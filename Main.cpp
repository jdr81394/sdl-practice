#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <iostream>

int main(int argc, char* argv[]){
    
    SDL_Window* window = nullptr;
    SDL_Surface* screen;

    if( SDL_Init(SDL_INIT_VIDEO) < 0 ) 
        std::cout << "SDL could not be initialized" << SDL_GetError();

    window = SDL_CreateWindow(
        "An SDL2 window",
        1000,
        1000,
        1000,
        1000,
        SDL_WINDOW_SHOWN       
    );

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  /* NOTES */
  /*

  An SDL surface is just some amount of pixels
  ________________________
  |                     |
  |                     |
  |                     |
  |                     |
  |                     |    
  |                     |
  |                     |
  -----------------------
    ^
    |
    |
    |
    |
    A Texture USES a surface. The texture is image data that is hosted on the GPU.
    It is inside of video memory. A texture USES surface pixels.

    SDL_CreateTextureFromSurface() explanation:
    This takes the surface that you have created, maybe you created a surface from a bmp/png.
    Now, it converts a texture. A texutre is on the hardware. It could be uploaded to the hardware which allows for
    better ways to draw something.

  */

   SDL_Surface* surface = SDL_LoadBMP("./assets/blender.bmp");
   SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    // After you create a texture from a surface you can free it.
    // Since the surface uploaded to the gpu as a texture, you can free it.

    SDL_FreeSurface(surface);


    // Infinite Loop for our application
    bool gameIsRunning = true;


    while(gameIsRunning) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                gameIsRunning = false;
            }

            // Clears the screen of anything that might have been there before

            // (2) handle updates

            // (3) clear and draw the screen
            SDL_SetRenderDrawColor(renderer, 0, 0, 0,0);
            SDL_RenderClear(renderer);

            SDL_SetRenderDrawColor(renderer, 255,255,200,255);
            SDL_RenderDrawLine(renderer, 5,5,200,200);

            // SDL_RenderCopy

            SDL_Rect rectangle = {
                100,100,100,100
            };

            /* NOTES */
            /*
                Here, were taking the texture and applying it to the renderer.
                3rd argument is what portion of the texture, NULL for the whole thing
                4th argument is where on the window you want that to go.
            */
            SDL_RenderCopy(renderer,texture, NULL,&rectangle);

            // (4) Finally show what we have drawn
            SDL_RenderPresent(renderer);
            
        }
    }

    SDL_DestroyTexture(texture);    
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;

};



