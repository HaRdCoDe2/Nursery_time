//Jai Bajarangbali
//renderwindow.cpp
#include"renderwindow.hpp"

bool render::Initialize()
{
	 // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize SDL_image for loading various image formats
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    window = SDL_CreateWindow("Nursey Time " , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , width , height , SDL_WINDOW_SHOWN);
    if(!window)
    {
	    cout<<"Error: Cannot create window using SDL"<<SDL_GetError()<<endl;
	    return false;
    }

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!render)
    {
	    cout<<"Error: Could not initialize renderer render for the Window window !"<<SDL_GetError()<<endl;
	    return false;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! TTF_Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    // Initialize SDL_mixer
   if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) != (MIX_INIT_MP3 | MIX_INIT_OGG)) {
       std::cerr << "SDL_mixer could not initialize! Mix_Error: " << Mix_GetError() << std::endl;
       return 1;
   }

   if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
       std::cerr << "SDL_mixer could not initialize! Mix_Error: " << Mix_GetError() << std::endl;
       return 1;
   }



    //IMGUI_CHECKVERSION(); // initializing imgui frontend and backend
    //ImGui::CreateContext();
    //ImGuiIO& io = ImGui::GetIO(); (void)io;
    //ImGui::StyleColorsDark();
    //ImGui_ImplSDL2_InitForSDLRenderer(window, render);
    //ImGui_ImplSDLRenderer2_Init(render);

    return true;
}

void render::setup()
{
	//Initializing textures using images and surface
	surface = IMG_Load("resource/images/back.jpg");
	if(!surface)
	{
		cout<<"Surface : !back.jpg"<<SDL_GetError()<<endl;
	}
	back = SDL_CreateTextureFromSurface(render , surface);
	if(!back)
	{
		cout<<"Cannot create texture"<<SDL_GetError()<<endl;
	}
	surface = IMG_Load("resource/images/standing.png");
        if(!surface)
        {
                cout<<"Surface : !standing.png"<<SDL_GetError()<<endl;
        }
        MC = SDL_CreateTextureFromSurface(render , surface);
        if(!MC)
        {
                cout<<"Cannot create texture"<<SDL_GetError()<<endl;
        }
  surface = IMG_Load("resource/images/2.png");
        if(!surface)
        {
                cout<<"Surface : !2.png"<<SDL_GetError()<<endl;
        }
        Cus = SDL_CreateTextureFromSurface(render , surface);
        if(!Cus)
        {
                cout<<"Cannot create texture"<<SDL_GetError()<<endl;
        }
        surface = IMG_Load("resource/images/coin.png");
              if(!surface)
              {
                      cout<<"Surface : !coin.png"<<SDL_GetError()<<endl;
              }
              coinbox = SDL_CreateTextureFromSurface(render , surface);
              if(!coinbox)
              {
                      cout<<"Cannot create texture"<<SDL_GetError()<<endl;
              }
              surface = IMG_Load("resource/images/counter.png");
                    if(!surface)
                    {
                            cout<<"Surface : !counter.png"<<SDL_GetError()<<endl;
                    }
                    counter = SDL_CreateTextureFromSurface(render , surface);
                    if(!coinbox)
                    {
                            cout<<"Cannot create texture"<<SDL_GetError()<<endl;
                    }
                    font = TTF_OpenFont("resource/fonts/Roboto-Black.ttf", 30); // 24 is the font size
               if (!font) {
                   printf("Failed to load font! TTF_Error: %s\n", TTF_GetError());
                   // Handle the error and clean up
               }

               back_music = Mix_LoadMUS("resource/audio/background_music.mp3");
               if(!back_music)
               {
                 cerr<<"Failed to load music from file background_music.mp3 Error:"<<Mix_GetError()<<endl;

               }

               if (Mix_PlayMusic(back_music, -1) == -1)
               {
                        cerr<<"Failed to play music Error:"<<Mix_GetError()<<endl;
               }

               Mix_VolumeMusic(64);

                coin_sound = Mix_LoadWAV("resource/audio/coinsound.wav");
                if (!coin_sound)
                {
                    cerr<<"Cannot lad coin sound from coinsound.wav Error:"<<Mix_GetError()<<endl;
                }


}

void render::print()
{
	//Printing everything on the screen using Render
  SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderClear(render);
	SDL_RenderCopy(render , back , NULL, NULL);
	SDL_RenderCopy(render , MC , &Cords[0] , &Cords[1]);
  SDL_RenderCopy(render , counter , NULL , NULL);
  SDL_RenderCopy(render , Cus ,&Cords[2] , &Cords[3]);
  SDL_RenderCopy(render , coinbox , &Cords[4], &Cords[5]);
  SDL_RenderCopy(render, textTexture, NULL , &Cords[6]);

  //ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData() , render);
	SDL_RenderPresent(render);
}

void render::Destroy()
{
	// Destroy texture, renderer, and window , imgui

    //ImGui_ImplSDLRenderer2_Shutdown();
    //ImGui_ImplSDL2_Shutdown();
    //ImGui::DestroyContext();

    SDL_DestroyTexture(back);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_FreeSurface(surface); // Free the surface
    TTF_CloseFont(font); // Close the font


    // Quit SDL_image and SDL
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}





void render::animation()
{
	Cords[0].x+=60;
   Cords[2].x+=60;
	if(Cords[0].x == 240 )
	{
		Cords[0].x = 0;
	}
  if(Cords[2].x == 240)
  {
    Cords[2].x =0;
  }

}

void render::movement()
{
  if(reach_counter == false && _buyer ==true)
  {
    Cords[3].x +=x*2;
    Cords[3].y +=y*2;
  }

  if(Cords[3].x <= -230 && Cords[3].y >=810)
  {
    _buyer = false ;
    Cords[3].x = 730 ; Cords[3].y = 810;
  }

  if(Cords[3].x == Cords[1].x )
  {
    reach_counter = true;
  }


}

void render::gui(int  a)
{
    stringstream strm;
    strm << a;
    SDL_Color textColor = {0, 0, 0, 0};

surface = TTF_RenderText_Solid(font,strm.str().c_str(), textColor);
if (!surface) {
    printf("Unable to render text surface! TTF_Error: %s\n", TTF_GetError());
    // Handle the error and clean up
}
textTexture = SDL_CreateTextureFromSurface(render, surface);
if (!textTexture) {
    printf("Unable to create texture from surface! SDL_Error: %s\n", SDL_GetError());
    // Handle the error and clean up
}

  // Obtain the draw list
  //    ImDrawList* draw_list = ImGui::GetForegroundDrawList();

  //    // Define the position where you want to draw the text
  //    ImVec2 text_pos = ImVec2(10, 10); // Example position, adjust as needed

  //    // Set text color (optional)
  //    ImU32 text_color = IM_COL32(0, 0, 0, 255); // White color with full opacity

  //    // Display the text
  //    draw_list->AddText(text_pos, text_color, &coin);
}
