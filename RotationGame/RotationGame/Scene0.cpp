#include "Scene0.h"
#include <SDL.h>
#include <SDL_render.h>
#include <SDL_image.h>

Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
	playerSprite = nullptr;
}

Scene0::~Scene0(){
}

bool Scene0::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0, 200.0f, 0.0f, 100.0f,0.0f,1.0f);
	projection =  ndc * ortho;

	playerSprite = new Player(Vec3(50.0f, 30.0f, 0.0f), Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0), 100.0);
	playerSprite->thePlayer = IMG_Load("test.png");
	

	map = new MapOne;			// adding Map to OnCreate with position
	map->image = SDL_LoadBMP("mapone.bmp");

	if (map->image == nullptr) {
		return false;
	}

	map->position.x = 15.0f;
	map->position.y = 90.0f;
	map->position.z = 0.0f;
	
	return true;
}

void Scene0::OnDestroy() {
	delete map;
}

void Scene0::Update(const float time) {
	while (SDL_PollEvent(&Event)) {
		//player.HandleEvents(Event);
		playerSprite->HandleEvents(Event);
	}
	playerSprite->Update(time);
}

void Scene0::Render() {
	
	Vec3 screenCoords = projection * map->position;
	
	SDL_Rect rect;
	//SDL_Rect rect2;
	rect.h = map->image->h;
	rect.w = map->image->w;
	rect.x = screenCoords.x; 
	rect.y = screenCoords.y; 

	Vec3 screenCoords2 = projection * playerSprite->GetPosition();
	SDL_Rect spritePosition;
	spritePosition.h = playerSprite->thePlayer->h;
	spritePosition.w = playerSprite->thePlayer->w;
	spritePosition.x = screenCoords2.x;
	spritePosition.y = screenCoords2.y;

	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 255.0f,255.0f,255.0f));		//changed color to white from blue.

	SDL_BlitSurface(map->image, nullptr, screenSurface, &rect);

	SDL_BlitSurface(playerSprite->thePlayer, NULL, screenSurface, &spritePosition);
	
	SDL_UpdateWindowSurface(window);



}

void Scene0::HandleEvents(const SDL_Event & event)
{

}