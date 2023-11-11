// GeneralAviation.h
#ifndef GENERALAVIATION_H
#define GENERALAVIATION_H

#include "Plane.h"
// Representing the general aviation aircraft in the simulation
class GeneralAviation : public Plane {
public:
    // Constructor for initializing general aviation plane with given parameters
    GeneralAviation(const std::string& from, const std::string& to, const FlightMap& flightMap);
    // Destructor for General Aviation class
    ~GeneralAviation() override;
    // Returns type of plane
    std::string plane_type() const override;
    // Time for general aviation plane spends on the ground between flights
    double time_on_ground() override;
};

#endif // GENERALAVIATION_H
