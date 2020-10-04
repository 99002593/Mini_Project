#include "premiershipdatabase.h"
#include "premiership.h"
#include "result.h"

#include<list>
#include<string>
#include<iterator>
using namespace std;

void PremiershipDatabase::addFixtures(int matchround, std::string hteam, std::string ateam, std::string ref, int hgoals, int agoals, int
hshots, int ashots, int tfouls, int ycards, int rcards)
{
	footy.push_back(Statistics(matchround, hteam, ateam, ref, hgoals, agoals, hshots, ashots, tfouls, ycards, rcards));

}

void PremiershipDatabase::removeFixture(int matchround)
{
	
	    std::list<Statistics> :: iterator iter;
	    
	    for(iter=footy.begin();iter!=footy.end();iter++)
	    {
        	if(iter->getround()== matchround)
        	{
           		footy.erase(iter);
           		break;
        	}
    	}
}

Statistics* PremiershipDatabase::findFixtureByround(int matchround)
{
		 std::list<Statistics> :: iterator iter;
		 
		 for(iter=footy.begin();iter!=footy.end();iter++)
		 {
		 	
        	if(matchround == iter->getround())
        	{
            		return &(*iter);
        	}
    }
    return NULL;
}

int PremiershipDatabase::computegoalsscoredinround(int round)
{
	 int count=0;
   std::list <Statistics> :: iterator iter;
   for(iter=footy.begin();iter!=footy.end();iter++)
   {
       if(iter->getround() == round)
        count = count+(iter->gethomegoals()+iter->getawaygoals());
   }
   return count;
}	



int PremiershipDatabase::countHomeFixturesbyTeam(std::string hteam)
{
	 int count=0;
   std::list <Statistics> :: iterator iter;
   for(iter=footy.begin();iter!=footy.end();iter++)
   {
       if(iter->gethometeam() == hteam)
        count++;
   }
   return count;
}

int PremiershipDatabase::computeTotalYellowcards()
{		
		int count=0;
		std::list<Statistics>::iterator iter=footy.begin();
    for(iter=footy.begin();iter!=footy.end();++iter)
    {
        count += iter->getyellowcards();
		}
    return count;
}

int PremiershipDatabase::findResultbyReferee(std::string ref)
{
    std::list<Statistics>::iterator iter;
    for(iter=footy.begin();iter!=footy.end();++iter)
    {
        if(iter->getReferee() == ref)
        {	
						std::string res=iter->getResult();
            cout<<res<<endl;
        }
    }
    return 0;
}

int PremiershipDatabase::countAll()
{
		int count=0;
    std::list<Statistics>::iterator iter;
    for(iter=footy.begin();iter!=footy.end();++iter)
    {
        count++;
    }
    return count;
}

