// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

TEST(test1, prefix) {
    generator gen;
    std::istringstream str("audaces fortuna juvat");
    gen.train(str, 2);
    std::map<prefix, std::vector<std::string> > map = gen.get_map();
    prefix exp = { "audaces", "fortuna" };
    EXPECT_EQ(exp, map.begin()->first);
}

TEST(test2, suffix) {
    generator gen;
    std::istringstream str("audaces fortuna juvat");
    gen.train(str, 2);
    std::map<prefix, std::vector<std::string> > map = gen.get_map();
    std::vector<std::string> > exp = { "juvat" };
    EXPECT_EQ(exp, map.begin()->second);
}

TEST(test3, single) {
    generator gen;
    std::istringstream str("amicus plato, sed magis amica veritas");
    gen.train(str, 1);
    std::string res = gen.generate_text(10);
    EXPECT_EQ("amicus plato, sed magis amica veritas", res);
}

TEST(test4, multiple) {
    generator gen;
    std::istringstream str("edimus, ut vivamus; non vivimus, ut edamus");
    gen.train(str, 1);
    prefix pr = { "ut" }
    std::map<prefix, std::vector<std::string> > map = gen.get_map();
    std::vector<std::string> > exp = { "vivamus", "edamus" };
    EXPECT_EQ(exp, map.at(pr));
}

TEST(test5, handwrittenTable) {
    generator gen;
    std::map<prefix, std::vector<std::string> > map = {
        { { "one" }, { "two" } },
        { { "two" }, { "three", "four" } },
        { { "three" }, { "five" } },
    }
    std::string res = gen.generate_text(10);
    EXPECT_EQ(true, (1 < res.size() && res.size() < 4));
}