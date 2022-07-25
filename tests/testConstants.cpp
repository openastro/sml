/*
 * Copyright (c) 2014-2022 Kartik Kumar (me@kartikkumar.com)
 * Distributed under the MIT License.
 * See accompanying file LICENSE.md or copy at http://opensource.org/licenses/MIT
 */

#include <catch2/catch_test_macros.hpp>

#include "sml/constants.hpp"

namespace sml
{
namespace tests
{

TEST_CASE("Test definition of constants", "[constants]")
{
    SECTION("Test that pi is defined correctly")
    {
        REQUIRE(SML_PI == 3.14159265358979323846);
    }
}

} // namespace tests
} // namespace sml
