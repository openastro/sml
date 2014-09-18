/*    
 * Copyright (c) 2014, K. Kumar (me@kartikkumar.com)
 * All rights reserved.
 */

#define REAL double

#include <vector>
#include <catch.hpp>

#include <SML/linearAlgebra.hpp>

namespace sml
{
namespace unit_tests
{

//! Define typedef for vector of reals.
typedef std::vector< REAL > Vector;

TEST_CASE( "Cross product", "[cross]" ) 
{
    SECTION( "cross product of non-3-vectors")
    {
        Vector vector1( 4 );
        Vector vector2( 5 );

        REQUIRE_THROWS( cross( vector1, vector2 ) );
    }

    SECTION( "cross product of unit vectors" )
    {
        Vector unitX( 3 );
        Vector unitY( 3 );
        Vector unitZ( 3 );

        unitX[ 0 ] = 1.0;
        unitX[ 1 ] = 0.0;
        unitX[ 2 ] = 0.0;

        unitY[ 0 ] = 0.0;
        unitY[ 1 ] = 1.0;
        unitY[ 2 ] = 0.0;

        unitZ[ 0 ] = 0.0;
        unitZ[ 1 ] = 0.0;
        unitZ[ 2 ] = 1.0;        

        REQUIRE( cross( unitX, unitY ) == unitZ );
        REQUIRE( cross( unitY, unitZ ) == unitX );
        REQUIRE( cross( unitZ, unitX ) == unitY );        
    }

    SECTION( "cross product of arbitrary vectors" )
    {
        Vector vector1( 3 );
        Vector vector2( 3 );
        Vector result( 3 );

        vector1[ 0 ] = 1.342;
        vector1[ 1 ] = -3.576;
        vector1[ 2 ] = 12.113;

        vector2[ 0 ] = -0.024;
        vector2[ 1 ] = 10.125;
        vector2[ 2 ] = -9.645;

        result[ 0 ] = -88.153605;
        result[ 1 ] = 12.652878000000001;
        result[ 2 ] = 13.501926000000001; 

        REQUIRE( cross( vector1, vector2 ) == result );        
    }
}

} // namespace unit_tests
} // namespace sml
