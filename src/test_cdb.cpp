#include <cdb/cdb.h>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>


TEST_CASE("cdb", "ExtractVars")
{
    const std::string vars("abc=123;t=;f=a");
    std::map<std::string, std::string> varvals = cdb::extract_vars(vars);
    REQUIRE(varvals.size() == 3);
    REQUIRE(varvals["abc"] == "123");
    REQUIRE(varvals["t"] == "");
    REQUIRE(varvals["f"] == "a");
}

