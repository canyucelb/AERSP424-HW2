// Plane.h
#ifndef PLANE_H
#define PLANE_H

#include <string>
#include "FlightMap.h"
// Declaration of the Plane class
class Plane {
private:
    // Private member variables that cannot be accessed directly from outside the class
    std::string origin;
    std::string destination;
    // Velocity in mph
    double vel = 0; 
    // Position in miles
    double pos = 0; 
    // Total distance to travel in miles
    double distance; 
    // Whether the plane is at SCE
    bool at_SCE = 0; 
    // Time to loiter
    double loiter_time = 0; 

protected:
    // Time the plane waits on the ground after landing initally set to 0
    double wait_time = 0.0;


public:
    //  Constructor declaration with parameters for origin, destination, and a reference to a FlightMap object
    Plane(const std::string& from, const std::string& to, const FlightMap& flightMap);
    // Destructor
    virtual ~Plane();
    // Function to update the plane's state given a time delta
    virtual void operate(double dt); 
    // Time a plane spending time on the ground
    virtual double time_on_ground() = 0;
    // Representation thetype of plane 
    virtual std::string plane_type() const = 0;
    // Returns the current position of the plane
    double getPos() const;
    // Returns the current velocity of the plane
    double getVel() const;
    // Returns the current loiter time of the plane
    double getLoiterTime() const;
    // Returns the origin airport code
    std::string getOrigin() const;
    // Returns the destination airport code
    std::string getDestination() const;
    // Returns the at_SCE flag status
    bool getAtSCE() const;
    // Sets the current velocity of the plane
    void setVel(double v);
    // Sets the loiter time of the plane
    void setLoiterTime(double lt);
    // Function to calculate the distance to SCE based on current position and destination
    double distance_to_SCE() const;
     // Static function to generate a random number from a normal distribution given a mean and standard deviation
    static double draw_from_normal_dist(double mean, double stddev);
};

#endif // PLANE_H
