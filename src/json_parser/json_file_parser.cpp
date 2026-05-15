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
        if (std::filesystem::is_directory(file_path) || !(std::filesystem::is_regular_file(file_path)))
        {
            return std::unexpected<std::string>("Provided path must not be a directory.");
        }
        if (std::filesystem::path(file_path).extension() != ".json")
        {
            return std::unexpected<std::string>("File is not a valid json file.");
        }
        std::ifstream f(file_path);
        return nlohmann::json::parse(f);
    }

}
