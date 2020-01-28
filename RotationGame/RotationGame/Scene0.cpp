#include "Scene0.h"
#include <SDL.h>
#include <SDL_render.h>
#include <SDL_image.h>

Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;

}

Scene0::~Scene0(){
}

bool Scene0::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0, 200.0f, 0.0f, 100.0f,0.0f,1.0f);
	projection =  ndc * ortho;
	
	return true;
}

void Scene0::OnDestroy() {
}

void Scene0::Update(const float time) {
	while (SDL_PollEvent(&Event)) {
		player.HandleEvents(Event);
	}
	player.Update(time);
}

void Scene0::Render() {
	

	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 255.0f,255.0f,255.0f));		//changed color to white from blue.

	SDL_UpdateWindowSurface(window);



}

void Scene0::HandleEvents(const SDL_Event & event)
{

}