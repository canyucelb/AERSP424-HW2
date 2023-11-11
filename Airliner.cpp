#include "Airliner.h"

// Constructor definition of the Airliner class
Airliner::Airliner(const std::string& airline, const std::string& from, const std::string& to, const FlightMap& flightMap)
    : Plane(from, to, flightMap), airline(airline) {}

// Destructor for Airliner class
Airliner::~Airliner() {}

// Mmeber function for plane type which allows to return type of plane
std::string Airliner::plane_type() const {
    return airline;
}

// Member function 'time_on_ground' that returns the time an airliner spends on the ground.
double Airliner::time_on_ground() {
    return draw_from_normal_dist(1800, 600);
}
