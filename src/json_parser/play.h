#ifndef MARTIN_FOWLER_REFACTORING_PLAY_H
#define MARTIN_FOWLER_REFACTORING_PLAY_H
#include <string>
#include <nlohmann/json.hpp>

namespace json_parser::play
{
    enum class Type
    {
        Tragedy,
        Comedy,
        Unknown
    };

    NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
    {Type::Unknown,   nullptr},
    {Type::Tragedy,     "tragedy"},
    {Type::Comedy, "comedy"},
})
    struct Play
    {
        std::string name{};
        Type type{};
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Play, name, type);

    inline std::unordered_map<std::string, Play> parse_plays(const nlohmann::json& j)
    {
        return j.get<std::unordered_map<std::string, Play>>();
    }

}
#endif //MARTIN_FOWLER_REFACTORING_PLAY_H