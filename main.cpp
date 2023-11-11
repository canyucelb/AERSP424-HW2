#include <iostream>
#include <vector>
#include "Plane.h"
#include "Airliner.h"
#include "GeneralAviation.h"
#include "ATC.h"
#include "FlightMap.h"
#include "HW2_Visualizer.h"

int main(int argc, char** argv) {
    // SDL initialization 
    HW2_VIZ viz;

    // Creating a flight map and adding flights routes with their distances 
    FlightMap flightMap;
    // Distance between SCE and PHL
    flightMap.addFlight("SCE", "PHL", 160); 
    // Distance between SCE and ORD
    flightMap.addFlight("SCE", "ORD", 640); 
    // Distance between SCE and EWR
    flightMap.addFlight("SCE", "EWR", 220); 

    // Creating a ATC object for managing the planes
    ATC atc;

    // Creating Airliner and General Aviation objects with specified routes and velocities
    Airliner aa1("AA", "SCE", "PHL", flightMap);
    Airliner aa2("UA", "SCE", "ORD", flightMap);
    Airliner ua1("UA", "SCE", "EWR", flightMap);
    Airliner ua2("AA", "SCE", "ORD", flightMap);
    GeneralAviation ga1("SCE", "PHL", flightMap);
    GeneralAviation ga2("SCE", "EWR", flightMap);
    GeneralAviation ga3("SCE", "ORD", flightMap);

    // Setting the velocities for each plane (miles per hour)
    aa1.setVel(470);
    aa2.setVel(515);

    ua1.setVel(480);
    ua2.setVel(500);

    ga1.setVel(140);
    ga2.setVel(160);
    ga3.setVel(180);


    // Registering the planes with ATC for tracking and control
    atc.register_plane(&aa1);
    atc.register_plane(&aa2);
    atc.register_plane(&ua1);
    atc.register_plane(&ua2);
    atc.register_plane(&ga1);
    atc.register_plane(&ga2);
    atc.register_plane(&ga3);

    // Pick a timestep within [10, 100]
    double timestep = 10;
    bool running = true;
    while (running) {
        // Event handling loop for SDL 
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                // Setting running to false to exit the loop
                running = false; 
            }
        }

        // Updaitng the each plane's status and visualizing its position
        for (Plane* plane : atc.getRegisteredPlanes()) {
            // Updating plane position based on velocity and time  step
            plane->operate(timestep);
            // Updating the air traffic control
            atc.control_traffic();
            // Visualizing the plane's current position
            viz.visualize_plane(plane->plane_type(), plane->getOrigin(), plane->getDestination(), plane->getPos());
        }

        // Update time step and visualization
        viz.update(timestep);
    }
    // Exit the program
    return 0; 
}
