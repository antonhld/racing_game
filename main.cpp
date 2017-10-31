
#include "racing.h"

void main()
{
	srand(time(0));
	bool exitCode = true, newGame = true;
	Racing game;
	//show start screen
	exitCode = game.showStartScreen();

	while(exitCode)
	{
		if(newGame == true)
		{
			game.~Racing();
			new(&game) Racing();
			newGame = false;
		}

		//clear the screen
		system("cls");
		//output the field to the console
		game.showField();

		//move the car to the right
		if(GetAsyncKeyState(VK_DOWN))
			game.moveRight();
		//move the car to the left
		if(GetAsyncKeyState(VK_UP))
			game.moveLeft();
		//increase speed
		if(GetAsyncKeyState(VK_RIGHT))
			game.increaseSpeed();
		//decrease speed
		if(GetAsyncKeyState(VK_LEFT))
			game.decreaseSpeed();
		//manually exit
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			exitCode = game.showEndScreen();
			if(exitCode == true)
				newGame = true;
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
			exitCode = game.showEndScreen();
			if(exitCode == true)
				newGame = true;
		}

		//increase obstacle position or create a new obstacle if the previous one is out of view
		game.increaseObstaclePos();
		
		game.increaseDistance(170 - game.getSpeed());
		Sleep(game.getSpeed());
	}
	
	return;
}