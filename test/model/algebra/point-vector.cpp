#include "../../../src/model/algebra/algebra.h"
#include "../../../src/model/random/random.h"

#include <catch2/catch.hpp>
#include <cmath>
#include <iostream>
#include <vector>

#define DIST_EXTREMES 10000.0
#define USE_RANDOM_VALS 0

TEST_CASE("Points and Vectors can be used interchangeably") {
    double x, y;

    if (USE_RANDOM_VALS) {
        // TODO: CHECK why certain numbers (e.g. 1208015009) let the tests fail
        // Guess: Rounding errors
        Uniform dist = Uniform (- DIST_EXTREMES, DIST_EXTREMES);
        x = dist.rand();
        y = dist.rand();
        std::cout << "SEED: " << dist.SEED << std::endl;
    }
    else {
        x = 298.3;
        y = 8643.9;
    }

    SECTION ("Points and Vectors can be compared to") {
        Point p1(1, 1);
        Point p2(3, 4);

        Vector v1(45, sqrt(2.0));
        Vector v2(acos(0.6), 5);

        CHECK (p1 == v1);
        CHECK (v1 == p1);
        CHECK (p2 == v2);
        CHECK (v2 == p2);

        CHECK (p1 != v2);
        CHECK (v2 != p1);
        CHECK (p2 != v1);
        CHECK (v1 != p2);
    }

    SECTION ("Points and Vectors can be constructed from each other") {
        Point p(x, y);
        Vector vp(p);
        Point pvp(vp);

        CHECK (p == vp);
        CHECK (p == pvp);
        CHECK (vp == p);
        CHECK (vp == pvp);
        CHECK (pvp == p);
        CHECK (pvp == vp);
    }

    SECTION ("Points and Vectors can be assigned to each other") {
        Point p(x, y);
        Vector vp(ORIGIN);
        Point pvp(ORIGIN);

        vp = p;
        pvp = vp;

        CHECK (p == vp);
        CHECK (vp == pvp);
        CHECK (pvp == p);
    }

    SECTION ("Vectors can be created between two points") {
        Point p(1, 0);
        Point q(2, 0);
        Vector v(0, 1);

        CHECK (v == (p.vectorTo(q)));
        CHECK (v == (ORIGIN.vectorTo(p)));
    }

    SECTION ("Vectors can be added onto Points to result in new Points") {
        Point p(0, 0);

        std::vector<Vector> vectors;
        vectors.emplace_back(0, 1);
        vectors.emplace_back(45, sqrt(2));
        vectors.emplace_back(90, 1);
        vectors.emplace_back(135, sqrt(2));
        vectors.emplace_back(180, 1);
        vectors.emplace_back(225, sqrt(2));
        vectors.emplace_back(270, 1);
        vectors.emplace_back(315, sqrt(2));

        std::vector<Point> points;
        points.emplace_back(1,0);
        points.emplace_back(1,1);
        points.emplace_back(0,1);
        points.emplace_back(-1,1);
        points.emplace_back(-1, 0);
        points.emplace_back(-1, -1);
        points.emplace_back(0, -1);
        points.emplace_back(1, -1);

        int i = 0;
        for (auto & v : vectors) {
            CHECK (p + v == points[i]);
            CHECK (p - v == points[(4 + i) % 8]);
            i++;
        }
    }
}