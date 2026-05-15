#include <gtest/gtest.h>
#include <json_parser/play.h>

using namespace json_parser::play;
TEST(PlayParseTest, ParsesFields) {
    auto j = R"({
        "name": "Hamlet", "type": "tragedy"
    })"_json;

    auto p = j.get<Play>();
    EXPECT_EQ(p.type, Type::Tragedy);
    EXPECT_EQ(p.name, "Hamlet");
}

TEST(PlayParseTest, UnknownCategoryFallsBack) {
    auto j = R"({
        "name": "Hamlet", "type": "romance"
    })"_json;

    auto p = j.get<Play>();
    EXPECT_EQ(p.type, Type::Unknown);
    EXPECT_EQ(p.name, "Hamlet");
}

TEST(PlayParseTest, ParsesMapWithCategories) {
    auto j = R"({
        "hamlet":  {"name": "Hamlet", "type": "tragedy"},
        "as-like": {"name": "As You Like It", "type": "comedy"},
        "othello": {"name": "Othello", "type": "tragedy"}
    })"_json;

    auto plays = parse_plays(j);

    EXPECT_EQ(plays.at("hamlet").type,  Type::Tragedy);
    EXPECT_EQ(plays.at("as-like").type, Type::Comedy);
    EXPECT_EQ(plays.at("othello").type, Type::Tragedy);
}