#include "entity.h"

Entity::Entity(double x, double y, double energy) :
    Entity(Point(x, y), energy) {}

Entity::Entity(Point position, double energy) :
    Object(position),
    energy{energy} {checkEnergy();}

void Entity::checkEnergy() const {
    if (energy <= 0) throw std::range_error("Entity::checkEnergy(): Energy has to be positive");
}

double Entity::getEnergy() const {return energy;}

double Entity::getRadius() const { return sqrt(energy) / M_PI; }

const Vector & Entity::applyForce(const Vector & v) {
    return speed += v;
}

const Vector & Entity::applyFriction() {
    return speed = Vector(speed.angle, (1 - FRICTION) * speed.length);
}

Point Entity::updatePosition() {
    return position += speed;
}
Point Entity::updatePosition(const std::function<Point(Point)> & normalise) {
    return position = normalise(position + speed);
}

void Entity::updateEnergy (double newEnergy) {
    energy = newEnergy;
}

double Entity::addEnergy (double e) {
    return energy += e;
}