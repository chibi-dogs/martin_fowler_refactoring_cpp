#ifndef MARTIN_FOWLER_REFACTORING_INVOICE_H
#define MARTIN_FOWLER_REFACTORING_INVOICE_H
#include <string>
#include <nlohmann/json.hpp>

namespace json_parser::invoice
{
    struct Performance
    {
        std::string play_id;
        std::size_t audience;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Performance, play_id, audience);
    struct Invoice
    {
        std::string customer;
        std::vector<Performance> performances;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Invoice, customer, performances);

    inline std::vector<Invoice> parse_invoices(const nlohmann::json& j)
    {
        return j.get<std::vector<Invoice>>();
    }
}
#endif //MARTIN_FOWLER_REFACTORING_INVOICE_H