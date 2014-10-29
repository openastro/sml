/*    
 * Copyright (c) 2014 K. Kumar (me@kartikkumar.com)
 * Distributed under the MIT License.
 * See accompanying file LICENSE or copy at http://opensource.org/licenses/MIT
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
