#ifndef __PREMIERSHIP_H_
#define __PREMIERSHIP_H_
#include<iostream>
#include<stdio.h>
#include<string>
class Premiership{
	protected:
		int round;	
		std::string hometeam;
		std::string awayteam;
		std::string referee;
	
	public:
		Premiership();
		Premiership(int,std::string,std::string,std::string);
		int getround();	
		std::string gethometeam();
		std::string getawayteam();
		std::string getReferee();	
		virtual double computegoalsscored(int, int)=0;
		virtual double computeshotstaken(int, int)=0;
		virtual std::string getResult()=0;
		void display();	
};

#endif