// https://www.youtube.com/watch?v=75yEVx8iXYQ&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=17
int texturedRectanglesWithSDLTextureAndSdlRenderCopy() {
    
    SDL_Window* window = nullptr;
    SDL_Surface* screen;

    if( SDL_Init(SDL_INIT_VIDEO) < 0 ) 
        std::cout << "SDL could not be initialized" << SDL_GetError();

    window = SDL_CreateWindow(
        "An SDL2 window",
        1000,
        1000,
        1000,
        1000,
        SDL_WINDOW_SHOWN       
    );

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  /* NOTES */
  /*

  An SDL surface is just some amount of pixels
  ________________________
  |                     |
  |                     |
  |                     |
  |                     |
  |                     |    
  |                     |
  |                     |
  -----------------------
    ^
    |
    |
    |
    |
    A Texture USES a surface. The texture is image data that is hosted on the GPU.
    It is inside of video memory. A texture USES surface pixels.

    SDL_CreateTextureFromSurface() explanation:
    This takes the surface that you have created, maybe you created a surface from a bmp/png.
    Now, it converts a texture. A texutre is on the hardware. It could be uploaded to the hardware which allows for
    better ways to draw something.

  */

   SDL_Surface* surface = SDL_LoadBMP("./assets/blender.bmp");
   SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    // After you create a texture from a surface you can free it.
    // Since the surface uploaded to the gpu as a texture, you can free it.

    SDL_FreeSurface(surface);


    // Infinite Loop for our application
    bool gameIsRunning = true;


    while(gameIsRunning) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                gameIsRunning = false;
            }

            // Clears the screen of anything that might have been there before

            // (2) handle updates

            // (3) clear and draw the screen
            SDL_SetRenderDrawColor(renderer, 0, 0, 0,0);
            SDL_RenderClear(renderer);

            SDL_SetRenderDrawColor(renderer, 255,255,200,255);
            SDL_RenderDrawLine(renderer, 5,5,200,200);

            // SDL_RenderCopy

            SDL_Rect rectangle = {
                100,100,100,100
            };

            /* NOTES */
            /*
                Here, were taking the texture and applying it to the renderer.
                3rd argument is what portion of the texture, NULL for the whole thing
                4th argument is where on the window you want that to go.
            */
            SDL_RenderCopy(renderer,texture, NULL,&rectangle);

            // (4) Finally show what we have drawn
            SDL_RenderPresent(renderer);
            
        }
    }

    SDL_DestroyTexture(texture);    
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;

}
// https://www.youtube.com/watch?v=9P_MAgSNZx8&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=17
int renderDrawLinesAndRectanglesUsingSdlRenderer() {
       SDL_Window* window = nullptr;
    SDL_Surface* screen;

    if( SDL_Init(SDL_INIT_VIDEO) < 0 ) 
        std::cout << "SDL could not be initialized" << SDL_GetError();

    window = SDL_CreateWindow(
        "An SDL2 window",
        1000,
        1000,
        1000,
        1000,
        SDL_WINDOW_SHOWN       
    );

    /* NOTESSSS */
    // Difference between drawing using renderer and using surfaces
    // Rendering must be continually drawn through time
    // while surface is permanent and remains until it is over ridden. It does not need to have to be redrawn constantly.
    // A renderer can be thought of as an object that contains a global state about how an object will be written to a screen.
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);



    // Infinite Loop for our application
    bool gameIsRunning = true;


    while(gameIsRunning) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                gameIsRunning = false;
            }

            // Clears the screen of anything that might have been there before

            // (2) handle updates

            // (3) clear and draw the screen
            // gives us  a clear canvas
            // We set the render draw color to black, and then the renderclear clears it
            // to black
            SDL_SetRenderDrawColor(renderer, 0, 0, 0,0);
            SDL_RenderClear(renderer);

            // Do our drawing
            // We set the render draw color, and then we draw a line in that color.
            SDL_SetRenderDrawColor(renderer, 255,255,200,255);
            SDL_RenderDrawLine(renderer, 5,5,200,200);

            // We can create a rectangle.
            SDL_Rect rectangle = {
                100,100,100,100
            };
            SDL_RenderDrawRect(renderer, &rectangle);

            // (4) Finally show what we have drawn
            SDL_RenderPresent(renderer);
            
        

        }
    }

    
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

