#include "FlightMap.h"
#include <stdexcept>


// Adding flight with specified origin, destination and distance
void FlightMap::addFlight(const std::string& from, const std::string& to,  double distance) {
    flights[from].emplace_back(from, to, distance);
}
// Retrieves the distance between airports for the flight
double FlightMap::getDistance(const std::string& from, const std::string& to) const {
    // Finding the flights departing
    auto it = flights.find(from);
    // If flight exists
    if (it != flights.end()) {
        // Iterate over flights
        for (const auto& flight : it->second) {
            // If the destination matches to 
            if (flight.getTo() == to) {
                // Return the distance of the flight
                return flight.getDistance();
            }
        }
    }
    // If the flight does not exists
    throw std::runtime_error("Flight route not found between " + from + " and " + to);
}
