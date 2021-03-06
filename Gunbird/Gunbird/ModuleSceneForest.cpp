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
#include "ModuleSceneCastle.h"
#include "ModuleCharacterSelection.h"
#include "SDL\include\SDL_timer.h"

//TODO: remove this if not necesary
#include "ModuleInput.h"

ModuleSceneForest::ModuleSceneForest()
{
	background_speed = 0.5f;
	// Background
	background.w = SCREEN_WIDTH;
	background.h = 2800;
	m_trees.w = SCREEN_WIDTH;
	m_trees.h = 2800;


	//motion trees
	motion_trees_1.x = 23;
	motion_trees_1.y = 42;
	motion_trees_1.w = 129;
	motion_trees_1.h = 174;

	motion_trees_2.x = 219;
	motion_trees_2.y = 38;
	motion_trees_2.w = 88;
	motion_trees_2.h = 175;
	
	motion_trees_3.x = 25;
	motion_trees_3.y = 245;
	motion_trees_3.w = 188;
	motion_trees_3.h = 381;

	motion_trees_4.x = 24;
	motion_trees_4.y = 678;
	motion_trees_4.w = 130;
	motion_trees_4.h = 174;

	motion_trees_5.x = 263;
	motion_trees_5.y = 254;
	motion_trees_5.w = 178;
	motion_trees_5.h = 184;

	motion_trees_6.x = 401;
	motion_trees_6.y = 784;
	motion_trees_6.w = 126;
	motion_trees_6.h = 173;

	motion_trees_7.x = 870;
	motion_trees_7.y = 623;
	motion_trees_7.w = 144;
	motion_trees_7.h = 335;

	motion_trees_8.x = 401;
	motion_trees_8.y = 784;
	motion_trees_8.w = 126;
	motion_trees_8.h = 173;


	//trump figures
	{
		trump_spikyHair1.PushBack({ 318, 325, 13, 24 });
		trump_spikyHair1.PushBack({ 336, 325, 13, 23 });
		trump_spikyHair1.loop = true;
		trump_spikyHair1.speed = 0.05f;

		//trump_spikyHair2.PushBack({ 354, 325, 12, 24 });
		trump_spikyHair2.PushBack({ 318, 243, 15, 23 });
		trump_spikyHair2.PushBack({ 338, 243, 14, 22 });
		trump_spikyHair2.PushBack({ 357, 243, 15, 23 });
		trump_spikyHair2.PushBack({ 377, 243, 14, 22 });
		trump_spikyHair2.loop = true;
		trump_spikyHair2.speed = 0.05f;

		trumphat1.PushBack({ 233, 328, 16, 27 });
		trumphat1.PushBack({ 253, 328, 16, 27 });
		trumphat1.loop = true;
		trumphat1.speed = 0.05f;

		//trumpHat2.PushBack({ 269, 328, 16, 27 });
		trumpHat2.PushBack({ 232, 242, 16, 27 });
		trumpHat2.PushBack({ 252, 242, 16, 27 });
		trumpHat2.PushBack({ 270, 243, 16, 27 });
		trumpHat2.PushBack({ 291, 242, 16, 27 });
		trumpHat2.loop = true;
		trumpHat2.speed = 0.05f;
	}


	// miner
	miner_down.PushBack({ 17, 13, 15, 23 });
	miner_down.PushBack({ 215, 13, 15, 23 });
	miner_down.PushBack({ 238, 13, 15, 23 });
	miner_down.PushBack({ 259, 13, 15, 23 });
	miner_down.speed = 0.05f;
	miner_down.loop = true;

	miner_up.PushBack({ 17, 125, 15, 23 });
	miner_up.PushBack({ 39, 125, 15, 23 });
	miner_up.PushBack({ 63, 125, 15, 23 });
	miner_up.PushBack({ 86, 125, 15, 23 });
	miner_up.speed = 0.02f;
	miner_up.loop = true;

	miner_rigth.PushBack({ 68, 50, 11, 22 });
	miner_rigth.PushBack({ 93, 50, 11, 23 });
	miner_rigth.PushBack({ 117, 50, 12, 22 });
	miner_rigth.PushBack({ 19, 88, 11, 23 });
	miner_rigth.speed = 0.05f;
	miner_rigth.loop = true;

	miner_dright_down.PushBack({ 15, 164, 16, 23 });
	miner_dright_down.PushBack({ 41, 164, 16, 23 });
	miner_dright_down.PushBack({ 67, 164, 16, 23 });
	miner_dright_down.speed = 0.05f;
	miner_dright_down.loop = true;

	miner_drigth.PushBack({ 176, 12, 15, 23 });
	miner_drigth.PushBack({ 176, 43, 15, 23 });
	miner_drigth.PushBack({ 176, 76, 15, 23 });
	miner_drigth.PushBack({ 176, 112, 15, 23 });
	miner_drigth.PushBack({ 176, 146, 15, 23 });
	miner_drigth.speed = 0.05f;
	miner_drigth.loop = true;

	miner_dleft.PushBack({ 154, 12, 15, 23 });
	miner_dleft.PushBack({ 154, 43, 15, 23 });
	miner_dleft.PushBack({ 154, 76, 15, 23 });
	miner_dleft.PushBack({ 154, 112, 15, 23 });
	miner_dleft.PushBack({ 154, 146, 15, 23 });
	miner_dleft.speed = 0.05f;
	miner_dleft.loop = true;

	brokenMecha.PushBack({23, 216, 71, 77});
	brokenMecha.speed = 0.05f;
	brokenMecha.loop = true;

	beamRight.PushBack({ 16, 333, 174, 23 });
	beamRight.speed = 0.05f;
	beamRight.loop = true;

	beamLeft.PushBack({ 16, 361, 174, 23 });
	beamLeft.speed = 0.05f;
	beamLeft.loop = true;

	shadowBeam.PushBack({ 16, 399, 174, 23 });
	shadowBeam.speed = 0.05f;
	shadowBeam.loop = true;

	goldMachine.PushBack({ 29,1357,91,76 });
	goldMachine.PushBack({ 131,1375,91,76 });
	goldMachine.PushBack({ 226,1375,91,76 });
	goldMachine.PushBack({ 322,1375,91,76 });
	goldMachine.PushBack({ 420,1375,91,76 });
	goldMachine.PushBack({ 512,1375,91,76 });
	goldMachine.PushBack({ 612,1375,91,76 });
	goldMachine.PushBack({ 38,1493,91,76 });
	goldMachine.PushBack({ 146,1493,91,76 });
	goldMachine.PushBack({ 263,1493,91,76 });
	goldMachine.PushBack({ 370,1493,91,76 });
	goldMachine.loop = true;
	goldMachine.speed = 0.1f;

}

