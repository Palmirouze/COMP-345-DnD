#include "Game.h"

#include "GUI/Screens/ScreenMain.h"
#include "GUI/Renderer.h"
#include <direct.h>
#include "GUI/Screens/ScreenTitle.h"
#include "Log.h"


#undef main

Game* Game::instance = nullptr;
Game::Game()
{
	gui_manager = new GuiManager();
}

bool Game::ini()
{
	_mkdir("maps/");
	_mkdir("characters/");
	_mkdir("items/");

	if (!Renderer::init())
		return false;

	//font color



	ScreenMain* titleScreen = new ScreenMain(this);

	gui_manager->setScreen(titleScreen);
	
	return true;

}

bool Game::run()
{
	bool running = true;

	//render loop
	while (running) //TODO: Add loop exit.
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{

			case SDL_MOUSEBUTTONUP:
				int x, y;

				SDL_GetMouseState(&x, &y);
				gui_manager->clickScreen(x, y);
				break;
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				gui_manager->keyPressed(event.key.keysym.sym);
				const Uint8 *state = SDL_GetKeyboardState(NULL);
				if (state[SDL_SCANCODE_LALT])
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_1:
						Log::instance()->toggle_Character();
						break;
					case SDLK_2:
						Log::instance()->toggle_Dice();
						break;
					case SDLK_3:
						Log::instance()->toggle_Game();
						break;
					case SDLK_4:
						Log::instance()->toggle_Map();
						break;
					case SDLK_z:
						gui_manager->toggleDebug();
						break;
					}
				
			
				}
				break;

			}
		}

		//logic here
		gui_manager->runTick();

		Renderer::iniRender();

		gui_manager->renderScreen();
		//render here

		Renderer::render();


		Renderer::destroyVoidedScreens();
	}

	return true;
}

bool Game::exit()
{
	Renderer::destroyRenderer();

	return true;
}

GuiManager* Game::getGuiManager()
{
	return gui_manager;
}

int main()
{
	Game* game = Game::getInstance();
	if(!game->ini())
	{
		std::cout << "Error initializing the game" << std::endl;
	}
	if(!game->run())
	{
		std::cout << "Error running the game" << std::endl;
	}
	if(!game->exit())
	{
		std::cout << "Error exiting the game" << std::endl;
	}

	//font location / bounds

	

	


}

Game* Game::getInstance()
{
	if (instance == nullptr)
		instance = new Game();

	return instance;
}
