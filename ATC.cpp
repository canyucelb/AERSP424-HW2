#include "ATC.h"

// Default constructor
ATC::ATC() {}
// Destructor
ATC::~ATC() {}
// Registring a new plane with ATC control
void ATC::register_plane(Plane* plane) {
    // Adding plane to the list
    registered_planes.push_back(plane);
}
// Managing traffic of registered listed planes
void ATC::control_traffic() {
    int landed_planes = 0;

    // Counting the landed planes
    for (Plane* plane : registered_planes) {
        if (plane->getAtSCE()) {
            landed_planes++;
        }
    }
    // If less than max plane return 
    if(landed_planes<MAX_LANDED_PLANE_NUM){
        return;
    }

    // Assigning the loiter times to the registered planes 
    for (Plane* plane : registered_planes) {
        // If the plane is not at SCE and within the airspace distance, and not loitering
        if (plane->getAtSCE()==0 && plane->distance_to_SCE() <= AIRSPACE_DISTANCE && plane->getLoiterTime() == 0) {
            // Setting the loiter time 
            plane->setLoiterTime(100); 
        }
    }
}
// Accessing the list of registered planes
const std::vector<Plane*>& ATC::getRegisteredPlanes() const {
    // Return current registered planes list
    return registered_planes;
}
