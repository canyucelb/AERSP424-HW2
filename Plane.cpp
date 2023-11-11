#include "Plane.h"
#include <random>
#include <cmath>
#include <algorithm>


// Initializing a Plane object with the given origin, destination, and a FlightMap reference
Plane::Plane(const std::string& from, const std::string& to, const FlightMap& flightMap)
    : origin(from), destination(to), vel(0), pos(0), at_SCE(false), loiter_time(0) {
    // Setting distance of the flight using flightmap
    distance = flightMap.getDistance(from, to);
}

Plane::~Plane() {
    // Destructor for plane class
}
// Operating function updates of the plane's position and state based on elapsed time (dt)
void Plane::operate(double dt) {
    // If the plane is currently loitering, decrement the loiter time and return early
    if(loiter_time>0){
        loiter_time -= dt;
        return;
    }
    // If plane is on the ground (waiting time) , decrement the waiting time and return early
    if(wait_time>0){
        wait_time -= dt;
        return; 
    }
    // If the plane is still in the air, update its position based on its velocity and elapsed time
    if(pos<distance){
        pos+= vel * dt/3600;
        at_SCE = false;
        return;
    }
    // If the plane's destination is SCE and it has reached it, update the at_SCE status
    if(destination=="SCE"){
        at_SCE = true;
    }
    // Set waiting time based on the time on the ground required
    wait_time =  time_on_ground();
    // Swap the origin and destination
    auto temp = origin;
    origin = destination;
    destination = temp;
    pos = 0.0;
}


// Returning the plane type
std::string Plane::plane_type() const {
    // Default plane type is General Aviation
    return "GA";
}

// Getting current position of the plane

double Plane::getPos() const {
    return pos;
}
// Getting velocity of the plane
double Plane::getVel() const {
    return vel;
}
// Getting remaining loiter time
double Plane::getLoiterTime() const {
    return loiter_time;
}
// Getting origin of the airport code
std::string Plane::getOrigin() const {
    return origin;
}
// Getting destination of airport code
std::string Plane::getDestination() const {
    return destination;
}
// Getting status of plane whether it's at SCE airport
bool Plane::getAtSCE() const {
    return at_SCE;
}
// Setting velocity of the plane
void Plane::setVel(double v) {
    vel = v;
}
// Setting loiter time of the plane
void Plane::setLoiterTime(double lt) {
    loiter_time = lt;
}
// Calcualtion the distance to SCE airport
double Plane::distance_to_SCE() const {
    if (destination == "SCE") {
        return distance - pos;
    } 

    return 10000;
}
// Generates and returns a random number from a normal distribution with the given mean and standard deviation
double Plane::draw_from_normal_dist(double mean, double stddev) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::normal_distribution<> dist(mean, stddev);
    return dist(gen);
}
