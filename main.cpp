#include "Screen.h"
#include <iostream>

int main()
{
    ps::Screen screen;
    ps::Swarm swarm;

    Uint32 previousTicks = 0; // Used to calculate FPS
    int frameCount = 0;       // Count of frames rendered

    while (!screen.quit_program())
    {
        // load the particle swarm
        screen.load_swarm(swarm);

        // update the sdl window with all the particles and colors
        screen.update();

        // manipulate the particle positions and colors
        // tick rate is used to ensure consistent/propostional movement
        swarm.move(SDL_GetTicks());

        // apply the gaussian blur
        screen.box_blur();

        // Calculate FPS
        Uint32 currentTicks = SDL_GetTicks();
        frameCount++;
        if (currentTicks - previousTicks >= 1000) // Update FPS every 1000 ms (1 second)
        {
            int fps = frameCount;
            std::cout << "FPS: " << fps << std::endl;

            // Reset the frame count and update the previousTicks
            frameCount = 0;
            previousTicks = currentTicks;
        }
    }

    return 0;
}