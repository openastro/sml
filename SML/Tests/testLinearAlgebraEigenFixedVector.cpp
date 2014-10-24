/*    
 * Copyright (c) 2014, K. Kumar (me@kartikkumar.com)
 * All rights reserved.
 */

#include <Eigen/Core>

#include <catch.hpp>

#include <SML/linearAlgebra.hpp>

namespace sml
{
namespace tests
{

typedef double Real;
typedef Eigen::Matrix< Real, 2, 1 > Vector2;
typedef Eigen::Matrix< Real, 3, 1 > Vector3;
typedef Eigen::Matrix< Real, 4, 1 > Vector4;

TEST_CASE( "Cross-product", "[cross]" ) 
{
    SECTION( "cross-product of non-3-vectors" )
    {
        Vector2 vector1;
        Vector2 vector2;

        REQUIRE_THROWS( cross( vector1, vector2 ) );
    }

    SECTION( "cross-product of unit vectors" )
    {
        Vector3 unitX;
        Vector3 unitY;
        Vector3 unitZ;

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
        Vector3 vector1;
        Vector3 vector2;
        Vector3 result;

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
    SECTION( "dot-product of vectors of zeros" )
    {
        SECTION( "2-vector" )
        {
            Vector2 vector;        

            vector[ 0 ] = 0.0;
            vector[ 1 ] = 0.0;

            REQUIRE( dot< Real >( vector, vector ) == 0.0 );            
        }

        SECTION( "3-vector" )
        {
            Vector3 vector;        

            vector[ 0 ] = 0.0;
            vector[ 1 ] = 0.0;
            vector[ 2 ] = 0.0;

            REQUIRE( dot< Real >( vector, vector ) == 0.0 );            
        }
                        
        SECTION( "4-vector" )
        {
            Vector4 vector;        

            vector[ 0 ] = 0.0;
            vector[ 1 ] = 0.0;
            vector[ 2 ] = 0.0;
            vector[ 3 ] = 0.0;

            REQUIRE( dot< Real >( vector, vector ) == 0.0 );            
        }
    }

    SECTION( "dot-product of arbitrary vectors" )
    {
        SECTION( "2-vector" )
        {
            Vector2 vector1;        
            Vector2 vector2;        

            vector1[ 0 ] = 1.234; 
            vector1[ 1 ] = -2.674;         

            vector2[ 0 ] = -4.119;
            vector2[ 1 ] = -3.003;  

            Real result = 2.9471760000000007;        

            REQUIRE( dot< Real >( vector1, vector2 ) == result );           
        }

        SECTION( "3-vector" )
        {
            Vector3 vector1;        
            Vector3 vector2;        

            vector1[ 0 ] = 1.234; 
            vector1[ 1 ] = -2.674;
            vector1[ 2 ] = 10.812;  

            vector2[ 0 ] = -4.119;
            vector2[ 1 ] = -3.003;
            vector2[ 2 ] = -0.048;  

            Real result = 2.4282000000000008;        

            REQUIRE( dot< Real >( vector1, vector2 ) == result );           
        }
                        
        SECTION( "4-vector" )
        {
            Vector4 vector1;        
            Vector4 vector2;        

            vector1[ 0 ] = 1.234; 
            vector1[ 1 ] = -2.674;
            vector1[ 2 ] = 10.812;  
            vector1[ 3 ] = -12.123;         

            vector2[ 0 ] = -4.119;
            vector2[ 1 ] = -3.003;
            vector2[ 2 ] = -0.048;  
            vector2[ 3 ] = 17.367;  

            Real result = -208.111941;        

            REQUIRE( dot< Real >( vector1, vector2 ) == result );           
        }

    }    
}

TEST_CASE( "Squared-norm", "[norm]" )
{
    SECTION( "squared-norm of vector of zeros" )
    {
        SECTION( "2-vector" )
        {
            Vector2 vector;        

            vector[ 0 ] = 0.0;
            vector[ 1 ] = 0.0;
            
            REQUIRE( squaredNorm< Real >( vector ) == 0.0 );            
        }

        SECTION( "3-vector" )
        {
            Vector3 vector;        

            vector[ 0 ] = 0.0;
            vector[ 1 ] = 0.0;
            vector[ 2 ] = 0.0;        

            REQUIRE( squaredNorm< Real >( vector ) == 0.0 );            
        }

        SECTION( "4-vector" )
        {
            Vector4 vector;        

            vector[ 0 ] = 0.0;
            vector[ 1 ] = 0.0;
            vector[ 2 ] = 0.0;        
            vector[ 3 ] = 0.0;

            REQUIRE( squaredNorm< Real >( vector ) == 0.0 );            
        }        
    }

    SECTION( "squared-norm of arbitrary vector" )
    {
        SECTION( "2-vector" )
        {
            Vector2 vector;        

            vector[ 0 ] = 1.234; 
            vector[ 1 ] = -2.674;  

            Real result = 8.673032;            

            REQUIRE( squaredNorm< Real >( vector ) == result );           
        }

        SECTION( "3-vector" )
        {
            Vector3 vector;        

            vector[ 0 ] = 1.234; 
            vector[ 1 ] = -2.674;
            vector[ 2 ] = 10.812;

            Real result = 125.572375999999991;   

            REQUIRE( squaredNorm< Real >( vector ) == result );           
        }

        SECTION( "4-vector" )
        {
            Vector4 vector;        

            vector[ 0 ] = 1.234; 
            vector[ 1 ] = -2.674;
            vector[ 2 ] = 10.812;  
            vector[ 3 ] = -12.123;  

            Real result = 272.53950499999996;            

            REQUIRE( squaredNorm< Real >( vector ) == result );            
        }        
    }    
}

TEST_CASE( "Norm", "[norm]" )
{
    SECTION( "norm of vector of zeros" )
    {
        SECTION( "2-vector" )
        {
            Vector2 vector;        

            vector[ 0 ] = 0.0;
            vector[ 1 ] = 0.0;
            
            REQUIRE( norm< Real >( vector ) == 0.0 );            
        }

        SECTION( "3-vector" )
        {
            Vector3 vector;        

            vector[ 0 ] = 0.0;
            vector[ 1 ] = 0.0;
            vector[ 2 ] = 0.0;        

            REQUIRE( norm< Real >( vector ) == 0.0 );            
        }

        SECTION( "4-vector" )
        {
            Vector4 vector;        

            vector[ 0 ] = 0.0;
            vector[ 1 ] = 0.0;
            vector[ 2 ] = 0.0;        
            vector[ 3 ] = 0.0;

            REQUIRE( norm< Real >( vector ) == 0.0 );            
        }           
    }

    SECTION( "norm of arbitrary vector" )
    {
        SECTION( "2-vector" )
        {
            Vector2 vector;        

            vector[ 0 ] = 1.234; 
            vector[ 1 ] = -2.674;  

            Real result = 2.9450011884547687;            

            REQUIRE( norm< Real >( vector ) == result );           
        }

        SECTION( "3-vector" )
        {
            Vector3 vector;        

            vector[ 0 ] = 1.234; 
            vector[ 1 ] = -2.674;
            vector[ 2 ] = 10.812;

            Real result = 11.205908084577528;            

            REQUIRE( norm< Real >( vector ) == result );           
        }

        SECTION( "4-vector" )
        {
            Vector4 vector;        

            vector[ 0 ] = 1.234; 
            vector[ 1 ] = -2.674;
            vector[ 2 ] = 10.812;  
            vector[ 3 ] = -12.123;  

            Real result = 16.508770547802765;            

            REQUIRE( norm< Real >( vector ) == result );            
        }      
    }    
}

TEST_CASE( "Normalize vector", "[norm]" )
{
    SECTION( "Normalize arbitrary vector" )
    {
        SECTION( "2-vector" )
        {
            Vector2 vector;        

            vector[ 0 ] = 1.234; 
            vector[ 1 ] = -2.674;

            Vector2 result;
            result[ 0 ] = 0.41901511104227274;
            result[ 1 ] = -0.9079792600705325;          

            REQUIRE( normalize< Real >( vector ) == result );  
        }

        SECTION( "3-vector" )
        {
            Vector3 vector;        

            vector[ 0 ] = 1.234; 
            vector[ 1 ] = -2.674;
            vector[ 2 ] = 10.812;  

            Vector3 result;
            result[ 0 ] = 0.11012048204271192;
            result[ 1 ] = -0.23862412397261884;
            result[ 2 ] = 0.9648481781570513;

            REQUIRE( normalize< Real >( vector ) == result ); 
        }

        SECTION( "4-vector" )
        {
            Vector4 vector;        

            vector[ 0 ] = 1.234; 
            vector[ 1 ] = -2.674;
            vector[ 2 ] = 10.812;  
            vector[ 3 ] = -12.123;  

            Vector4 result;
            result[ 0 ] = 0.07474814653379741;
            result[ 1 ] = -0.1619745087774508;
            result[ 2 ] = 0.6549246031794307;
            result[ 3 ] = -0.7343369371387568;            

            REQUIRE( normalize< Real >( vector ) == result );           
        }
    }
}

TEST_CASE( "Return unit-vectors", "[unit-vector]" )
{
    SECTION( "Return unit-vector in x-direction" )
    {
        Vector3 xUnitVector;        

        xUnitVector[ 0 ] = 1.0; 
        xUnitVector[ 1 ] = 0.0;
        xUnitVector[ 2 ] = 0.0;           

        REQUIRE( getXUnitVector< Vector3 >( ) == xUnitVector ); 
    }

    SECTION( "Return unit-vector in y-direction" )
    {
        Vector3 yUnitVector;        

        yUnitVector[ 0 ] = 0.0; 
        yUnitVector[ 1 ] = 1.0;
        yUnitVector[ 2 ] = 0.0;           

        REQUIRE( getYUnitVector< Vector3 >( ) == yUnitVector ); 
    }
            
    SECTION( "Return unit-vector in z-direction" )
    {
        Vector3 zUnitVector;        

        zUnitVector[ 0 ] = 0.0; 
        zUnitVector[ 1 ] = 0.0;
        zUnitVector[ 2 ] = 1.0;           

        REQUIRE( getZUnitVector< Vector3 >( ) == zUnitVector ); 
    }
}

TEST_CASE( "Perform element-wise operations", "[element-wise]" )
{
    SECTION( "Multiply arbitrary vector element-wise" )
    {
        SECTION( "2-vector" )
        {
            Vector2 vector;  
            vector[ 0 ] = 12.3; 
            vector[ 1 ] = -15.4;

            Vector2 result; 

            Real multiplier = 0.0;

            SECTION( "Multiply vector element-wise by 1 to give same vector" )
            {
                multiplier = 1.0;  

                result = vector;      

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }

            SECTION( "Multiply vector element-wise by 0 to give 0-vector" )
            {
                multiplier = 0.0;  

                result[ 0 ] = 0.0; 
                result[ 1 ] = 0.0;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }            

            SECTION( "Multiply by positive multiplier with magnitude greater than unity" )
            {
                multiplier = 6.35;        

                result[ 0 ] = 78.105; 
                result[ 1 ] = -97.78999999999999;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            } 

            SECTION( "Multiply by negative multiplier with magnitude greater than unity" )
            {
                multiplier = -4.65;        

                result[ 0 ] = -57.19500000000001; 
                result[ 1 ] = 71.61000000000001;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }

            SECTION( "Multiply by positive multiplier with magnitude less than unity" )
            {
                multiplier = 0.146;        

                result[ 0 ] = 1.7958;  
                result[ 1 ] = -2.2483999999999997;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }

            SECTION( "Multiply by negative multiplier with magnitude less than unity" )
            {
                multiplier = -0.0488;        

                result[ 0 ] = -0.6002400000000001; 
                result[ 1 ] = 0.7515200000000001;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }
        }

        SECTION( "3-vector" )
        {
            Vector3 vector;  
            vector[ 0 ] = 12.3; 
            vector[ 1 ] = -15.4;
            vector[ 2 ] = 0.17;

            Vector3 result; 

            Real multiplier = 0.0;

            SECTION( "Multiply vector element-wise by 1 to give same vector" )
            {
                multiplier = 1.0;  

                result = vector;      

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }

            SECTION( "Multiply vector element-wise by 0 to give 0-vector" )
            {
                multiplier = 0.0;  

                result[ 0 ] = 0.0; 
                result[ 1 ] = 0.0;
                result[ 2 ] = 0.0;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }            

            SECTION( "Multiply by positive multiplier with magnitude greater than unity" )
            {
                multiplier = 6.35;        

                result[ 0 ] = 78.105; 
                result[ 1 ] = -97.78999999999999;
                result[ 2 ] = 1.0795000000000001;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            } 

            SECTION( "Multiply by negative multiplier with magnitude greater than unity" )
            {
                multiplier = -4.65;        

                result[ 0 ] = -57.19500000000001; 
                result[ 1 ] = 71.61000000000001;
                result[ 2 ] = -0.7905000000000001;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }

            SECTION( "Multiply by positive multiplier with magnitude less than unity" )
            {
                multiplier = 0.146;        

                result[ 0 ] = 1.7958;  
                result[ 1 ] = -2.2483999999999997;
                result[ 2 ] = 0.024820000000000002;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }

            SECTION( "Multiply by negative multiplier with magnitude less than unity" )
            {
                multiplier = -0.0488;        

                result[ 0 ] = -0.6002400000000001; 
                result[ 1 ] = 0.7515200000000001;
                result[ 2 ] = -0.008296000000000001;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }          
        }

        SECTION( "4-vector" )
        {
            Vector4 vector;  
            vector[ 0 ] = 12.3; 
            vector[ 1 ] = -15.4;
            vector[ 2 ] = 0.17;
            vector[ 3 ] = -0.036;

            Vector4 result; 

            Real multiplier = 0.0;

            SECTION( "Multiply vector element-wise by 1 to give same vector" )
            {
                multiplier = 1.0;  

                result = vector;      

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }

            SECTION( "Multiply vector element-wise by 0 to give 0-vector" )
            {
                multiplier = 0.0;  

                result[ 0 ] = 0.0; 
                result[ 1 ] = 0.0;
                result[ 2 ] = 0.0;
                result[ 3 ] = 0.0;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }            

            SECTION( "Multiply by positive multiplier with magnitude greater than unity" )
            {
                multiplier = 6.35;        

                result[ 0 ] = 78.105; 
                result[ 1 ] = -97.78999999999999;
                result[ 2 ] = 1.0795000000000001;
                result[ 3 ] = -0.22859999999999997;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            } 

            SECTION( "Multiply by negative multiplier with magnitude greater than unity" )
            {
                multiplier = -4.65;        

                result[ 0 ] = -57.19500000000001; 
                result[ 1 ] = 71.61000000000001;
                result[ 2 ] = -0.7905000000000001;
                result[ 3 ] = 0.1674;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }

            SECTION( "Multiply by positive multiplier with magnitude less than unity" )
            {
                multiplier = 0.146;        

                result[ 0 ] = 1.7958;  
                result[ 1 ] = -2.2483999999999997;
                result[ 2 ] = 0.024820000000000002;
                result[ 3 ] = -0.005255999999999999;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }

            SECTION( "Multiply by negative multiplier with magnitude less than unity" )
            {
                multiplier = -0.0488;        

                result[ 0 ] = -0.6002400000000001; 
                result[ 1 ] = 0.7515200000000001;
                result[ 2 ] = -0.008296000000000001;
                result[ 3 ] = 0.0017568;

                REQUIRE( multiply( vector, multiplier ) == result ); 
            }         
        }          
    }

    SECTION( "Add to arbitrary vector element-wise" )
    {
        SECTION( "2-vector" )
        {
            Vector2 vector;  
            vector[ 0 ] = 12.3; 
            vector[ 1 ] = -15.4;

            Vector2 result; 

            Real adder = 0.0;   

            SECTION( "Add 0 to vector element-wise to give same vector" )
            {
                adder = 0.0; 

                REQUIRE( add( vector, adder ) == vector ); 
            }

            SECTION( "Add positive adder" )
            {
                adder = 6.35;        

                result[ 0 ] = 18.65; 
                result[ 1 ] = -9.05;

                REQUIRE( add( vector, adder ) == result ); 
            }   

            SECTION( "Add negative adder" )
            {
                adder = -3.64;        

                result[ 0 ] = 8.66; 
                result[ 1 ] = -19.04;

                REQUIRE( add( vector, adder ) == result ); 
            }
        }

        SECTION( "3-vector" )
        {

            Vector3 vector;  
            vector[ 0 ] = 12.3; 
            vector[ 1 ] = -15.4;
            vector[ 2 ] = 0.17;  

            Vector3 result; 

            Real adder = 0.0;   

        SECTION( "Add 0 to vector element-wise to give same vector" )
        {
            adder = 0.0; 

            REQUIRE( add( vector, adder ) == vector ); 
        }

            SECTION( "Add positive adder" )
            {
                adder = 6.35;        

                result[ 0 ] = 18.65; 
                result[ 1 ] = -9.05;
                result[ 2 ] = 6.52;  

                REQUIRE( add( vector, adder ) == result ); 
            }   

            SECTION( "Add negative adder" )
            {
                adder = -3.64;        

                result[ 0 ] = 8.66; 
                result[ 1 ] = -19.04;
                result[ 2 ] = -3.47;  

                REQUIRE( add( vector, adder ) == result ); 
            }
        }

        SECTION( "4-vector" )
        {
            Vector4 vector;  
            vector[ 0 ] = 12.3; 
            vector[ 1 ] = -15.4;
            vector[ 2 ] = 0.17;
            vector[ 3 ] = -0.35;

            Vector4 result; 

            Real adder = 0.0;   

            SECTION( "Add 0 to vector element-wise to give same vector" )
            {
                adder = 0.0; 

                REQUIRE( add( vector, adder ) == vector ); 
            }

            SECTION( "Add positive adder" )
            {
                adder = 6.35;        

                result[ 0 ] = 18.65; 
                result[ 1 ] = -9.05;
                result[ 2 ] = 6.52;
                result[ 3 ] = 6.0;

                REQUIRE( add( vector, adder ) == result ); 
            }   

            SECTION( "Add negative adder" )
            {
                adder = -3.64;        

                result[ 0 ] = 8.66; 
                result[ 1 ] = -19.04;
                result[ 2 ] = -3.47;  
                result[ 3 ] = -3.99;

                REQUIRE( add( vector, adder ) == result ); 
            }            
        }

    }  

    SECTION( "Add two vectors of equal length element-wise" )
    {
        SECTION( "2-vector" )
        {
            SECTION( "Add two 0-vectors" )
            {
                Vector2 vector;

                vector[ 0 ] = 0.0;
                vector[ 1 ] = 0.0;

                REQUIRE( add( vector, vector ) == vector );
            }

            SECTION( "Add two arbitrary equal-vectors" )
            {
                Vector2 vector;
                Vector2 result;

                vector[ 0 ] = 2.6;
                vector[ 1 ] = -9.4;

                result[ 0 ] = 5.2;
                result[ 1 ] = -18.8;

                REQUIRE( add( vector, vector ) == result );
            }        

        SECTION( "Add two arbitrary unequal-vectors" )
        {
            Vector2 vector1;
            Vector2 vector2;
            Vector2 result;

            vector1[ 0 ] = 2.6;
            vector1[ 1 ] = -9.4;

            vector2[ 0 ] = -0.54;
            vector2[ 1 ] = 12.3;

            result[ 0 ] = 2.06;
            result[ 1 ] = 2.9000000000000004;

            REQUIRE( add( vector1, vector2 ) == result );
        }   
    }

        SECTION( "3-vector" )
        {
            SECTION( "Add two 0-vectors" )
            {
                Vector3 vector;

                vector[ 0 ] = 0.0;
                vector[ 1 ] = 0.0;
                vector[ 2 ] = 0.0;

                REQUIRE( add( vector, vector ) == vector );
            }

            SECTION( "Add two arbitrary equal-vectors" )
            {
                Vector3 vector;
                Vector3 result;

                vector[ 0 ] = 2.6;
                vector[ 1 ] = -9.4;
                vector[ 2 ] = -0.64;

                result[ 0 ] = 5.2;
                result[ 1 ] = -18.8;
                result[ 2 ] = -1.28;

                REQUIRE( add( vector, vector ) == result );
            }        

            SECTION( "Add two arbitrary unequal-vectors" )
            {
                Vector3 vector1;
                Vector3 vector2;
                Vector3 result;

                vector1[ 0 ] = 2.6;
                vector1[ 1 ] = -9.4;
                vector1[ 2 ] = -0.64;

                vector2[ 0 ] = -0.54;
                vector2[ 1 ] = 12.3;
                vector2[ 2 ] = 1.36;

                result[ 0 ] = 2.06;
                result[ 1 ] = 2.9000000000000004;
                result[ 2 ] = 0.7200000000000001;

                REQUIRE( add( vector1, vector2 ) == result );
            }               
        }

        SECTION( "4-vector" )
        {
            SECTION( "Add two 0-vectors" )
            {
                Vector4 vector;

                vector[ 0 ] = 0.0;
                vector[ 1 ] = 0.0;
                vector[ 2 ] = 0.0;
                vector[ 3 ] = 0.0;

                REQUIRE( add( vector, vector ) == vector );
            }

            SECTION( "Add two arbitrary equal-vectors" )
            {
                Vector4 vector;
                Vector4 result;

                vector[ 0 ] = 2.6;
                vector[ 1 ] = -9.4;
                vector[ 2 ] = -0.64;
                vector[ 3 ] = 0.39;                

                result[ 0 ] = 5.2;
                result[ 1 ] = -18.8;
                result[ 2 ] = -1.28;
                result[ 3 ] = 0.78;

                REQUIRE( add( vector, vector ) == result );
            }        

            SECTION( "Add two arbitrary unequal-vectors" )
            {
                Vector4 vector1;
                Vector4 vector2;
                Vector4 result;

                vector1[ 0 ] = 2.6;
                vector1[ 1 ] = -9.4;
                vector1[ 2 ] = -0.64;
                vector1[ 3 ] = 0.39; 

                vector2[ 0 ] = -0.54;
                vector2[ 1 ] = 12.3;
                vector2[ 2 ] = 1.66;
                vector2[ 3 ] = -9.7;

                result[ 0 ] = 2.06;
                result[ 1 ] = 2.9000000000000004;
                result[ 2 ] = 1.02;
                result[ 3 ] = -9.309999999999999;

                REQUIRE( add( vector1, vector2 ) == result );
            }   
        }             
    }  
}

} // namespace tests
} // namespace sml
