
#include "racing.h"

void clearscreen()
{
    HANDLE hOut;
    COORD Position;
 
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
 
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void Racing::moveLeft()
{
	playerSide_ = LEFT;
}
void Racing::moveRight()
{
	playerSide_ = RIGHT;
}
void Racing::increaseObstaclePos()
{
	obstaclePos_++;
	if(obstaclePos_ > 22) 
	{
        obstaclePos_ = 0;
        obstacleSide_ = rand() % 2;
    }
}
void Racing::increaseSpeed()
{
	if(speed_ > 20)
		speed_ -= 20;
}
void Racing::decreaseSpeed()
{
	if(speed_ < 150)
		speed_ += 20;
}
int Racing::getSpeed()
{
	return speed_;
}
void Racing::addTimeOnPause(uint amount)
{
	startTime_ += amount;
}
void Racing::increaseDistance(int amount)
{
	distance_ += amount;
}
void Racing::renderField()
{
	for(int i=0; i<25; i++)
	{
		field_[i][0] =  '|';
		field_[i][24] = '|';
		for(int j=1; j<24; j++)
			field_[i][j] = ' ';
		field_[i][12] = '|';
	}
	if(playerSide_ == LEFT)
	{
		for(int i=0; i<2; i++)
			for(int j=3; j<6; j++)
				field_[16+i][2+j] = '*';
		for(int i=2; i<4; i++)
			for(int j=0; j<3; j++)
				field_[16+i][2+j] = '*';
		for(int i=2; i<4; i++)
			for(int j=6; j<9; j++)
				field_[16+i][2+j] = '*';
		for(int i=4; i<6; i++)
			for(int j=3; j<6; j++)
				field_[16+i][2+j] = '*';
		for(int i=6; i<8; i++)
			for(int j=0; j<3; j++)
				field_[16+i][2+j] = '*';
		for(int i=6; i<8; i++)
			for(int j=6; j<9; j++)
				field_[16+i][2+j] = '*';
	}
	if(playerSide_ == RIGHT)
	{
		for(int i=0; i<2; i++)
			for(int j=3; j<6; j++)
				field_[16+i][14+j] = '*';
		for(int i=2; i<4; i++)
			for(int j=0; j<3; j++)
				field_[16+i][14+j] = '*';
		for(int i=2; i<4; i++)
			for(int j=6; j<9; j++)
				field_[16+i][14+j] = '*';
		for(int i=4; i<6; i++)
			for(int j=3; j<6; j++)
				field_[16+i][14+j] = '*';
		for(int i=6; i<8; i++)
			for(int j=0; j<3; j++)
				field_[16+i][14+j] = '*';
		for(int i=6; i<8; i++)
			for(int j=6; j<9; j++)
				field_[16+i][14+j] = '*';
	}
	if(obstacleSide_ == LEFT)
		for(int i=obstaclePos_; i<obstaclePos_+3; i++)
			for(int j=0; j<9; j++)
				field_[i][2+j] = 219;
	if(obstacleSide_ == RIGHT)
		for(int i=obstaclePos_; i<obstaclePos_+3; i++)
			for(int j=0; j<9; j++)
				field_[i][14+j] = 219;
}
void Racing::showField()
{
	for(int i=0; i<25; i++)
	{
		for(int j=0; j<25; j++)
		{
			std::cout<<field_[i][j];
			if(i==10 && j==24)
				std::cout<<"       Speed:"<<170-speed_<<"   ";
			if(i==11 && j==24)
				std::cout<<"       Time:"<<(clock()-startTime_)/1000<<"   ";
			if(i==12 && j==24)
				std::cout<<"       Distance:"<<distance_<<"   ";
			if(i==13 && j==24)
				std::cout<<"       Points:"<<(distance_/((clock()-startTime_)/1000 + 1))<<"   ";
		}
		std::cout<<'\n';
	}
}
bool Racing::showStartScreen()
{
	system("cls");
	std::cout<<"                       \n"
				<<"                       \n"
				<<"        Racing         \n"
				<<"                       \n"
				<<"                       \n"
				<<"                       \n"
				<<"                       \n"
				<<"    Press q to exit    \n" 
				<<"    Press s to start   \n"
				<<"                       \n"
				<<"                       \n";
	for(;;)
	{
		//if 'q' is pressed
		if(GetAsyncKeyState(0x51))
			return false;
		//if 's' is pressed
		if(GetAsyncKeyState(0x53))
			return true;
	}
}
bool Racing::showEndScreen()
{
	system("cls");
	std::cout<<"                       \n"
				<<"                       \n"
				<<"       GAME OVER       \n"
				<<"    Time:"<<(clock()-startTime_)/1000<<"\n"
				<<"    Distance:"<<distance_<<"\n"
				<<"    Points:"<<(distance_/((clock()-startTime_)/1000 + 1))<<"\n"
				<<"                       \n"
				<<"    Press q to exit    \n" 
				<<"    Press s to start   \n"
				<<"                       \n"
				<<"                       \n";
	for(;;)
	{
		//if 'q' is pressed
		if(GetAsyncKeyState(0x51))
			return false;
		//if 's' is pressed
		if(GetAsyncKeyState(0x53))
			return true;
	}
}
bool Racing::detectHit()
{
	if(playerSide_ == obstacleSide_ && obstaclePos_ >= 14)
		return true;
	return false;
}
Racing::Racing()
{
	distance_ = 0;
	speed_ = 150;
	startTime_ = clock();
	playerSide_ = RIGHT;
	obstaclePos_ = 0;
}