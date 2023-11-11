#ifndef FLIGHTMAP_H
#define FLIGHTMAP_H

#include "Flight.h"
#include <map>
#include <vector>
#include <string>

// Class for managing the map of fligts
class FlightMap {
private:
    // Holding the lists of flights by their origin airport code
    std::map<std::string, std::vector<Flight>> flights;

public:
    // Adding flights between two airports for given distance
    void addFlight(const std::string& from, const std::string& to,  double distance);
    // Retrieving the distances between two airports
    double getDistance(const std::string& from, const std::string& to) const;
};

#endif // FLIGHTMAP_H
