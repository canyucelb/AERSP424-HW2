#ifndef ATC_H
#define ATC_H

#include "Plane.h"
#include <vector>
// Class for Air Traffic Contral (ATC) for managing the registration  and traffic of the planes
class ATC {
private:
    // Storing the resigstered planes 
    std::vector<Plane*> registered_planes; 
    // Limits the maximum landed planes
    const int MAX_LANDED_PLANE_NUM = 2;    
    // Distance for planes if they can't land
    const int AIRSPACE_DISTANCE = 50;     

public:
    // Constructor
    ATC();
    // Destructor
    ~ATC();
    // Registering plane with ATC
    void register_plane(Plane* plane);
    // Manages the air traffic of registered planes
    void control_traffic();

    // Retrieves the registered current plane list
    const std::vector<Plane*>& getRegisteredPlanes() const;
};

#endif // ATC_H
