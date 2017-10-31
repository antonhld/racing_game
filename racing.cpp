
#include "racing.h"

Racing::Racing() 
	: distance_(0), speed_(150), startTime_(clock()), playerSide_(LEFT), obstacleSide_(RIGHT), obstaclePos_(LANE_LENGTH - OBSTACLE_LENGTH)
{}
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
	obstaclePos_--;
	if(obstaclePos_ <= 0) 
	{
        obstaclePos_ = LANE_LENGTH - OBSTACLE_LENGTH;
        obstacleSide_ = rand() % 2;
    }
}
void Racing::increaseSpeed()
{
	if(speed_ > MIN_SPEED)
		speed_ -= SPEED_INC;
}
void Racing::decreaseSpeed()
{
	if(speed_ < MAX_SPEED)
		speed_ += SPEED_INC;
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
void Racing::showField()
{
	array<System::String^>^ carModel = gcnew array<System::String^>(9) {
		"  *****     *****     ",
		"  *****     *****     ",
		"  *****     *****     ",
        "       *****     *****",
		"       *****     *****",
		"       *****     *****",
		"  *****     *****     ",
        "  *****     *****     ",
		"  *****     *****     "};
		array<System::String^>^ obstacleModel = gcnew array<System::String^>(9) {
		"#####",
		"#####",
		"#####",
		"#####",
		"#####",
		"#####",
		"#####",
		"#####",
		"#####",};
	for(int i=0; i<LANE_LENGTH; i++)
		cout<<'-';
	cout<<'\n';
	for(int i=0; i<LANE_WIDTH; i++)
	{
		String^ spacing = gcnew String(SPACE, obstaclePos_);
		if(playerSide_ == LEFT)
			Console::Write(carModel[i]);
		if(playerSide_ == obstacleSide_)
			spacing = gcnew String(SPACE, obstaclePos_ - CAR_WIDTH);
		if(obstacleSide_ == LEFT)
			Console::Write(spacing + obstacleModel[i]);
		cout<<'\n';
	}
	cout<<'\n';
	for(int i=0; i<LANE_LENGTH; i++)
		cout<<'-';
	cout<<'\n';
	for(int i=0; i<LANE_WIDTH; i++)
	{
		String^ spacing = gcnew String(SPACE, obstaclePos_);
		if(playerSide_ == RIGHT)
			Console::Write(carModel[i]);
		if(playerSide_ == obstacleSide_)
			spacing = gcnew String(SPACE, obstaclePos_ - CAR_WIDTH);
		if(obstacleSide_ == RIGHT)
			Console::Write(spacing + obstacleModel[i]);
		cout<<'\n';
	}
	cout<<'\n';
	for(int i=0; i<LANE_LENGTH; i++)
		cout<<'-';
	cout<<'\n';
	cout<<"   Speed: "<<170-speed_<<"   Time: "<<getTime()<<"   Distance: "<<distance_<<"   Points: "<<calculatePoints()<<"   \n";
}
int Racing::getTime()
{
	return (clock()-startTime_)/1000;
}
int Racing::calculatePoints()
{
	return (distance_/((clock()-startTime_)/1000 + 1));
}
bool Racing::showStartScreen()
{
	system("cls");
	cout<<"                       \n"
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
	while(true)
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
	cout<<"                       \n"
		<<"                       \n"
		<<"       GAME OVER       \n"
		<<"    Time:"<<getTime()<<"\n"
		<<"    Distance:"<<distance_<<"\n"
		<<"    Points:"<<calculatePoints()<<"\n"
		<<"                       \n"
		<<"    Press q to exit    \n" 
		<<"    Press s to start   \n"
		<<"                       \n"
		<<"                       \n";
	while(true)
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
	if(playerSide_ == obstacleSide_ && obstaclePos_ <= CAR_WIDTH)
		return true;
	return false;
}
