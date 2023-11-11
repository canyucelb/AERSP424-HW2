#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
// Flight class for representing a flight between airports
class Flight {
    // Origin of airport code
    std::string from;
    // Destination airport code
    std::string to;
    // Distance between two airports
    double distance;

public:
    // Constructor for setting the origin, destination and distance for the flight
    Flight(const std::string& from, const std::string& to,  double distance);
    // Getting the origin of airport code
    std::string getFrom() const;
    // Getting the destination of  airport code
    std::string getTo() const;
    // Getting the distance between origin and destination airports
    double getDistance() const;
};

#endif // FLIGHT_H
