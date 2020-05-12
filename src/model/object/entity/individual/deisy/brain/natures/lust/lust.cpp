#include "lust.h"

Uniform Lust::dice {0, 1};

Action Lust::think(const std::unique_ptr<std::vector<Object *> > & visibles, double energy) {
    if (energy > REPRODUCTION_THRESHOLD) return Action (REPRODUCE);
    if (visibles->size() > visiblesLimit) return Action (MOVE);
    double random = dice.rand();
    if (random < LUST_MOVE_WEIGHT) return Action (MOVE);
    return Action ((turnLeft == (LUST_MOVE_WEIGHT <= random < LUST_TURN_WEIGHT)) ? TURN_LEFT : TURN_RIGHT);
}

