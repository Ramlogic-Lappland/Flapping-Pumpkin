#include "player.h"

#include "globals/globals.h"

namespace player
{
	void initPlayer(createPlayer& player)
	{
		player.alive = true;
		player.lives = 3;
		player.gravity = 180;
		player.jumpSpeed = static_cast<float>( player.gravity * 2.5);
		player.playerbody = { 60, (Globals::Screen.size.y / 2) - 30, 40, 40}; 
	}
	void movePlayer(createPlayer& player)
	{
		if (IsKeyDown(KEY_DOWN))
		{
			player.playerbody.y += player.gravity * GetFrameTime();
		}
		if (IsKeyDown(KEY_UP))
		{
			player.playerbody.y -= player.gravity * GetFrameTime();
		}
	}
}