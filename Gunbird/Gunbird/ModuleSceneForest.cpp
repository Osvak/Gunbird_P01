#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleSceneForest.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModuleScoreRanking.h"
#include "ModuleUI.h"
#include "SDL\include\SDL_timer.h"

//TODO: remove this if not necesary
#include "ModuleInput.h"


ModuleSceneForest::ModuleSceneForest()
{
	background_speed = 0.5f;
	// Background
	background.w = SCREEN_WIDTH;
	background.h = 1717;


	/*soldier_left_wall.loop = true;
	soldier_left_wall.PushBack({ 533, 373, 13, 26 });
	soldier_left_wall.PushBack({ 550, 373, 13, 26 });
	soldier_left_wall.PushBack({ 566, 373, 13, 26 });
	soldier_left_wall.PushBack({ 582, 373, 13, 26 });
	soldier_left_wall.speed = 0.06f;
	soldier_left_wall_y = -145;
	soldier_left_wall_x = 50;*/

}

ModuleSceneForest::~ModuleSceneForest()
{}

// Load assets
bool ModuleSceneForest::Start()
{
	spawned = 0;
	//setting bckground
	background_x = 0;
	background_y = -1717.0f;
	//EXAMPLE
	/*soldier_left_wall_y = -145;
	soldier_left_wall_x = 50;
	soldier_left_wall.Reset();*/



	LOG("Loading SceneForest assets");
	bool ret = true;
	

	App->player->Enable();
	App->ui->Enable();

	if (App->player2->playerLives > 0 && App->ui->p2 == true)
		App->player2->Enable();

	App->collision->Enable();
	App->enemies->Enable();
	App->particles->Enable();

	graphics = App->textures->Load("Assets/maps/forest/map_forest_background.png");
	if (graphics == nullptr) {
		LOG("Cannot load the texture in SceneForest");
		ret = false;
	}

	//EXAMPLE:
	/*graphicsSoldier = App->textures->Load("Assets/maps/castle/castle_map_stuff.png");
	if (graphicsSoldier == nullptr) {
		LOG("Cannot load the animations spritesheet in SceneCastle");
		ret = false;
	}*/

	if (!App->audio->PlayMusic("Assets/audio/gunbird_jungle_level_music.ogg"))
		ret = false;

	LOG("Loading audio fx when player 2 joins the game");
	player2joined = App->audio->LoadFx("Assets/audio/effects/Valnus_Start.wav");

	return ret;
}

