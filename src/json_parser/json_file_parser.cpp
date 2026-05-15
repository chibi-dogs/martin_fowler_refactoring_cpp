#include "json_file_parser.h"
#include <fstream>

namespace json_parser
{
    std::expected<nlohmann::json, std::string> parse_file_as_json(const std::filesystem::path& file_path)
    {
        if (!std::filesystem::exists(file_path))
        {
            return std::unexpected<std::string>("File does not exist.");
        }
        std::ifstream f(file_path);
        return nlohmann::json::parse(f);
    }

}
