//Jai Bajarangbali
//main.cpp
#include<iostream>
#include<SDL2/SDL.h>
#include"renderwindow.hpp"
#include"algorithm.hpp"
using namespace std;








// main function
int main()
{
	algos algo;
	algo.input_data();
	render graphic ; // Created a new object of class render
	SDL_Event e;// event to take inputs
	//string charac  ; // this to randomize which character will come t obuy stuff
	// although for now , we have only one , somebody help me write T T .
	int anime = 0;
	int fps = 1000/60; // to know how much millisecond should be spend in a frame
	int time = SDL_GetTicks() +fps ;
	if(graphic.Initialize() == true)// if sdl is initialized
	{
		graphic.setup();
		graphic.gui(algo.coins);
		while(true)//main game loop
		{
			if(SDL_PollEvent(&e))
      {
				 //ImGui_ImplSDL2_ProcessEvent(&e);
				if(e.type == SDL_QUIT)
				{
						break;
				}
			}

			//Until this part is basic ,Chill ujjwal !! You didn't fu@&*d up:)


			if (graphic._buyer == false ) // To check if buyer has come to buy something
			{
				if(algo.random(5,0) == 0)// TO randomize the coming of buyer
				{
					graphic.x = -1; graphic.y = -1;
				  graphic._buyer = true;
					algo.assign_random();// Assign random order of the buyer

				}
			}

			if(graphic._buyer == true)
			{
				if(graphic.reach_counter == true) // If the buyer has reached the counter to buy something
				{
					if(algo.order_check() == true) //  IF the shopkeeper has the plants , he wil buy and go
					{
						Mix_PlayChannel(-1, graphic.coin_sound, 0);
						graphic.y*=-1; // Iska mtlab ??? Are chodo yaar , Amul macho pehen ke nacho (0o0)!
						algo.order_refresh();// referesh the order size
						graphic.gui(algo.coins);
					}
					else {
						graphic.y*=-1;
						graphic.x*=-1;
						algo.order_refresh();

					}
					graphic.reach_counter = false; // After this  , the buyer will leave
				}
			}

			graphic.movement(); //To do the mo0vement of buyer

			if(time-SDL_GetTicks()<fps )
			{
				SDL_Delay(time-SDL_GetTicks());
				time = SDL_GetTicks() +fps ;
			}

			if(anime==15)
			{
				graphic.animation();
				anime = 0;
			}
			anime++;


			graphic.print();

		}
	}
	algo.output_data();
	graphic.Destroy();
	return 0;
}
