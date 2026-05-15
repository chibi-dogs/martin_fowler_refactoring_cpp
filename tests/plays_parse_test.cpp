#include <gtest/gtest.h>
#include <json_parser/play.h>

#include <json_parser/invoice.h>

using namespace json_parser::play;
using namespace json_parser::invoice;

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
    EXPECT_EQ(plays.at("hamlet").name,  "Hamlet");
    EXPECT_EQ(plays.at("as-like").type, Type::Comedy);
    EXPECT_EQ(plays.at("as-like").name,  "As You Like It");
    EXPECT_EQ(plays.at("othello").type, Type::Tragedy);
    EXPECT_EQ(plays.at("othello").name, "Othello");
}

TEST(InvoiceParseTest, ParsesFields) {
    auto j = R"({
            "customer": "BigCo",
    "performances": [
      {
        "playID": "hamlet",
        "audience": 55
      },
      {
        "playID": "as-like",
        "audience": 35
      },
      {
        "playID": "othello",
        "audience": 40
      }
    ]
    })"_json;

    auto p = j.get<Invoice>();
    EXPECT_EQ(p.customer, "BigCo");
    //EXPECT_EQ(p.customer, "BigCo");
}