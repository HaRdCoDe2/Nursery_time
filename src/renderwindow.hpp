//Jai Bajarangbali
//renderwindow.hpp
#pragma once
#include<SDL2/SDL.h>
#include<sstream>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_mixer.h>
#include<iostream>
//#include <imgui/imgui.h>
//#include <imgui/backends/imgui_impl_sdl2.h>
//#include <imgui/backends/imgui_impl_sdlrenderer2.h>
using namespace std;


struct render
{
	private:
		//Including all the nedessary members for class
		int width = 960 , height =540 ;
		SDL_Window *window ;
		SDL_Renderer *render ;
		SDL_Texture *back ;
		SDL_Texture *counter ;
		SDL_Texture *coinbox ;
		SDL_Texture *MC ;
		SDL_Texture *Cus ;
		SDL_Texture *textTexture;
		SDL_Surface *surface ;
		TTF_Font *font;
		Mix_Music *back_music ;
		SDL_Rect Cords[7] = {{0 , 0 , 60 , 80},{180 , 160 , 240 , 320},
											  	{0 , 0, 60 ,80},{730 , 810 , 240 , 320} ,
												  {0 ,30 , 60 , 20},	{10 , 10 , 150,50},
													{75,25 , 50 ,20}};

	public:
	  bool _buyer = false ;
		bool reach_counter = false ;
		 int x = -1 , y = -1 ;
		 Mix_Chunk *coin_sound ;
		bool Initialize(); // to see if sdl is initialize
		void setup(); // To load textures
		void print(); // To print textures on screen using render
		void Destroy(); // To Destroy SDL and SDL image , textures , renderer and window
		void animation();// To change th pixel art coordinated to animate it
		void movement(); // To move the player and the buyer
		void reset_buyer(); // To reset the position of buyer
		void gui(int a); // used to generate gui on the imgui window



};
