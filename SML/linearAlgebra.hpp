/*    
 * Copyright (c) 2014, K. Kumar (me@kartikkumar.com)
 * All rights reserved.
 */

#include <stdexcept>

namespace sml
{

//! Compute cross-product of two 3-vectors.
/*!
 * Computes the cross-product of two 3-vectors. Throws an exception if either of the vectors do not
 * have dimension 3. The cross-product \f$\bar{R} = \bar{X} \times \bar{Y}\f$ is computed as 
 * follows:
 * 
 * \f{eqnarray*}{
 *      R_{1} &=& X_{2} * Y_{3} - X_{3} * Y{2} \\ 
 *      R_{2} &=& X_{3} * Y_{1} - X_{1} * Y{3} \\ 
 *      R_{3} &=& X_{1} * Y_{2} - X_{2} * Y{1}
 * \f}
 *
 * @tparam Vector3 3-Vector type
 * @param  vector1 A vector
 * @param  vector2 A vector
 * @return Vector resulting from cross-product
 */
template< typename Vector3 >
Vector3 cross( const Vector3& vector1, const Vector3& vector2 )
{
    // Check if either vector is not a 3-vector. If so, throw an exception.
    if ( vector1.size( ) != 3 || vector2.size( ) != 3 )
    {
        throw std::runtime_error( "ERROR: Cross product can only be computed for 3-vectors!" );
    }

    // Declare the resulting 3-vector.
    Vector3 result( 3 );

    // Compute components of resulting 3-vector.
    result[ 0 ] = vector1[ 1 ] * vector2[ 2 ] - vector1[ 2 ] * vector2[ 1 ];
    result[ 1 ] = vector1[ 2 ] * vector2[ 0 ] - vector1[ 0 ] * vector2[ 2 ];
    result[ 2 ] = vector1[ 0 ] * vector2[ 1 ] - vector1[ 1 ] * vector2[ 0 ];

    // Return result vector.
    return result;
}

// template< typename Vector, typename Real >
// Real squaredNorm( const Vector& vector )
// {
//     // Declare norm;
//     Real squaredNorm = 0.0;

//     // Loop through vector to compute norm.
//     for ( unsigned int i = 0; i < vector.size( ); i++ )
//     {
//         squaredNorm += vector[ i ] * vector[ i ];
//     }

//     // Return computed norm.
//     return squaredNorm;
// }

// template< typename Vector, typename Real >
// Real norm( const Vector& vector )
// {
//     return std::sqrt( squaredNorm< Vector, Real >( vector ) );
// }

// template< typename Vector, typename Real >
// Vector normalize( const Vector& vector )
// {
//     // Declare normalized vector.
//     Vector normalizedVector( vector.size( ) );

//     // Compute the norm of the vector.
//     Real vectorNorm = norm< Vector, Real >( vector );

//     // Loop through vector and divide each component by the norm of the vector.
//     for ( unsigned int i = 0; i < vector.size( ); i++ )
//     {
//         normalizedVector[ i ] = vector[ i ] / vectorNorm;
//     }   

//     // Return normalized vector.
//     return normalizedVector;
// }

// template< typename Vector >
// Vector getZUnitVector( )
// {
//     // Declare vector of size 3.
//     Vector zUnitVector( 3 );

//     // Set components of unit-vector.
//     zUnitVector[ 0 ] = 0.0;
//     zUnitVector[ 1 ] = 0.0;
//     zUnitVector[ 2 ] = 1.0;

//     // Return unit vector in z-direction.
//     return zUnitVector;
// }

} // namespace sml