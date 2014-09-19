/*    
 * Copyright (c) 2014, K. Kumar (me@kartikkumar.com)
 * All rights reserved.
 */

#define REAL double

#include <catch.hpp>

#include <SML/basicFunctions.hpp>

namespace sml
{
namespace unit_tests
{

TEST_CASE( "Test modulo function", "[modulo]" )
{
    SECTION( "Test 1.0 mod 1.0" )
    {
        REAL dividend = 1.0;
        REAL divisor = 1.0;
        REAL remainder = 0.0;

        REQUIRE( computeModulo( dividend, divisor ) == remainder );
    }

    SECTION( "Test 3.0 mod 2.5" )
    {
        REAL dividend = 3.0;
        REAL divisor = 2.5;
        REAL remainder = 0.5;

        REQUIRE( computeModulo( dividend, divisor ) == remainder );
    }    
}

} // namespace unit_tests
} // namespace sml
