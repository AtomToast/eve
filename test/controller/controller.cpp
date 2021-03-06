#include "../../src/controller/controller.h"
#include "../../src/main.h"

#include <catch2/catch.hpp>
#include <stdexcept>

SCENARIO("The Controller can be initialised") {
    GIVEN("An instance of a controller") {
        Controller controller = Controller(WIDTH, HEIGHT, ENERGY);

        WHEN ("I start the controller") {
            WHEN ("The controller isn't initialised yet") {
                THEN ("the controller throws an exception") {
                    CHECK_THROWS_AS(controller.run(), std::logic_error);
                }
            }
            CHECK_NOTHROW(controller.init());
        }
    }
}
