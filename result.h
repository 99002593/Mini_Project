#ifndef __RESULT_H_
#define __RESULT_H_

#include<iostream>
#include<string>
#include"premiership.h"

class Statistics : public Premiership{
	private:
		int homegoals;
		int awaygoals;
		int homeshots;
		int awayshots;
		int fouls;
		int yellowcards;
		int redcards;

	public:
		Statistics();
		Statistics(int, std::string, std::string, std::string, int, int, int, int, int, int, int);
		double computegoalsscored(int, int);
		double computeshotstaken(int, int);
		std::string getResult();		
		int gethomegoals();
		int getawaygoals();
		int gethomeshots();
		int getawayshots();
		int getfouls();
		int getyellowcards();
		int getredcards();
};
#endif
