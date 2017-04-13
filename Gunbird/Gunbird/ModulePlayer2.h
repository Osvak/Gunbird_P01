#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer2 : public Module
{
private:
	unsigned short laserType;
	int original_camera_y;

	uint currentTime;
	uint lastTime;

public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation right_animation;
	Animation right_idle_animation;
	Animation left_idle_animation;
	Animation left_animation;
	Animation dead_animation;
	Animation dead_animation_explosion;
	Animation* current_animation;
	iPoint position;
	Collider* playerCollider;

	bool inmortal;
	int playerLives;
	bool deadPlayer;
	int counter = 0;
	bool control = false;
	bool playerLost;

};

#endif