ModuleSceneForest::~ModuleSceneForest()
{}

// Load assets
bool ModuleSceneForest::Start()
{
	background_speed = 0.5f;
	spawned = 0;
	//setting bckground
	background_x = 0;
	background_y = -2800.0f;
	f5Pressed = false;

	//EXAMPLE
	/*soldier_left_wall_y = -145;
	soldier_left_wall_x = 50;
	soldier_left_wall.Reset();*/

	miner_up_y = 0.0f;
	beam_y = 0.0f;
	miner_brokenMecha_y = 0.0f;
	miner_down_y = 0.0f;
	miner_right_x = 0.0f;
	trump_y = 0.0f;
	trump_x = 0.0f;

	motion_trees_1_x = 96;
	motion_trees_1_y = -526.0f;

	motion_trees_2_x = 0;
	motion_trees_2_y = -665.0f;

	motion_trees_3_x = 39;
	motion_trees_3_y = -850.0f;

	motion_trees_4_x = 0;
	motion_trees_4_y = -808.0f;

	motion_trees_5_x = 0;
	motion_trees_5_y = 0;

	motion_trees_6_x = 0;
	motion_trees_6_y = -1125.0f;

	motion_trees_7_x = 82;
	motion_trees_7_y = -1285.0f;

	motion_trees_8_x = 0;
	motion_trees_8_y = -1298.0f;


	LOG("Loading SceneForest assets");
	bool ret = true;

	if(App->characterSelection->characterSelected_P1 != CHARACTER_SELECTED::NONE_SELECTED && App->characterSelection->characterSelected_P2 != CHARACTER_SELECTED::NONE_SELECTED)
		App->ui->p2 = true;

	
	// ENABLING SELECTED CHARACTER

	if (App->characterSelection->characterSelected_P1 == CHARACTER_SELECTED::VALNUS_SELECTED)
	{
		App->player->Enable();
		App->ui->Enable();
	}
	else if (App->characterSelection->characterSelected_P1 == CHARACTER_SELECTED::TETSU_SELECTED)
	{
		App->player2->Enable();
		App->ui->Enable();
	}

	if (App->characterSelection->characterSelected_P2 == CHARACTER_SELECTED::VALNUS_SELECTED)
	{
		App->player->Enable();
		App->ui->Enable();
	}
	else if (App->characterSelection->characterSelected_P2 == CHARACTER_SELECTED::TETSU_SELECTED)
	{
		App->player2->Enable();
		App->ui->Enable();
	}

	if (App->player2->playerLives > 0 && App->ui->p2 == true)
		App->player2->Enable();

	App->collision->Enable();
	App->enemies->Enable();
	App->particles->Enable();

	graphics = App->textures->Load("Assets/maps/forest/map_forest_background_.png");
	motionless_trees = App->textures->Load("Assets/maps/forest/Motionless_Trees.png");
	graphic_miner = App->textures->Load("Assets/maps/forest/Forest_stuff.png");
	motion_trees = App->textures->Load("Assets/maps/forest/Motion_trees.png");
	bossForest = App->textures->Load("Assets/enemies/enemies_definitive.png");

	if (graphics == nullptr ||motionless_trees == nullptr) {
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
	App->characterSelection->selected_P2_done = false;
	//App->characterSelection->characterSelected_P2 = CHARACTER_SELECTED::NONE_SELECTED;

	update_status status = UPDATE_CONTINUE;

	if (background_y < -SCREEN_HEIGHT) {
		background_y += background_speed;
	}

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics, (int)background_x, (int)background_y + SCREEN_HEIGHT, &background, 0.75f)) {
		LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}


	if (background_y >= -2400.0f && graphic_miner != nullptr)
	{
		if (!App->render->Blit(graphic_miner, (int)115, -25 + beamShadow_y, &(shadowBeam.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}

		if (!App->render->Blit(graphic_miner, (int)-47, -111 + beamShadow_y, &(shadowBeam.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}

		if (!App->render->Blit(graphic_miner, (int)-47, -186 + beamShadow_y, &(shadowBeam.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}

		if (!App->render->Blit(graphic_miner, (int)-47, -246 + beamShadow_y, &(shadowBeam.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}

		if (!App->render->Blit(graphic_miner, (int)-47, -346 + beamShadow_y, &(shadowBeam.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}

		if (!App->render->Blit(graphic_miner, (int)97, -416 + beamShadow_y, &(shadowBeam.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}


		if (background_y < -1850.0f && graphic_miner != nullptr)
		{

			if (!App->render->Blit(graphic_miner, (int)115, -416 + beamShadow_y, &(trumphat1.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			if (!App->render->Blit(graphic_miner, (int)100, -416 + beamShadow_y, &(trump_spikyHair1.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
		}
		else
		{
			if (!App->render->Blit(graphic_miner, (int)115 + trump_x, -416 + beamShadow_y - trump_y, &(trumpHat2.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			if (!App->render->Blit(graphic_miner, (int)100 + trump_x, -416 + beamShadow_y - trump_y, &(trump_spikyHair2.GetCurrentFrame()), 0.75f)) {
				LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			trump_y -= -0.3f;
			trump_x += 0.25f; 
		}
	}

	if (background_y >= -2400.0f) {
		beamShadow_y -= -0.5f;
	}

	if (background_y >= -1550.0f)
		trump_x += 270;


	



	if (background_y >= -2350.0 && graphic_miner != nullptr) {
		if (!App->render->Blit(graphic_miner, (int)190, (int)160 + miner_up_y, &(miner_up.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		if (!App->render->Blit(graphic_miner, (int)150, (int)160 + miner_up_y, &(miner_up.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		if (!App->render->Blit(graphic_miner, (int)170, (int)140 + miner_up_y, &(miner_up.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		if (!App->render->Blit(graphic_miner, (int)120, (int)140 + miner_up_y, &(miner_up.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		if (!App->render->Blit(graphic_miner, (int)140, (int)120 + miner_up_y, &(miner_up.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
		if (background_y >= -2130.0) {
			miner_up_y -= -0.5f;
		}
	}

	if (background_y >= -2200.0f && graphic_miner != nullptr)
	{
		
		if (!App->render->Blit(graphic_miner, (int)50, (int)-95 + miner_up_y, &(brokenMecha.GetCurrentFrame()), 0.75f))
		{
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}

		if (background_y < -2050.0f && graphic_miner != nullptr)
		{
			if (!App->render->Blit(graphic_miner, (int)72, (int)-110 + miner_brokenMecha_y, &(miner_up.GetCurrentFrame()), 0.75f))
			{
				LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}

			if (!App->render->Blit(graphic_miner, (int)55, (int)-120 + miner_brokenMecha_y, &(miner_dleft.GetCurrentFrame()), 0.75f))
			{
				LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}

			if (!App->render->Blit(graphic_miner, (int)87, (int)-110 + miner_brokenMecha_y, &(miner_drigth.GetCurrentFrame()), 0.75f))
			{
				LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}

			if (!App->render->Blit(graphic_miner, (int)103, (int)-120 + miner_brokenMecha_y, &(miner_drigth.GetCurrentFrame()), 0.75f))
			{
				LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
		}
		else
		{
			if (!App->render->Blit(graphic_miner, (int)72, (int)-110 + miner_brokenMecha_y + miner_down_y, &(miner_down.GetCurrentFrame()), 0.75f))
			{
				LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}

			if (!App->render->Blit(graphic_miner, (int)55, (int)-120 + miner_brokenMecha_y + miner_down_y, &(miner_down.GetCurrentFrame()), 0.75f))
			{
				LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			////
			if (!App->render->Blit(graphic_miner, (int)87 + miner_dright_x, (int)-110 + miner_brokenMecha_y + miner_dright_y, &(miner_dright_down.GetCurrentFrame()), 0.75f))
			{
				LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}
			////
			if (!App->render->Blit(graphic_miner, (int)103 + miner_right_x, (int)-120 + miner_brokenMecha_y, &(miner_rigth.GetCurrentFrame()), 0.75f))
			{
				LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
				status = UPDATE_ERROR;
			}

			if (background_y >= -2050.0f) 
				miner_down_y -= -0.65f;

			if (background_y >= -2050.0f)
				miner_right_x += 0.65f;

			if (background_y >= -2050.0f)
				miner_dright_x += 0.45;

			if (background_y >= -2050.0f)
				miner_dright_y += 0.45;

		}

		if (background_y >= -2200.0f) {
			miner_brokenMecha_y -= -0.5f;
		}
	}



	if (background_y >= -2360.0f && graphic_miner != nullptr)
	{
		//BEAMS
		if (!App->render->Blit(graphic_miner, (int)100, -19 + beam_y, &(beamRight.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}

		if (!App->render->Blit(graphic_miner, (int)-62, -105 + beam_y, &(beamRight.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}

		if (!App->render->Blit(graphic_miner, (int)-62, -180 + beam_y, &(beamLeft.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}

		if (!App->render->Blit(graphic_miner, (int)-62, -240 + beam_y, &(beamLeft.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}

		if (!App->render->Blit(graphic_miner, (int)-62, -340 + beam_y, &(beamLeft.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}

		if (!App->render->Blit(graphic_miner, (int)112, -410 + beam_y, &(beamLeft.GetCurrentFrame()), 0.75f)) {
			LOG("Cannot blit the texture in SceneForest %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}
	
	if (background_y >= -2360.0f) {
		beam_y -= -0.5f; 
	}


	//motion trees

	if (motion_trees != nullptr)
	{
		if (!App->render->Blit(motion_trees, (int)0 + motion_trees_4_x, (int)0 + motion_trees_4_y, &motion_trees_4, 0.75f)) {
			LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}
	

	if (background_y >= -2800.0f) {
		motion_trees_4_y -= -0.5f;
	}
	if (background_y >= -2100.0f && background_y <= -1990.0f) {
		motion_trees_4_x -= 0.5f;
	}

	if (motion_trees != nullptr)
	{
		if (!App->render->Blit(motion_trees, (int)0 + motion_trees_2_x, (int)0 + motion_trees_2_y, &motion_trees_2, 0.75f)) {
			LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}
	
	if (background_y >= -2800.0f) {
		motion_trees_2_y -= -0.5f;
	}
	if (background_y >= -2200.0f && background_y <= 2190.0f) {
		motion_trees_2_x -= 0.5f;
	}

	if (motion_trees != nullptr)
	{
		if (!App->render->Blit(motion_trees, (int)0 + motion_trees_3_x, (int)0 + motion_trees_3_y, &motion_trees_3, 0.75f)) {
			LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}
	

	if (background_y >= -2800.0f) {
		motion_trees_3_y -= -0.5f;
	}
	if (background_y >= -1990.0f && background_y <= -1910.0f) {
		motion_trees_3_x += 0.5f;
	}

	if (motion_trees != nullptr)
	{
		if (!App->render->Blit(motion_trees, (int)0 + motion_trees_1_x, (int)0 + motion_trees_1_y, &motion_trees_1, 0.75f)) {
			LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}

	if (background_y >= -2800.0f) {
		motion_trees_1_y -= -0.5f;
	}
	if (background_y >= -2360.0f && background_y <= 2300.0f) {
		motion_trees_1_x += 0.5f;
	}

	/*if (!App->render->Blit(motion_trees, (int)0 + motion_trees_8_x, (int)0 + motion_trees_8_y, &motion_trees_8, 0.75f)) {
		LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}*/


	/////////////BOSS????

	if ((int)background_y == -1525 && !App->enemies->bossDestroyed)
	{
		background_speed = 0.0f;
	}


	/*if (background_y >= -2800.0f) {
		if (background_speed == 0.0f)
			motion_trees_8_y = 0.0f;
		else
			motion_trees_8_y -= -0.5f;
	}
	if (background_speed == 0/*background_y >= -1525.0f && background_y <= -1435.0f) {
		motion_trees_8_x -= 0.5f;
	}*/

	/*if (background_y >= -2800.0f) {
		if (background_speed == 0.0f)
			motion_trees_6_y = 0.0f;
		else
			motion_trees_6_y -= -0.5f;
	}
	if (background_speed == 0/*background_y >= -1525.0f && background_y <= -1435.0f) {
		motion_trees_6_x -= 0.5f;
	}*/

	/*if (!App->render->Blit(motion_trees, (int)0 + motion_trees_6_x, (int)0 + motion_trees_6_y, &motion_trees_6, 0.75f)) {
		LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}//6*/

	/*if (!App->render->Blit(motion_trees, (int)0 + motion_trees_7_x, (int)0 + motion_trees_7_y, &motion_trees_7, 0.75f)) {
		LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	if (background_y >= -2800.0f) {
		if (background_speed == 0.0f)
			motion_trees_7_y = 0.0f;
		else
			motion_trees_7_y -= -0.5f;
	}
	

	if (background_speed == 0/*background_y >= -1525.0f && background_y <= -1435.0f) {
		motion_trees_7_x += 0.5f;
	}*/

	if (motionless_trees != nullptr)
	{
		if (!App->render->Blit(motionless_trees, (int)background_x, (int)background_y + SCREEN_HEIGHT, &m_trees, 0.75f)) {
			LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
			status = UPDATE_ERROR;
		}
	}
		

		
		if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN && App->sceneForest->IsEnabled())
		{
			App->enemies->Disable();
			App->particles->Disable();
			background_y = -SCREEN_HEIGHT;
			App->enemies->bossDestroyed = true;
		}

		if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN && App->sceneForest->IsEnabled() && !f5Pressed)
		{
			App->enemies->Disable();
			App->particles->Disable();

			if (graphic_miner != nullptr)
			{
				App->textures->Unload(graphic_miner);
				graphic_miner = nullptr;
			}

			if (motion_trees != nullptr)
			{
				App->textures->Unload(motion_trees);
				motion_trees = nullptr;
			}

			if (motionless_trees != nullptr)
			{
				App->textures->Unload(motionless_trees);
				motionless_trees = nullptr;
			}
			f5Pressed = true;
			background_y = -1740.0f;
			App->enemies->Enable();
			App->particles->Enable();
			App->enemies->AddEnemy(ENEMY_TYPES::FOREST_BOSS_HAND, 121, -62, ENEMY_MOVEMENT::BOSS_FOREST_HAND);
			App->enemies->AddEnemy(ENEMY_TYPES::FOREST_BOSS_HAND, 66, -62, ENEMY_MOVEMENT::BOSS_FOREST_HAND);
			App->enemies->AddEnemy(ENEMY_TYPES::BOSS_FOREST, 19, -170, ENEMY_MOVEMENT::BOSS_FOREST_HAND);

			if (bossForest != nullptr)
			{
				if (!App->render->Blit(bossForest, (int)121, 59, &(goldMachine.GetCurrentFrame()), 0.75f)) {
					LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
					status = UPDATE_ERROR;
				}
			}
		}


		//TODO change the position of the player to private to be more pro
		if ((App->player2->position.y < 0 || App->player->position.y < 0) && App->fade->FadeIsOver() && App->enemies->bossDestroyed) {
			App->fade->FadeToBlack(this, App->sceneCastle, 1.0f);
			
		}

		if (App->player->playerLost) {
			LOG("Player LOST");
			if(!App->player2->IsEnabled())
				App->fade->FadeToBlack(this, App->scoreRanking);
		}

		if (App->player2->playerLost) {
			LOG("Player2 LOST");
			App->ui->p2 = false;
			App->player2->Disable();
		}

		//ENEMY SPAWN PHASE 

		{
			//bee
			if ((int)background_y == -2799 && spawned == 0) {

				App->enemies->AddEnemy(ENEMY_TYPES::FOREST_HOUSE, 100, 30, ENEMY_MOVEMENT::STAY);
			}
			
				if ((int)background_y == -2710 && spawned == 0) {
					
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, -10, -10, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, SCREEN_WIDTH, -20, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH);

				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 50, -30, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, SCREEN_WIDTH / 2 + 30, -29, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH2);

				}

			if ((int)background_y == -2780 && spawned == 0) {
				App->enemies->AddEnemy(ENEMY_TYPES::FOREST_HOUSE, -40, -240, ENEMY_MOVEMENT::STAY);

			}

			//big red turret + bee
			if ((int)background_y == -2760 && spawned == 0)
			{
				spawned = 1;
				App->enemies->AddEnemy(ENEMY_TYPES::BIG_RED_TURRET, 25, -70, ENEMY_MOVEMENT::STAY);
				App->enemies->AddEnemy(ENEMY_TYPES::BIG_RED_TURRET, 153, -85, ENEMY_MOVEMENT::STAY);

			}

			//metalic balloon
			if ((int)background_y == -2720 && spawned == 1)
			{
				spawned = 2;
				App->enemies->AddEnemy(ENEMY_TYPES::METALLICBALLOON, 112, -70, ENEMY_MOVEMENT::BALLOON_PATH_FOREST);

				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 20, -30, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 40, -40, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 80, -60, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH2);

				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 180, -80, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH2);

			}

			if ((int)background_y == -2600 && spawned == 2)
			{
				spawned = 3;
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 30, -20, ENEMY_MOVEMENT::BEE_CORNER_STRAIGHT);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 130, -70, ENEMY_MOVEMENT::BEE_CORNER_STRAIGHT);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 160, -40, ENEMY_MOVEMENT::BEE_CORNER_STRAIGHT);

			}


			//flying machine + bee
			if ((int)background_y == -2500 && spawned == 3) {
				spawned = 4;
				App->enemies->AddEnemy(ENEMY_TYPES::FLYING_MACHINE, -80, 20, ENEMY_MOVEMENT::FLYING_MACHINE_PATH_1);

				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 50, -40, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 130, -70, ENEMY_MOVEMENT::BEE_CORNER_STRAIGHT);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 20, -40, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 80, -100, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH2);

			}

			//red turret
			if ((int)background_y == -2400 && spawned == 4)
			{
				spawned = 5;
				

				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 160, -40, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, -40, -40, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 80, -100, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH2);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, -10, -100, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH);

			}

			if ((int)background_y == -2290 && spawned == 5)
			App->enemies->AddEnemy(ENEMY_TYPES::RED_TURRET, 274, 50, ENEMY_MOVEMENT::RED_TURRET_RIGHT_LEFT);

			if ((int)background_y == -2200 && spawned == 5)
			{
				spawned = 6;
				App->enemies->AddEnemy(ENEMY_TYPES::RED_TURRET, -80, 55, ENEMY_MOVEMENT::RED_TURRET_LEFT_RIGTH);
				App->enemies->AddEnemy(ENEMY_TYPES::RED_TURRET, -80, -20, ENEMY_MOVEMENT::RED_TURRET_LEFT_RIGTH);

				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 20, -40, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 160, -40, ENEMY_MOVEMENT::BEE_CORNER_STRAIGHT);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 50, -100, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, -10, -100, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);


			}

			if ((int)background_y == -2080 && spawned == 6)
			{
				spawned = 7;
				App->enemies->AddEnemy(ENEMY_TYPES::RED_TURRET, -70, 40, ENEMY_MOVEMENT::RED_TURRET_LEFT_RIGTH);
				App->enemies->AddEnemy(ENEMY_TYPES::RED_TURRET, -70, -60, ENEMY_MOVEMENT::RED_TURRET_LEFT_RIGTH);

			}

			//red turret + red mecha
			if ((int)background_y == -2000 && spawned == 7)
			{
				spawned = 8;
				App->enemies->AddEnemy(ENEMY_TYPES::RED_TURRET, 234, -50, ENEMY_MOVEMENT::RED_TURRET_RIGHT_LEFT);
				App->enemies->AddEnemy(ENEMY_TYPES::TRUMP_RED_MECHA, 35, -50, ENEMY_MOVEMENT::TRUMP_RED_MECHA_PATH);

			}


			if ((int)background_y == -1900 && spawned == 8)
			{
				spawned = 9;
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, -10, -20, ENEMY_MOVEMENT::BEE_CORNER_STRAIGHT);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 160, -50, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH2);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 20, -80, ENEMY_MOVEMENT::BEE_CORNER_LEFT_PATH);
				App->enemies->AddEnemy(ENEMY_TYPES::BEE, 80, -50, ENEMY_MOVEMENT::BEE_CORNER_RIGHT_PATH);

			}

			if (((int)background_y == -1740 && spawned == 9))
			{
				spawned = 10;
				App->enemies->AddEnemy(ENEMY_TYPES::FOREST_BOSS_HAND, 121, -62, ENEMY_MOVEMENT::BOSS_FOREST_HAND);
				App->enemies->AddEnemy(ENEMY_TYPES::FOREST_BOSS_HAND, 66, -62, ENEMY_MOVEMENT::BOSS_FOREST_HAND);
				App->enemies->AddEnemy(ENEMY_TYPES::BOSS_FOREST, 19, -170, ENEMY_MOVEMENT::BOSS_FOREST_HAND);
			}



			if (background_y >= 1901) {
				App->particles->AddParticle(App->particles->tree, motion_trees_5_x, motion_trees_5_y, COLLIDER_NONE);
				
				/*if (background_y >= -2800.0f) {
					motion_trees_5_y -= -0.5f;
				}
				if (background_y >= -2100.0f && background_y <= -1990.0f) {
					motion_trees_5_x -= 0.5f;
				}*/
			}


			/*if ((int)background_y >= -1901) {
				if (!App->render->Blit(motion_trees, (int)0 + motion_trees_5_x, (int)0 + motion_trees_5_y, &motion_trees_5, 0.75f)) {
					LOG("Cannot blit the texture in SceneJungle %s\n", SDL_GetError());
					status = UPDATE_ERROR;
				}
				if (background_y >= -2800.0f) {
					motion_trees_5_y -= -0.5f;
				}
				if (background_y >= -2100.0f && background_y <= -1990.0f) {
					motion_trees_5_x -= 0.5f;
				}
			}*/
			

		}


		if (App->input->keyboard[SDL_SCANCODE_KP_1] && !App->player2->IsEnabled())
		{
			App->ui->p2 = true;
			App->player2->playerLives = 3;
			App->player2->Enable();
			App->characterSelection->player2_joined = true;

			if (App->characterSelection->characterSelected_P1 = CHARACTER_SELECTED::VALNUS_SELECTED)
				App->characterSelection->characterSelected_P2 = CHARACTER_SELECTED::TETSU_SELECTED;

			App->audio->PlayFx(player2joined);
		}


		if (App->input->keyboard[SDL_SCANCODE_KP_1] && !App->player->IsEnabled())
		{
			App->ui->p2 = true;
			App->player->playerLives = 3;
			App->player->Enable();
			App->characterSelection->player2_joined = true;

			if (App->characterSelection->characterSelected_P2 = CHARACTER_SELECTED::VALNUS_SELECTED)
				App->characterSelection->characterSelected_P1 = CHARACTER_SELECTED::TETSU_SELECTED;

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