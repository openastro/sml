/*    
 * Copyright (c) 2014, K. Kumar (me@kartikkumar.com)
 * All rights reserved.
 */

#define REAL double

#include <limits>

#include <catch.hpp>

#include <SML/basicFunctions.hpp>
#include <SML/constants.hpp> 

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

TEST_CASE( "Test radian-to-degree conversion function", "[radians-to-degrees]")
{
    SECTION( "PI/2 radians to degrees" )
    {
        REQUIRE( convertRadiansToDegrees( SML_PI / 2.0 ) == 90.0 );
    }

    SECTION( "0 radians to degrees" )
    {
        REQUIRE( convertRadiansToDegrees( 0.0 ) == 0.0 );
    }

    SECTION( "PI radians to degrees" )
    {
        REQUIRE( convertRadiansToDegrees( SML_PI ) == 180.0 );
    }    

    SECTION( "Arbitrary radians to degrees" )
    {
        REQUIRE( convertRadiansToDegrees( 2.573 ) 
                 == Approx( 147.4220406871608 ).epsilon( 
                        std::numeric_limits< REAL >::epsilon( ) ) );
    }        
}

} // namespace unit_tests
} // namespace sml
