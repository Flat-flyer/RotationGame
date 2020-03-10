#include "Scene0.h"
#include <SDL.h>
#include <SDL_render.h>
#include <SDL_image.h>

Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
	playerSprite = nullptr;
	mRender = nullptr;
	
}

Scene0::~Scene0(){
}

bool Scene0::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0, 200.0f, 0.0f, 100.0f,0.0f,1.0f);
	projection =  ndc * ortho;

	playerSprite = new Player(Vec3(100.0f, 50.0f, 0.0f), Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0), 100.0);
	playerSprite->thePlayer = IMG_Load("test.png");
	

	tile = new Tile(Vec3(15.0f, 90.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(100.0f, 50.0f, 0.0f), 1.0f, 0.0f, 0.0f);			// adding Map to OnCreate with position
	tile->image = SDL_LoadBMP("mapone.bmp");

	if (tile->image == nullptr) {
		return false;
	}
	tile->height = 100.0f;
	tile->width = 100.0f;

	tile->RotateObject = true;

	
	return true;
}

void Scene0::OnDestroy() {
	delete tile;
}

void Scene0::Update(const float time) {
	
		//player.HandleEvents(Event);
		playerSprite->Update(time);
		tile->Update(time);
}

void Scene0::Render() {
	
	Vec3 screenCoords = projection * tile->GetPosition();
	
	SDL_Rect rect;
	//SDL_Rect rect2;
	rect.h = tile->image->h;
	rect.w = tile->image->w;
	rect.x = screenCoords.x; 
	rect.y = screenCoords.y; 
	if (clip != NULL)
	{
		rect.w = clip->w;
		rect.h = clip->h;
	}
	Vec3 screenCoords2 = projection * playerSprite->GetPosition();
	SDL_Rect spritePosition;
	spritePosition.h = playerSprite->thePlayer->h;
	spritePosition.w = playerSprite->thePlayer->w;
	spritePosition.x = screenCoords2.x;
	spritePosition.y = screenCoords2.y;

	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 255.0f,255.0f,255.0f));		//changed color to white from blue.

	SDL_BlitSurface(tile->image, nullptr, screenSurface, &rect);
	SDL_RenderCopyEx(mRender, mTexture, clip, &rect,playerSprite->degrees1 , NULL, SDL_FLIP_NONE);
	SDL_BlitSurface(playerSprite->thePlayer, NULL, screenSurface, &spritePosition);
	SDL_RenderPresent(mRender);
	SDL_UpdateWindowSurface(window);



}

void Scene0::HandleEvents(const SDL_Event & event)
{
	playerSprite->HandleEvents(event);
}