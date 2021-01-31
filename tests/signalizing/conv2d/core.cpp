#include "signalizing/conv2d/core.hpp"

#include <array>
#include <catch2/catch.hpp>
#include <iostream>

TEST_CASE("conv2d/core - convolute_simple", "[conv2d][core]") {
  GIVEN("A matrix and a core") {
    std::array<std::array<int, 5>, 5> a        = { { { 1, 1, 1, 1, 1 },
                                              { 1, 1, 1, 1, 1 },
                                              { 1, 1, 1, 1, 1 },
                                              { 1, 1, 1, 1, 1 },
                                              { 1, 1, 1, 1, 1 } } };
    std::array<std::array<int, 5>, 5> expected = { { { 4, 8, 8, 8, 6 },
                                                     { 1, 2, 2, 2, 2 },
                                                     { 1, 2, 2, 2, 2 },
                                                     { 1, 2, 2, 2, 2 },
                                                     { -2, -4, -4, -4, -3 } } };


    std::array<std::array<int, 3>, 3> core = { { { 1, 2, 3 }, { 1, 0, 1 }, { -2, -1, -3 } } };

    WHEN("Convoluting within the original range") {
      std::array<std::array<int, 5>, 5> res;
      signalizing::conv2d::core::convoluteSimple(a, core, res);

      THEN("The expected result is generated") {
        for (auto row = 0; row < size(res); row++) {
          for (auto col = 0; col < size(res[row]); col++) {
            REQUIRE(expected[row][col] == res[row][col]);
          }
        }
      }
    }
  }
}