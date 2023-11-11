#include "Flight.h"
// Initialize a flight with object origin, destination and distance
Flight::Flight(const std::string& from, const std::string& to,  double distance) 
    : from(from), to(to), distance(distance) {}

// Getting the origin airport code
std::string Flight::getFrom() const {
    return from;
}
// Getting destination of airport code
std::string Flight::getTo() const {
    return to;
}
// Getting distance between origin and destination of the airports
double Flight::getDistance() const {
    return distance;
}
