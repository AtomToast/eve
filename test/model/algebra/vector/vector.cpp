#include "../../../../src/model/algebra/vector/vector.h"

#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("Vectors can be used for calculations and simple arithmetic") {
    std::vector<Vector> VECTORS;
    VECTORS.emplace_back(90, 1.5);
    VECTORS.emplace_back(0.5 * M_PI, 1.5);
    VECTORS.emplace_back(M_PI, 4);
    VECTORS.emplace_back(135, 5);
    VECTORS.emplace_back(270, 1.5);
    VECTORS.emplace_back(270, -1.5);

    SECTION ("Vectors get instantiated correctly") {
        CHECK (VECTORS[4].angle == 1.5 * M_PI);
        CHECK (VECTORS[4].length == 1.5);

        CHECK (VECTORS[5].angle.radians() == 0.5 * M_PI);
        CHECK (VECTORS[5].length == 1.5);
    }

    SECTION ("Vectors can be compared") {
        for (auto & v : VECTORS) CHECK (v == v);
        CHECK (VECTORS[0] == VECTORS[1]);

        CHECK (VECTORS[2] != VECTORS[3]);
        CHECK (VECTORS[4] != VECTORS[5]);
    }

    SECTION ("Vectors can be negated") {
        for (auto & v : VECTORS) CHECK (v == - - v);
        CHECK (VECTORS[4] == - VECTORS[5]);
    }

    SECTION ("Vectors can be added and subtracted") {
        CHECK ((VECTORS[0] + VECTORS[1]).angle.degrees() == 90);
        CHECK ((VECTORS[0] + VECTORS[1]).length == 3.0);

        Vector v = VECTORS[4] + VECTORS[5];
        CHECK (v == Vector(ORIGIN));

        v = VECTORS[0] - VECTORS[1];
        CHECK (v == Vector(ORIGIN));
    }

    SECTION ("Angles and Vectors can be added onto a Vector") {
        Vector v(0, 0);
        for (int i = 0; i < 360; i += 10) {
            Vector w (i, 10);
            Vector r = v + w;
            CHECK (r == w);
        }


    }
}
