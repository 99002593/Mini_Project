#ifndef __PREMIERSHIPDATABASE_H_
#define __PREMIERSHIPDATABASE_H_

#include"premiership.h"
#include"result.h"
#include<iostream>
#include<string>
#include<iterator>
#include<list>


class PremiershipDatabase
{
	std::list <Statistics> footy;

public:
	void addFixtures(int, std::string, std::string, std::string, int, int, int, int, int, int, int);
	void removeFixture(int);
	Statistics* findFixtureByround(int);
	int computegoalsscoredinround(int);
	int countHomeFixturesbyTeam(std::string);
	int countWinsbyHomeTeam();
	int computeTotalYellowcards();
	int findResultbyReferee(std::string);
	int countAll();
	


};

#endif
		
	
