#include<iostream>
#include<ctime>
#include"premiership.h"


Premiership::Premiership():round(0),hometeam(""),awayteam(""),referee(""){}

Premiership::Premiership(int matchround, std::string hteam, std::string ateam, std::string ref):round(matchround), hometeam(hteam),awayteam(ateam),referee(ref){}

int Premiership::getround()
{
	return round;
}	


std::string Premiership::gethometeam()
{
	return hometeam;
}	

std::string Premiership::getawayteam()
{
	return awayteam;
}

std::string Premiership::getReferee()
{
	return referee;
}

