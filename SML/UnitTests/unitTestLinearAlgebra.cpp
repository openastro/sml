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

TEST_CASE( "Cross-product", "[cross]" ) 
{
    SECTION( "cross-product of non-3-vectors")
    {
        Vector vector1( 4 );
        Vector vector2( 5 );

        REQUIRE_THROWS( cross( vector1, vector2 ) );
    }

    SECTION( "cross-product of unit vectors" )
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

    SECTION( "cross-product of arbitrary vectors" )
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

TEST_CASE( "Dot-product", "[dot]" ) 
{
    SECTION( "dot-product of non-equal-length vectors")
    {
        Vector vector1( 4 );
        Vector vector2( 5 );

        REQUIRE_THROWS( dot< REAL >( vector1, vector2 ) );
    }

    SECTION( "dot-product of vectors of zeros" )
    {
        Vector vector( 3 );        

        vector[ 0 ] = 0.0;
        vector[ 1 ] = 0.0;
        vector[ 2 ] = 0.0;        

        REQUIRE( dot< REAL >( vector, vector ) == 0.0 );
    }

    SECTION( "dot-product of arbitrary vectors" )
    {
        Vector vector1( 4 );        
        Vector vector2( 4 );        

        vector1[ 0 ] = 1.234; 
        vector1[ 1 ] = -2.674;
        vector1[ 2 ] = 10.812;  
        vector1[ 3 ] = -12.123;         

        vector2[ 0 ] = -4.119;
        vector2[ 1 ] = -3.003;
        vector2[ 2 ] = -0.048;  
        vector2[ 3 ] = 17.367;  

        REAL result = -208.111941;        

        REQUIRE( dot< REAL >( vector1, vector2 ) == result );
    }    
}

TEST_CASE( "Squared-norm", "[norm]" )
{
    SECTION( "squared-norm of vector of zeros" )
    {
        Vector vector( 3 );        

        vector[ 0 ] = 0.0;
        vector[ 1 ] = 0.0;
        vector[ 2 ] = 0.0;        

        REQUIRE( squaredNorm< REAL >( vector ) == 0.0 );        
    }

    SECTION( "squared-norm of arbitrary vector" )
    {
        Vector vector( 4 );        

        vector[ 0 ] = 1.234; 
        vector[ 1 ] = -2.674;
        vector[ 2 ] = 10.812;  
        vector[ 3 ] = -12.123;  

        REAL result = 272.53950499999996;            

        REQUIRE( squaredNorm< REAL >( vector ) == result );        
    }    
}

TEST_CASE( "Norm", "[norm]" )
{
    SECTION( "norm of vector of zeros" )
    {
        Vector vector( 3 );        

        vector[ 0 ] = 0.0;
        vector[ 1 ] = 0.0;
        vector[ 2 ] = 0.0;        

        REQUIRE( norm< REAL >( vector ) == 0.0 );        
    }

    SECTION( "norm of arbitrary vector" )
    {
        Vector vector( 4 );        

        vector[ 0 ] = 1.234; 
        vector[ 1 ] = -2.674;
        vector[ 2 ] = 10.812;  
        vector[ 3 ] = -12.123;  

        REAL result = 16.508770547802765;            

        REQUIRE( norm< REAL >( vector ) == result );        
    }    
}

TEST_CASE( "Normalize vector", "[norm]" )
{
    SECTION( "Normalize arbitrary vector" )
    {
        Vector vector( 4 );        

        vector[ 0 ] = 1.234; 
        vector[ 1 ] = -2.674;
        vector[ 2 ] = 10.812;  
        vector[ 3 ] = -12.123;  

        Vector result( 4 );
        result[ 0 ] = 0.07474814653379741;
        result[ 1 ] = -0.1619745087774508;
        result[ 2 ] = 0.6549246031794307;
        result[ 3 ] = -0.7343369371387568;            

        REQUIRE( normalize< REAL >( vector ) == result ); 
    }
}

} // namespace unit_tests
} // namespace sml