// Update: draw background
update_status ModuleSceneForest::Update()
{

	update_status status = UPDATE_CONTINUE;

	if (background_y < -SCREEN_HEIGHT) {
		background_y += background_speed;
		//EXAMPLE:
		//soldier_left_y += background_speed;
	}

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics, (int)background_x, (int)background_y + SCREEN_HEIGHT, &background, 0.75f)) {
		LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	//BACKGROUND ANIMATIONS
	{
		//soldier animations EXAMPLE
		/*if (background_y <= -1800.0f && soldier_left_x >= -12 && graphicsSoldier != nullptr) {
			if (!App->render->Blit(graphicsSoldier, (int)soldier_left_x, (int)soldier_left_y + SCREEN_HEIGHT, &(soldier_left.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			if (!App->render->Blit(graphicsSoldier, (int)soldier_left_x - 6, (int)soldier_left_y + SCREEN_HEIGHT + 20, &(soldier_left.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneCastle %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			soldier_left_x -= 0.4f;
		}*/
		
	}

	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN && App->sceneForest->IsEnabled())
	{
		//DO UNLOAD OF ALL THE TEXTURES ABOUT ANIM IN BACKGROUND LIKE SOLDIERS ETC
		//EXAMPLE:
		/*if (!App->textures->Unload(graphicsSoldier)) {
			LOG("Error unloading graphics in SceneCastle");
			status = UPDATE_ERROR;
		}
		graphicsSoldier = nullptr;
		*/
		App->enemies->Disable();
		App->particles->Disable();
		background_y = -SCREEN_HEIGHT;
	}


	//TODO change the position of the player to private to be more pro
	if (App->player->position.y < 0 && App->fade->FadeIsOver())
		App->fade->FadeToBlack(this, this, 1.0f);

	if (App->player->playerLost) {
		LOG("Player LOST");
		App->fade->FadeToBlack(this, App->scoreRanking);
	}

	if (App->player2->playerLost) {
		LOG("Player2 LOST");
		App->ui->p2 = false;
		App->player2->Disable();
	}

	//ENEMY SPAWN PHASE
	/*
	{

		if ((int)background_y == -2000 && spawned == 0) {
			spawned = 1;
			App->enemies->AddEnemy(ENEMY_TYPES::CASTLE_HOUSEFLAG, 149, -275, ENEMY_MOVEMENT::STAY);
		}

		if ((int)background_y == -1950 && spawned == 1)
		{
			spawned = 2;
			App->enemies->AddEnemy(ENEMY_TYPES::METALLICBALLOON, 112, -70, ENEMY_MOVEMENT::BALLOON_PATH_CASTLE);
		}

		if ((int)background_y == -1840 && spawned == 2) {
			spawned = 3;
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, -25, -50, ENEMY_MOVEMENT::TURRET_1_PATH);
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, -25, -15, ENEMY_MOVEMENT::TURRET_2_PATH);
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, -25, 15, ENEMY_MOVEMENT::TURRET_3_PATH);
		}


		if ((int)background_y == -1800 && spawned == 3) {
			spawned = 4;
			App->enemies->AddEnemy(ENEMY_TYPES::CASTLE_HOUSEFLAG_2, 78, -340, ENEMY_MOVEMENT::STAY);

		}

		if ((int)background_y == -1780 && spawned == 4) {
			spawned = 5;
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, -30, -32, ENEMY_MOVEMENT::TORPEDO_DIAGONALL_R);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, -60, -64, ENEMY_MOVEMENT::TORPEDO_DIAGONALL_R);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, -90, -96, ENEMY_MOVEMENT::TORPEDO_DIAGONALL_R);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, -120, -128, ENEMY_MOVEMENT::TORPEDO_DIAGONALL_R);
		}


		if ((int)background_y == -1500 && spawned == 5) {
			spawned = 6;


			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, SCREEN_WIDTH - 10, -45, ENEMY_MOVEMENT::TURRET1_L_PATH);
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, SCREEN_WIDTH - 30, -85, ENEMY_MOVEMENT::TURRET1_L_PATH);

			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, 15, -45, ENEMY_MOVEMENT::STAY);
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, -2, -85, ENEMY_MOVEMENT::TURRET_1_PATH);

			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, 40, -375, ENEMY_MOVEMENT::STAY);
			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, 170, -375, ENEMY_MOVEMENT::STAY);

			App->enemies->AddEnemy(ENEMY_TYPES::TERRESTIALTURRET, SCREEN_WIDTH - 40, -475, ENEMY_MOVEMENT::STAY);

			App->enemies->AddEnemy(ENEMY_TYPES::CASTLE_VASE, 10, -135, ENEMY_MOVEMENT::STAY);
			App->enemies->AddEnemy(ENEMY_TYPES::CASTLE_VASE, 185, -135, ENEMY_MOVEMENT::STAY);

			App->enemies->AddEnemy(ENEMY_TYPES::CASTLE_VASE, 8, -345, ENEMY_MOVEMENT::STAY);
			App->enemies->AddEnemy(ENEMY_TYPES::CASTLE_VASE, 185, -348, ENEMY_MOVEMENT::STAY);

		}

		if ((int)background_y == -1300 && spawned == 6) {
			spawned = 7;
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 30, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 60, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 90, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 120, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 150, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, SCREEN_WIDTH + 180, 70, ENEMY_MOVEMENT::TORPEDO_HORIZONTALR_L);

		}

		if ((int)background_y == -1050 && spawned == 7) {
			spawned = 8;
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 70, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 120, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);

			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 10, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 50, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 140, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 180, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
		}
		if ((int)background_y == -1025 && spawned == 8) {
			spawned = 9;
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 10, -32, ENEMY_MOVEMENT::TORPEDO_DIAGONAL_L_FINAL);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 50, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 140, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 180, -32, ENEMY_MOVEMENT::TORPEDO_DIAGONAL_R_FINAL);

			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 70, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 120, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 112, -122, ENEMY_MOVEMENT::TORPEDO_DIAGONAL_R_FINAL);
		}

		if ((int)background_y == -900 && spawned == 9) {
			spawned = 10;
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 70, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 120, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);

			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 10, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 50, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 140, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 180, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
		}
		if ((int)background_y == -875 && spawned == 10) {
			spawned = 11;
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 10, -32, ENEMY_MOVEMENT::TORPEDO_DIAGONAL_L_FINAL2);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 50, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 140, -32, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 180, -32, ENEMY_MOVEMENT::TORPEDO_DIAGONAL_R_FINAL2);

			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 70, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 120, -122, ENEMY_MOVEMENT::TORPEDO_STRAIGHT_ON);
			App->enemies->AddEnemy(ENEMY_TYPES::TORPEDO, 112, -122, ENEMY_MOVEMENT::TORPEDO_DIAGONAL_L_FINAL2);
		}
	}
	*/

	if (App->input->keyboard[SDL_SCANCODE_KP_1] && !App->player2->IsEnabled()) {
		App->ui->p2 = true;
		App->player2->playerLives = 3;
		App->player2->Enable();
		App->audio->PlayFx(player2joined);
	}

	/*if (App->input->keyboard[SDL_SCANCODE_F9] == KEY_STATE::KEY_DOWN)
	{
	App->enemies->AddEnemy(ENEMY_TYPES::METALLICBALLOON, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, ENEMY_MOVEMENT::STAY);
	}*/

	return status;
}


bool ModuleSceneForest::CleanUp()
{
	LOG("Unloading SceneForest");

	bool ret = true;

	if (!App->textures->Unload(graphics)) {
		LOG("Error unloading graphics in SceneForest");
		ret = false;
	}
	
	App->collision->Disable();
	App->particles->Disable();
	App->enemies->Disable();
	App->ui->Disable();
	App->player->Disable();
	App->player2->Disable();

	return ret;
}