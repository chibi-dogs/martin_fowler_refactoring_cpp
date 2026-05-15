find_package(nlohmann_json REQUIRED)
add_library(json_parser STATIC)

target_include_directories(json_parser
        PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)

target_sources(json_parser
    PUBLIC
        json_file_parser.h
        play.h
        invoice.h
    PRIVATE
        json_file_parser.cpp
)

target_link_libraries(json_parser PUBLIC nlohmann_json::nlohmann_json)