#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
#include "Path.h"

#define MAX_ENEMIES 100

enum ENEMY_TYPES
{
	NO_TYPE,
	TORPEDO,
	METALLICBALLOON,
	TERRESTIALTURRET,
	CASTLE_HOUSEFLAG,

	POWER_UP
};

enum ENEMY_MOVEMENT
{
	NO_MOVEMENT,
	TORPEDO_DIAGONALL_R,
	TORPEDO_HORIZONTALR_L,
	TORPEDO_STRAIGHT_ON,
	BALLOON_PATH_CASTLE,
	TURRET_1_PATH,
	TURRET_2_PATH,
	TURRET_3_PATH,

	POWER_UP_MOVEMENT
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	ENEMY_MOVEMENT typeMovement = ENEMY_MOVEMENT::NO_MOVEMENT;
	int x, y;
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddEnemy(ENEMY_TYPES type, int x, int y, ENEMY_MOVEMENT typeMovement);

private:

	void SpawnEnemy(const EnemyInfo& info);

private:

	//paths (torpedo)
	Path diagonalPathL_R;
	Path horizontalPathR_L;
	Path strightOnPath;

	// path balloon
	Path balloonPathCastle;

	//paths terrestial turret
	Path turret1_path;
	Path turret2_path;
	Path turret3_path;

	//path power_up
	Path powerUpPath;


	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
};

#endif // __ModuleEnemies_H__