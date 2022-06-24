/*
 * Copyright (c) 2014-2022 Kartik Kumar (me@kartikkumar.com)
 * Distributed under the MIT License.
 * See accompanying file LICENSE.md or copy at http://opensource.org/licenses/MIT
 */

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <limits>

#include "sml/basicFunctions.hpp"

namespace sml
{
namespace tests
{

typedef double Real;

TEST_CASE( "Test modulo function", "[modulo]" )
{
    SECTION( "Test 1.0 mod 1.0" )
    {
        Real dividend = 1.0;
        Real divisor = 1.0;
        Real remainder = 0.0;

        REQUIRE( computeModulo( dividend, divisor ) == remainder );
    }

    SECTION( "Test 3.0 mod 2.5" )
    {
        Real dividend = 3.0;
        Real divisor = 2.5;
        Real remainder = 0.5;

        REQUIRE( computeModulo( dividend, divisor ) == remainder );
    }
}

TEST_CASE( "Test radian-to-degree conversion function", "[radians-to-degrees]")
{
    SECTION( "PI/2 radians to degrees" )
    {
        REQUIRE( convertRadiansToDegrees( 3.14159265358979323846 / 2.0 ) == 90.0 );
    }

    SECTION( "0 radians to degrees" )
    {
        REQUIRE( convertRadiansToDegrees( 0.0 ) == 0.0 );
    }

    SECTION( "PI radians to degrees" )
    {
        REQUIRE( convertRadiansToDegrees( 3.14159265358979323846 ) == 180.0 );
    }

    SECTION( "Arbitrary radians to degrees" )
    {
        REQUIRE( convertRadiansToDegrees( 2.573 )
                 == Catch::Approx( 147.4220406871608 ).epsilon(
                        std::numeric_limits< Real >::epsilon( ) ) );
    }
}

TEST_CASE( "Test degree-to-radians conversion function", "[degrees-to-radians]")
{
    SECTION( "90 degrees to radians" )
    {
        REQUIRE( convertDegreesToRadians( 90.0 ) == 3.14159265358979323846 / 2.0 );
    }

    SECTION( "0 degrees to radians" )
    {
        REQUIRE( convertDegreesToRadians( 0.0 ) == 0.0 );
    }

    SECTION( "180 degrees to radians" )
    {
        REQUIRE( convertDegreesToRadians( 180.0 ) == 3.14159265358979323846 );
    }

    SECTION( "Arbitrary degrees to radians" )
    {
        REQUIRE( convertDegreesToRadians( 147.422 )
                 == Catch::Approx( 2.572999289875080 ).epsilon(
                        std::numeric_limits< Real >::epsilon( ) ) );
    }
}

} // namespace tests
} // namespace sml
