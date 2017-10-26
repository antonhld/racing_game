
#include "racing.h"

void main()
{
	srand(time(0));
	int exitCode;
Start:
	Racing game;
	//show start screen
	if(!game.showStartScreen())
		goto Exit;
	for(;;)
	{
		//clear the screen
		clearscreen();
		//render the field
		game.renderField();
		//output the field to the console
		game.showField();

		//move the car to the right
		if(GetAsyncKeyState(VK_RIGHT))
			game.moveRight();
		//move the car to the left
		if(GetAsyncKeyState(VK_LEFT))
			game.moveLeft();
		//increase speed
		if(GetAsyncKeyState(VK_UP))
			game.increaseSpeed();
		//decrease speed
		if(GetAsyncKeyState(VK_DOWN))
			game.decreaseSpeed();
		//manually exit
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			exitCode = 1;
			break;
		}
		//pause
		if(GetAsyncKeyState(VK_RETURN))
		{
			uint pauseTime = clock();
			system("pause");
			game.addTimeOnPause(clock() - pauseTime);
		}

		//end the game if car hits the obstacle
		if(game.detectHit())
		{
			exitCode = 0;
			break;
		}

		//increase obstacle position or create a new obstacle if the previous one is out of view
		game.increaseObstaclePos();
		
		game.increaseDistance(170 - game.getSpeed());
		Sleep(game.getSpeed());
	}
	//show start screen on manual exit
	if(exitCode)
		goto Start;
	//show end screen on crash
	else
		if(game.showEndScreen())
			goto Start;
Exit:
	return;
}