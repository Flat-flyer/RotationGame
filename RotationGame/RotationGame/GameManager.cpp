#include "GameManager.h"
#include "Window.h"
#include "Timer.h"
#include "Scene0.h"
#include <iostream>

GameManager::GameManager() {
	timer = nullptr;
	isRunning = true;
	currentScene = nullptr;
}


/// In this OnCreate() method, fuction, subroutine, whatever the word, 
bool GameManager::OnCreate() {
	const int SCREEN_WIDTH = 780;
	const int SCREEN_HEIGHT = 400;
	ptr = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (ptr == nullptr) {
		OnDestroy();
		return false;
	}
	if (ptr->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	timer = new Timer();
	if (timer == nullptr) {
		OnDestroy();
		return false;
	}

	currentScene = new Scene0(ptr->GetSDL_Window());
	if (currentScene == nullptr) {
		OnDestroy();
		return false;
	}

	if (currentScene->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	return true;
}

/// Here's the whole game
void GameManager::Run() {
	timer->Start();
	while (isRunning) {
		timer->UpdateFrameTicks();
		HandleEvents();
		currentScene->Update(timer->GetDeltaTime());
		currentScene->Render();

		/// Keeep the event loop running at a proper rate
		SDL_Delay(timer->GetSleepTime(60)); ///60 frames per sec
	}
}

void GameManager::HandleEvents() {
	SDL_Event Event;
	while (SDL_PollEvent(&Event)){
		if (Event.type == SDL_QUIT) {
			isRunning = false;
		}
		if (Event.type == SDL_KEYDOWN) {
			if (Event.key.keysym.sym == SDLK_d) {
				currentScene->MoveState = 1;
			}
			if (Event.key.keysym.sym == SDLK_a) {
				currentScene->MoveState = 2;
			}
			if (Event.key.keysym.sym == SDLK_w) {
				currentScene->MoveState = 3;
			}
			if (Event.key.keysym.sym == SDLK_s) {
				currentScene->MoveState = 4;
			}
			if (Event.key.keysym.sym == SDLK_l) {
				currentScene->MoveState = 5;
			}
			if (Event.key.keysym.sym == SDLK_j) {
				currentScene->MoveState = 6;
			}
			if (Event.key.keysym.sym == SDLK_i) {
				currentScene->MoveState = 7;
			}
			if (Event.key.keysym.sym == SDLK_k) {
				currentScene->MoveState = 8;
			}
		}
		if (Event.type == SDL_KEYUP) {
			currentScene->MoveState = 0;
		}
		
	}

}

GameManager::~GameManager() {}

void GameManager::OnDestroy(){
	if (ptr) delete ptr;
	if (timer) delete timer;
	if (currentScene) delete currentScene;
}