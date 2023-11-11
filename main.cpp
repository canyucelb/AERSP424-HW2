#include <iostream>
#include <vector>
#include "Plane.h"
#include "Airliner.h"
#include "GeneralAviation.h"
#include "ATC.h"
#include "FlightMap.h"
#include "HW2_Visualizer.h"

int main(int argc, char** argv) {
    // SDL initialization and window setup are done in the HW2_VIZ constructor
    HW2_VIZ viz;

    // Instantiate FlightMap and add flights
    FlightMap flightMap;
    flightMap.addFlight("SCE", "PHL", 160); // Distance between SCE and PHL
    flightMap.addFlight("SCE", "ORD", 640); // Distance between SCE and ORD
    flightMap.addFlight("SCE", "EWR", 220); // Distance between SCE and EWR

    // Instantiate ATC object
    ATC atc;

    // Instantiate plane objects and set their velocities as per the provided flight schedule
    Airliner aa1("AA", "SCE", "PHL", flightMap);
    Airliner aa2("UA", "SCE", "ORD", flightMap);
    Airliner ua1("UA", "SCE", "EWR", flightMap);
    Airliner ua2("AA", "SCE", "ORD", flightMap);
    GeneralAviation ga1("SCE", "PHL", flightMap);
    GeneralAviation ga2("SCE", "EWR", flightMap);
    GeneralAviation ga3("SCE", "ORD", flightMap);


    aa1.setVel(470);
    aa2.setVel(515);

    ua1.setVel(480);
    ua2.setVel(500);

    ga1.setVel(140);
    ga2.setVel(160);
    ga3.setVel(180);


    // Register planes with ATC
    atc.register_plane(&aa1);
    atc.register_plane(&aa2);
    atc.register_plane(&ua1);
    atc.register_plane(&ua2);
    atc.register_plane(&ga1);
    atc.register_plane(&ga2);
    atc.register_plane(&ga3);

    // Pick a timestep within [10, 100], for this example we use 50 seconds
    double timestep = 10;
    bool running = true;
    while (running) {
        // Handle SDL events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false; // Set running to false to exit the loop
            }
        }

        // Operate each plane and control traffic
        for (Plane* plane : atc.getRegisteredPlanes()) {
            plane->operate(timestep);
            atc.control_traffic();
            // Visualize the plane's current position
            viz.visualize_plane(plane->plane_type(), plane->getOrigin(), plane->getDestination(), plane->getPos());
        }

        // Update the visualization with the timestep
        viz.update(timestep);
    }

    return 0;
}
