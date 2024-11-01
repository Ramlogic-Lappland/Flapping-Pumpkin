#include "obstacle.h"

#include <cstdlib>
#include <ctime>

#include "globals/globals.h"

namespace obstacle
{
	int minHeight;
	int maxHeight;
	int maxWidth;
	int minWidth;
	const float initialSpeed = 200; 

	void initObstacle(CreateObstacle& obstacle)
	{
		minHeight = static_cast<int>(Globals::Screen.size.y / 12);
		maxHeight = static_cast<int>((Globals::Screen.size.y / 12) * 4);

		float sizeX = (Globals::Screen.size.x / 16);
		float sizeY = static_cast<float>(rand() % maxHeight + minHeight);

		obstacle.size = {sizeX, sizeY};
		obstacle.position = { Globals::Screen.size.x + obstacle.size.x, Globals::Screen.size.y - obstacle.size.y };
		obstacle.speed =  initialSpeed;
		obstacle.stride = minWidth * 3;
	}
	void updateObstacle(CreateObstacle& obstacle)
	{
		minHeight = static_cast<int>(Globals::Screen.size.y / 12);
		maxHeight = static_cast<int>((Globals::Screen.size.y / 12) * 4);

		float sizeY = static_cast<float>(rand() % maxHeight + minHeight);
		obstacle.size.y =  sizeY ;

		obstacle.position = { Globals::Screen.size.x + obstacle.size.x, Globals::Screen.size.y - obstacle.size.y };

		obstacle.speed +=  30 * GetFrameTime();
	}
}