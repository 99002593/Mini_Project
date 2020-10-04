#include <iostream>
#include <string>
#include <fstream>
#include"premiershipdatabase.h"
#include"result.h"
#include"premiership.h"
#include <gtest/gtest.h>
using namespace std;

namespace {

class PremiershipDatabaseTest : public ::testing::Test {

protected:
  void SetUp() { 
    std::ifstream ip("datapl.csv");

  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

  string Round;
  string Hometeam;
  string Awayteam;
	string Referee;  
	string Homegoals;
  string Awaygoals;
  string Homeshots;
  string Awayshots;
	string Fouls;
	string Yellowcards;
	string Redcards;	
	


  while(ip.good()){
  
		//int stoi(const std::string& str, std::size_t* pos = 0, int base = 10);

    getline(ip,Round,',');
    getline(ip,Hometeam,',');
    getline(ip,Awayteam,',');
		getline(ip,Referee,',');    
		getline(ip,Homegoals,',');
    getline(ip,Awaygoals,',');
    getline(ip,Homeshots,',');
		getline(ip,Awayshots,',');
		getline(ip,Fouls,',');
    getline(ip,Yellowcards,',');
    getline(ip,Redcards,'\n');
    int ROUND=atoi(Round.c_str());
    int HOMEGOALS=atoi(Homegoals.c_str());
		int AWAYGOALS=atoi(Awaygoals.c_str());
		int HOMESHOTS=atoi(Homeshots.c_str());
		int AWAYSHOTS=atoi(Awayshots.c_str());
		int FOULS=atoi(Fouls.c_str());
		int YELLOWCARDS=atoi(Yellowcards.c_str());
		int REDCARDS=atoi(Redcards.c_str());

    if(Round!="")
    P1.addFixtures(ROUND,Hometeam,Awayteam,Referee,HOMEGOALS,AWAYGOALS,HOMESHOTS,AWAYSHOTS,FOULS,YELLOWCARDS,REDCARDS);
 
  }
 	}
  void TearDown() {}
  PremiershipDatabase P1;
};


TEST_F(PremiershipDatabaseTest, AddFixtureTest) 
{
  P1.addFixtures(39,"Fulham", "Leeds","J.Vardy",2,1,11,13,25,4,0);
  EXPECT_NE((Statistics*)NULL, P1.findFixtureByround(39));
  EXPECT_EQ(381, P1.countAll());
}


TEST_F(PremiershipDatabaseTest, RemoveFixtureTest) 
{
  P1.removeFixture(39);
  EXPECT_EQ(NULL, P1.findFixtureByround(39));
  EXPECT_EQ(380, P1.countAll());
}

TEST_F(PremiershipDatabaseTest, CountTotalNumberOfFixtures) 
{   
  P1.addFixtures(39, "Norwich", "Villa","H.Quinn",4,1,14,10,8,0,1);
  P1.addFixtures(39,"Portsmouth", "Peterborough","H.Wilson",1,3,8,15,31,8,2);          
  EXPECT_EQ(382, P1.countAll());
}



TEST_F(PremiershipDatabaseTest, TotalYellowcards) 
{
  EXPECT_EQ(1380, P1.computeTotalYellowcards());
}

TEST_F(PremiershipDatabaseTest, Goalsscoredinround) 
{
  EXPECT_EQ(36, P1.computegoalsscoredinround(27));
}
}