// https://www.youtube.com/watch?v=YlwDwC4H47s&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=14
int sdlSurfaceGetWindowSurfaceAndSdlLoadBmp() {
       // SDL_Surface is a structure that contains a collection of pixels used in
    // software blitting

    // What is pitch in an SDL Surface?
    // The pitch = width * #of components
    // # of components = R,G,B of a pixel. 
    // The pitch allows us to determine the number of bytes in a row. 
    // Sometimes you have an additional attribute for the opacity.
    
    SDL_Window* window = nullptr;
    // Grab the window surface
    SDL_Surface* screen;

    if( SDL_Init(SDL_INIT_VIDEO) < 0 ) 
        std::cout << "SDL could not be initialized" << SDL_GetError();

    window = SDL_CreateWindow(
        "An SDL2 window",
        1000,
        1000,
        1000,
        1000,
        SDL_WINDOW_SHOWN        // This means by default the window will show unless I tell it not to show.
    );

    // If I understand what is going on, what SDL_GetWindowSurface is doing
    // is: It is getting the actual pixels that are appearing in the window.
    // I'm not sure if its just a row or if it is the whole thing.
    screen = SDL_GetWindowSurface(window);

    // Now we want to get the pixels from our image
    SDL_Surface* image = SDL_LoadBMP("./assets/blender.bmp");

    // SDL Blit surface - takes one surface that represents an image, and copies to another surface
    SDL_BlitSurface(image, NULL, screen, NULL);

    SDL_FreeSurface(image);

    // This redraws our window surface
    // This will properly draw the image to the window. This may not be the right size we may need to resize it.
    SDL_UpdateWindowSurface(window);


    // Infinite Loop for our application
    bool gameIsRunning = true;

    while(gameIsRunning) {
        SDL_Event event;
        // Start our event loop here
        while(SDL_PollEvent(&event)) {
            // Handle each event
            // Here are the different types the event.type can have
            // https://wiki.libsdl.org/SDL_Event
            if(event.type == SDL_QUIT) {
                gameIsRunning = false;
            }

            // Handle Mouse motion
            if(event.type == SDL_MOUSEMOTION) {

            }

            if(event.type == SDL_KEYDOWN) {

            }

            // Handle key down
            const Uint8* state = SDL_GetKeyboardState(NULL);
            if(state[SDL_SCANCODE_RIGHT]) {
                std::cout << "Right arrow key is pressed\n";
            }

        }
    }

    

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

// https://www.youtube.com/watch?v=FwRfH2bA48M&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=10
void applicationLoopAndEventQueue() {
     SDL_Window* window = nullptr;

    if( SDL_Init(SDL_INIT_VIDEO) < 0 ) 
        std::cout << "SDL could not be initialized" << SDL_GetError();


    window = SDL_CreateWindow(
        "An SDL2 window",
        1000,
        1000,
        1000,
        1000,
        SDL_WINDOW_SHOWN        // This means by default the window will show unless I tell it not to show.
    );

    // Infinite Loop for our application
    bool gameIsRunning = true;
    while(gameIsRunning) {
        SDL_Event event;
        // Start our event loop here
        while(SDL_PollEvent(&event)) {
            // Handle each event
            // Here are the different types the event.type can have
            // https://wiki.libsdl.org/SDL_Event
            if(event.type == SDL_QUIT) gameIsRunning = false;
        }
    }



    SDL_DestroyWindow(window);


    SDL_Quit();
    return;
}

// https://www.youtube.com/watch?v=qPHKWsZK2Jc&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=9
void createWindowLecture() {
   SDL_Window* window = nullptr;

    if( SDL_Init(SDL_INIT_VIDEO) < 0 ) 
        std::cout << "SDL could not be initialized" << SDL_GetError();


    window = SDL_CreateWindow(
        "An SDL2 window",
        1000,
        1000,
        1000,
        1000,
        SDL_WINDOW_SHOWN        // This means by default the window will show unless I tell it not to show.
    );

    // Window will not appear without a delay, however delay creates a bug where window will still not show.
    // I mention this in the sdlNotesOnMyOwn, but here is the stackoverflow with the solution.
    // The solution is that the delay blocks the creation of the window, so you need to set up a main loop
    // https://stackoverflow.com/questions/37848065/sdl-window-not-showing-up-at-all

    SDL_DestroyWindow(window);


    SDL_Quit();
}

void sdlNotesOnMyOwn() {

    // 1. Initialize all SDL controls
    // To do this we use an imperative paradigm. We call SDL_INIT function that takes a few different built in arguments
    // 2. We can pass it a variety of values, but we want to pass it SDL_INIT_EVERYTHING to initialize every sub system.

    SDL_Init(SDL_INIT_EVERYTHING);

    // 3. The SDL display mode "contains the description of the display mode".. Not very helpful.
    // https://wiki.libsdl.org/SDL_DisplayMode
    SDL_DisplayMode displayMode;

    //4. SDL_GetCurrentDisplayMode - I believe the "0" is the current monitor that you are using, and it is filling
    // that value of "0" into your displayMode variable so your window can use that window to display the future window.
    SDL_GetCurrentDisplayMode(0, &displayMode);

    // 5. Now that the displayMode has pulled in the values of the correct display, get what you want the window size to be from it. 
    glm::vec2 windowDimensions = glm::vec2(displayMode.w, displayMode.h);

    // 6. Now that we have the windows dimensions, lets make the dimensions of our game window
    // SDL_CreateWindow is the imperative paradigm way of creating a window. This creates a pointer.
    SDL_Window* window = SDL_CreateWindow(
        NULL, 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        windowDimensions.x, 
        windowDimensions.y,
        SDL_WINDOW_RESIZABLE
    );

    // 7. Create renderer takes 3 arguments
    // the 1st one is the window where the rendering will be displayed, 
    // the other 2 dont really matter
    // this doesnt matter in actually making the screen appear.
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // For some reason screen doesn't appear unless this imperative function call is made
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

    // ^^ found solution, the SDL_Delay blocks it
    // https://stackoverflow.com/questions/37848065/sdl-window-not-showing-up-at-all
    // Here is what code would needed to be add to make this work.
    // A basic main loop to prevent blocking
    // bool is_running = true;
    // SDL_Event event;
    // while (is_running) {
    //     while (SDL_PollEvent(&event)) {
    //         if (event.type == SDL_QUIT) {
    //             is_running = false;
    //         }
    //     }
    //     SDL_Delay(16);
    // }


    SDL_Delay(10000);

    
};