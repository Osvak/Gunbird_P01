#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleSceneSea.h"
#include "ModuleSceneMine.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"

//TODO: remove this if not necesary
#include "ModuleInput.h"


ModuleSceneSea::ModuleSceneSea()
{
	// Background
	background_x = 0;
	background_y = -2036;
	background.w = SCREEN_WIDTH;
	background.h = 2036;
}

ModuleSceneSea::~ModuleSceneSea()
{}

// Load assets
bool ModuleSceneSea::Start()
{
	LOG("Loading SceneSea assets");
	bool ret = true;
	background_y = -2036;
	App->player->Enable();

	graphics = App->textures->Load("Assets/maps/map_sea_background.png");
	if (graphics == nullptr) {
		LOG("Cannot load the texture in SceneSea");
		ret = false;
	}
	if (!App->audio->PlayMusic("Assets/audio/gunbird_sea_level_music.wav"))
		ret = false;
	return ret;
}

// Update: draw background
update_status ModuleSceneSea::Update()
{

	update_status status = UPDATE_CONTINUE;

	int speed = 1;
	if(background_y< -SCREEN_HEIGHT)
		background_y += speed;

	// Draw everything --------------------------------------
	if (!App->render->Blit(graphics, background_x, background_y + SCREEN_HEIGHT, &background, 0.75f)) {
		LOG("Cannot blit the texture in Scene Sea %s\n",SDL_GetError());
		status = UPDATE_ERROR;
	}

	//TODO change the position of the player to private to be more pro

	if ((App->player->position.y < 0 && App->fade->FadeIsOver()) ||/*TODO: remove this condition*/ (App->input->keyboard[SDL_SCANCODE_RETURN] && App->fade->FadeIsOver()))
		App->fade->FadeToBlack(this, App->sceneMine);

	return status;
}

bool ModuleSceneSea::CleanUp()
{
	//TODO check if we can control this
	LOG("Unloading Scene Sea");

	App->player->Disable();
	graphics = nullptr;
	App->audio->StopMusic();

	return true;
}