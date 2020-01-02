#include <cdb/cdb.h>

#include <gtest/gtest.h>

TEST(cdb, ExtractVars)
{
    const std::string vars("abc=123;t=;f=");
    std::map<std::string, std::string> varvals = cdb::extract_vars(vars);
    ASSERT_EQ(varvals.size(), 3);
    ASSERT_STREQ(varvals["abc"].c_str(), "123");
    ASSERT_STREQ(varvals["t"].c_str(), "");
    ASSERT_STREQ(varvals["f"].c_str(), "");
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
