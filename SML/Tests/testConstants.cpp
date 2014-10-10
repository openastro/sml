/*    
 * Copyright (c) 2014, K. Kumar (me@kartikkumar.com)
 * All rights reserved.
 */

#include <catch.hpp>

#include <SML/constants.hpp>

namespace sml
{
namespace tests
{

TEST_CASE( "Test definition of constants", "[constants]" )
{
    SECTION( "Test that pi is defined correctly" )
    {
        REQUIRE( SML_PI == 3.14159265358979323846 );
    }
}

} // namespace tests
} // namespace sml
