#include<iostream>
#include<string>
#include "result.h"


Statistics::Statistics():homegoals(0),awaygoals(0), homeshots(0), awayshots(0), fouls(0), yellowcards(0), redcards(0){}

Statistics::Statistics(int matchround, std::string hteam, std::string ateam, std::string ref, int hgoals, int agoals, int hshots, int ashots, int tfouls, int ycards, int rcards): Premiership(matchround,hteam,ateam,ref), homegoals(hgoals), awaygoals(agoals), homeshots(hshots), awayshots(ashots), fouls(tfouls), yellowcards(ycards), redcards(rcards){}


double Statistics::computegoalsscored(int hgoals, int agoals)
{
	int totalgoals = hgoals + agoals;
	return totalgoals;
	
}

double Statistics::computeshotstaken(int hshots, int ashots)
{
	int totalshots = hshots + ashots;
	return totalshots;
}

std::string Statistics::getResult()
{
	if (homegoals>awaygoals)
		{
		return hometeam;
		}
	else
		{
		return awayteam;
		}
}

int Statistics::gethomegoals()
{
	return homegoals;
}


int Statistics::getawaygoals()
{
	return awaygoals;
}

int Statistics::gethomeshots()
{
	return homeshots;
}

int Statistics::getawayshots()
{
	return awayshots;
}

int Statistics::getfouls()
{
	return fouls;
}

int Statistics::getyellowcards()
{
	return yellowcards;
}

int Statistics::getredcards()
{
	return redcards;
}
