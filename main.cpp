#include <iostream>
#include <string>
#include <json_parser/invoice.h>
#include <json_parser/play>
#include <json_parser/json_file_parser.h>

#include "json_parser/play.h"

using namespace json_parser;
std::string statement (const invoice::Invoice& invoice, const std::unordered_map<std::string, play::Play>& play )
{
    std::string result = std::format("Statement for {}\n", invoice.customer );
    double total_amount = 0;
    double volume_credit = 0;
    for (const auto& perf: invoice.performances)
    {
        const auto [name, type] = play.at(perf.play_id);
        auto amount = 0;
        switch (type)
        {
        case play::Type::Tragedy:
            {
                amount += 40000;
                break;
            }
        case play::Type::Comedy:  return "comedy";
        case play::Type::Unknown: return "unknown";
        }
    }
    // let totalAmount = 0;
    // let volumeCredits = 0;
    // let result = `Statement for ${invoice.customer}\n`;
    // const format = new Intl.NumberFormat("enUS",
    // { style: "currency", currency: "USD",
    // minimumFractionDigits: 2 }).format;
    // for (let perf of invoice.performances) {
    //     const play = plays[perf.playID];
    //     let thisAmount = 0;
    //     switch (play.type) {
    //     case "tragedy":
    //         thisAmount = 40000;
    //         if (perf.audience > 30) {
    //             thisAmount += 1000 * (perf.audience 30)
    //             ;
    //             }
    //         break;
    //         case "comedy":
    //         thisAmount = 30000;
    //         if (perf.audience > 20) {
    //             thisAmount += 10000 + 500 * (perf.audience 20)
    //             ;
    //             }
    //         thisAmount += 300 * perf.audience;
    //         break;
    //         default:
    //         throw new Error(`unknown type: ${play.type}`);
    //         }
    //     // add volume credits
    //     volumeCredits += Math.max(perf.audience 30,
    //     0);
    //     // add extra credit for every ten comedy attendees
    //     if ("comedy" === play.type) volumeCredits += Math.floor(perf.audience / 5);
    //     // print line for this order
    //     result += ` ${play.name}: ${format(thisAmount/100)} (${perf.audience} seats)\totalAmount += thisAmount;
    //     }
    // result += `Amount owed is ${format(totalAmount/100)}\n`;
    // result += `You earned ${volumeCredits} credits\n`;

    return result;

}

int main()
{
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++)
    {
        std::cout << "i = " << i << std::endl;
    }

    return 0;
}

