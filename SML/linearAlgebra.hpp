/*    
 * Copyright (c) 2014, K. Kumar (me@kartikkumar.com)
 * All rights reserved.
 */

#include <cmath>
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
 * @param  vector1 A 3-vector
 * @param  vector2 A 3-vector
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

    Vector3 result( 3 );

    // Compute components of resulting 3-vector.
    result[ 0 ] = vector1[ 1 ] * vector2[ 2 ] - vector1[ 2 ] * vector2[ 1 ];
    result[ 1 ] = vector1[ 2 ] * vector2[ 0 ] - vector1[ 0 ] * vector2[ 2 ];
    result[ 2 ] = vector1[ 0 ] * vector2[ 1 ] - vector1[ 1 ] * vector2[ 0 ];

    return result;
}

//! Compute dot-product of two equal-length vectors.
/*!
 * Computes the dot-product (inner-product) of two vectors of length N. Throws an exception if the
 * vectors are unequal in length. The dot-product \f$r = \bar{X} \cdot \bar{Y}\f$ is computed as 
 * follows:
 * 
 * \f[
 *      r = \sum_{i=1}^{N} X_{i} * Y_{i}
 * \f]
 *
 * @tparam Real Real type
 * @tparam Vector Vector type
 * @param  vector1 A vector of length N
 * @param  vector2 A vector of length N
 * @return Scalar resulting from dot-product
 */
template< typename Real, typename Vector >
Real dot( const Vector& vector1, const Vector& vector2 )
{
    // Check if vectors are of different length. If so, throw an exception.
    if ( vector1.size( ) != vector2.size( ) )
    {
        throw std::runtime_error( 
            "ERROR: Dot product can only be computed for vectors of equal length!" );
    }

    Real result = 0.0;

    // Loop through vector and compute dot product.
    for ( unsigned int i = 0; i < vector1.size( ); i++ )
    {
        result += vector1[ i ] * vector2[ i ];
    }

    return result;
}

//! Compute squared-norm of vector.
/*!
 * Computes the square of the Euclidean norm of a vector of length N. This is computed as the dot-
 * product of the vector with itself. The squared-norm \f$r\f$ of vector \f$X\f$ is computed as
 * follows:
 * 
 * \f[
 *      r = \sum_{i=1}^{N} X_{i}^{2}
 * \f]
 * 
 * @sa dot
 * @tparam Real Real type
 * @tparam Vector Vector type
 * @param  vector A vector of length N
 * @return Scalar squared-norm of vector
 */
template< typename Real, typename Vector >
Real squaredNorm( const Vector& vector )
{
    return dot< Real, Vector >( vector, vector );
}

//! Compute norm of vector.
/*!
 * Computes the Euclidean norm of a vector of length N. This is computed as the square-root of the 
 * dot-product of the vector with itself. The norm \f$r\f$ of vector \f$X\f$ is computed as
 * follows:
 * 
 * \f[
 *      r = \sqrt{\sum_{i=1}^{N} X_{i}^{2}}
 * \f]
 * 
 * @sa squaredNorm, dot
 * @tparam Real Real type
 * @tparam Vector Vector type
 * @param  vector A vector of length N
 * @return Scalar norm of vector
 */
template< typename Real, typename Vector >
Real norm( const Vector& vector )
{
    return std::sqrt( squaredNorm< Real, Vector >( vector ) );
}

//! Normalize vector.
/*!
 * Normalizes a vector of length N by computing the Euclidean norm of the vector and dividing by
 * the norm component-wise. The result is a unit-vector. A vector \f$X\f$ is normalized as follows:
 *
 * \f[
 *      \hat{\bar{X}} = \frac{\bar{X}}{|\bar{X}|}
 * \f]
 * 
 * @sa norm, dot
 * @tparam Real Real type
 * @tparam Vector Vector type
 * @param  vector A vector of length N
 * @return Normalized vector
 */
template< typename Real, typename Vector >
Vector normalize( const Vector& vector )
{
    // Declare normalized vector.
    Vector normalizedVector( vector.size( ) );

    // Compute the norm of the vector.
    Real vectorNorm = norm< Real, Vector >( vector );

    // Loop through vector and divide each component by the norm of the vector.
    for ( unsigned int i = 0; i < vector.size( ); i++ )
    {
        normalizedVector[ i ] = vector[ i ] / vectorNorm;
    }   

    // Return normalized vector.
    return normalizedVector;
}

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