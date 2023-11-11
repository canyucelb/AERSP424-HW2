#include "GeneralAviation.h"

// Constructor
GeneralAviation::GeneralAviation(const std::string& from, const std::string& to, const FlightMap& flightMap)
    : Plane(from, to, flightMap) {}

// Destructor
GeneralAviation::~GeneralAviation() {}

// Getting the type of plane if it is NA (Non - Airliner)
std::string GeneralAviation::plane_type() const {
    return "NA";
}

// Determining the time a general aviation plane spends on the ground
double GeneralAviation::time_on_ground() {
    
    return draw_from_normal_dist(600, 60);
}
