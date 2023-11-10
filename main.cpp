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
    Airliner aa1("AA", "SCE", "PHL", 470, flightMap);
    Airliner aa2("AA", "SCE", "ORD", 500, flightMap);
    Airliner ua1("UA", "SCE", "EWR", 480, flightMap);
    Airliner ua2("UA", "SCE", "ORD", 515, flightMap);
    GeneralAviation ga1("SCE", "PHL", 140, flightMap);
    GeneralAviation ga2("SCE", "EWR", 160, flightMap);
    GeneralAviation ga3("SCE", "ORD", 180, flightMap);

    // Register planes with ATC
    atc.register_plane(&aa1);
    atc.register_plane(&aa2);
    atc.register_plane(&ua1);
    atc.register_plane(&ua2);
    atc.register_plane(&ga1);
    atc.register_plane(&ga2);
    atc.register_plane(&ga3);

    // Pick a timestep within [10, 100], for this example we use 50 seconds
    double timestep = 50;

    // Simulation loop
    while (!viz.quit) {
        // Handle SDL events
        while (SDL_PollEvent(&viz.event)) {
            if (viz.event.type == SDL_QUIT) {
                viz.quit = true;
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

    // Clean up SDL resources
    SDL_DestroyTexture(viz.texture);
    SDL_FreeSurface(viz.image);
    SDL_DestroyRenderer(viz.renderer);
    SDL_DestroyWindow(viz.win);
    SDL_Quit();

    return 0;
}
