#include <iostream>
#include <sstream>
#include <string>
#include <json_parser/invoice.h>
#include <json_parser/play.h>
#include <json_parser/json_file_parser.h>


using namespace json_parser;

auto makeUSDFormatter() {
    return [](const double amount) -> std::string {
        std::ostringstream oss;
        oss.imbue(std::locale("en_US.UTF-8"));
        oss << std::showbase << std::put_money(amount * 100.0);
        return oss.str();
    };
}

std::expected<double, std::string> calculate_amount_for_play_type(const invoice::Performance& perf, const play::Type type)
{
    auto amount = 0;
    switch (type)
    {
        case play::Type::Tragedy:
            {
                amount += 40000;
                if (perf.audience > 30)
                {
                    amount += 1000 * (perf.audience - 30);
                }
                break;
            }
        case play::Type::Comedy:
            {
                {
                    amount += 30000;
                    if (perf.audience > 20)
                    {
                        amount += 10000 + 500 * (perf.audience-20);
                    }
                    amount += 300 * perf.audience;
                    break;
                }
            }
        case play::Type::Unknown:
            {
                return std::unexpected<std::string>("unknown play type! Currently only comedy and tragedy are supported.");
            }

    }
    return amount;
}

std::expected<std::string, std::string> statement (const invoice::Invoice& invoice, const std::unordered_map<std::string, play::Play>& play )
{
    auto format_currency = makeUSDFormatter();
    std::string result = std::format("Statement for {}\n", invoice.customer );
    double total_amount = 0;
    double volume_credits = 0;
    for (const auto& perf: invoice.performances)
    {
        const auto [name, type] = play.at(perf.play_id);
        if (const auto expected_amount = calculate_amount_for_play_type(perf, type))
        {
            volume_credits += std::max(static_cast<int>(perf.audience-30), 0);
            if (type == play::Type::Comedy )
            {
                volume_credits += std::floor(perf.audience / 5);
            }
            result.append(std::format(" {}: {} ({} seats)\n", name, format_currency(expected_amount.value()/100), perf.audience));
            total_amount += expected_amount.value();
        }
    }
    result.append(std::format("Amount owed is {}\n", format_currency(total_amount/100)));
    result.append(std::format("You earned {} credits\n", volume_credits));
    return result;

}

int main()
{
    std::vector<invoice::Invoice> invoices{};
    std::unordered_map<std::string, play::Play> plays{};

    if (const auto parse_result = parse_file_as_json("invoices.json"))
    {
        invoices = invoice::parse_invoices(parse_result.value());
    }
    if (const auto parse_result = parse_file_as_json("plays.json"))
    {
        plays = play::parse_plays(parse_result.value());
    }
    for (const auto& invoice : invoices)
    {
        if (const auto result = statement(invoice, plays))
        {
            std::cout << *result << std::endl;
        }

    }

}

