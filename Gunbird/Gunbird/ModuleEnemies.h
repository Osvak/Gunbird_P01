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
	CASTLE_HOUSEFLAG_2,
	CASTLE_VASE,
	
	COIN,
	POWER_UP
};

enum ENEMY_MOVEMENT
{
	NO_MOVEMENT,
	STAY,
	TORPEDO_DIAGONALL_R,
	TORPEDO_HORIZONTALR_L,
	TORPEDO_STRAIGHT_ON,
	TORPEDO_DIAGONAL_R_FINAL,
	TORPEDO_DIAGONAL_L_FINAL,
	TORPEDO_DIAGONAL_R_FINAL2,
	TORPEDO_DIAGONAL_L_FINAL2,
	BALLOON_PATH_CASTLE,
	TURRET_1_PATH,
	TURRET1_L_PATH,
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

	//path stay
	Path stayPath;

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
	Path diagonalPath_R_Final;
	Path diagonalPath_L_Final;
	Path diagonalPath_R_Final2;
	Path diagonalPath_L_Final2;
	// path balloon
	Path balloonPathCastle;

	//paths terrestial turret
	Path turret1_path;
	Path turret1_L_path;
	Path turret2_path;
	Path turret3_path;

	//path power_up
	Path powerUpPath;


	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
};

#endif // __ModuleEnemies_H__