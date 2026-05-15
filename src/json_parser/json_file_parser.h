#ifndef MARTIN_FOWLER_REFACTORING_JSON_FILE_PARSER_H
#define MARTIN_FOWLER_REFACTORING_JSON_FILE_PARSER_H

#include <expected>
#include <filesystem>
#include <nlohmann/json.hpp>

namespace json_parser
{
std::expected<nlohmann::json, std::string> parse_file_as_json(const std::filesystem::path& file_path);
}
#endif //MARTIN_FOWLER_REFACTORING_JSON_FILE_PARSER_H