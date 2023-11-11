#ifndef AIRLINER_H
#define AIRLINER_H

#include "Plane.h"

// Airliner class from derived Plane class

class Airliner : public Plane {
private:
    // Airline name
    std::string airline; 

public:
    // Constructor with initilazition list
    Airliner(const std::string& airline, const std::string& from, const std::string& to, const FlightMap& flightMap);
    // Deconstructor
    ~Airliner() override;
    // Returning the plane type
    std::string plane_type() const override;
    // Time calculation on the ground
    double time_on_ground() override;
};

#endif // AIRLINER_H
