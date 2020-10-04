#include <iostream>
#include"premiershipdatabase.h"
#include"result.h"
#include"premiership.h"
#include <gtest/gtest.h>

TEST(Premiership,DefaultConstructor) {
    Statistics S1;
    EXPECT_EQ(0,S1.gethomegoals());
    EXPECT_EQ(0,S1.getawaygoals());
    EXPECT_EQ(0,S1.gethomeshots());
    EXPECT_EQ(0,S1.getawayshots());
    EXPECT_EQ(0,S1.getfouls());
		EXPECT_EQ(0,S1.getyellowcards());
		EXPECT_EQ(0,S1.getredcards());
}

TEST(Premiership,ParameterizedConstructor) {
    Statistics S2(20, "Chelsea","Arsenal","A.Conte",2,2,10,12,18,8,1);
		EXPECT_EQ(20,S2.getround());
		EXPECT_EQ("Chelsea",S2.gethometeam());
		EXPECT_EQ("Arsenal",S2.getawayteam());
		EXPECT_EQ("A.Conte",S2.getReferee());    
		EXPECT_EQ(2,S2.gethomegoals());
    EXPECT_EQ(2,S2.getawaygoals());
    EXPECT_EQ(10,S2.gethomeshots());
    EXPECT_EQ(12,S2.getawayshots());
    EXPECT_EQ(18,S2.getfouls());
		EXPECT_EQ(8,S2.getyellowcards());
		EXPECT_EQ(1,S2.getredcards());
}

TEST(Premiership,Shotstaken) {
    Statistics S3(16, "Man City","Man United","Josep",4,5,18,6,14,4,0);
    EXPECT_EQ(9,S3.computegoalsscored(4,5));
    EXPECT_EQ(24,S3.computeshotstaken(18,6));
    EXPECT_EQ("Man United",S3.getResult());
}
