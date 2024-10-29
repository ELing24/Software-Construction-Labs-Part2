#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/Awards.h"
#include "../include/Triangle.h"
#include "../include/Hailstone.h"
#include <iostream>
using namespace awards;
using namespace std;
using testing::InSequence;
using namespace sequence;
using shapes::Triangle;


/*TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}*/

class HardcodedRankList : public RankList {
    private:
        vector<string> names = {"John", "Jane", "Jim", "Joan", "Jake"};
        int currentIndex = 0;

    public:
        std::string getNext() {
        if (currentIndex >= names.size()) {
        currentIndex = 0;
        }
        return names[currentIndex++];
    }
};

class MockAwardCeremonyActions: public AwardCeremonyActions{
    public:
        MOCK_METHOD(void, playAnthem, (), (override));
        MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
        MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
        MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
        MOCK_METHOD(void, awardGold, (std::string recipient), (override));

};
TEST(ACAtests, ACA_RL)
{
    MockAwardCeremonyActions foo;
    EXPECT_CALL(foo, playAnthem());
    EXPECT_CALL(foo, awardBronze("John"));
    EXPECT_CALL(foo, awardSilver("Jane"));
    EXPECT_CALL(foo, awardGold("Jim"));
    EXPECT_CALL(foo, turnOffTheLightsAndGoHome());
    HardcodedRankList rankList;
    performAwardCeremony(rankList, foo);
}


TEST(HailstoneTest, zeroInput){
    uint64_t number = 0;
    EXPECT_TRUE(satisfiesHailstone(number) == false);
}
TEST(HailstoneTest, oneInput){
    uint64_t number = 1;
    EXPECT_TRUE(satisfiesHailstone(number) == true);
    
}
TEST(HailstoneTest, modeven){
    uint64_t number = 4;
    EXPECT_TRUE(satisfiesHailstone(number) == true);
}
TEST(HailstoneTest, mododd){
    uint64_t number = 3;
    EXPECT_TRUE(satisfiesHailstone(number) == true);
}

TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(4,2,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

TEST(TriangleTests, testArea) {
    Triangle *aTriangle = new Triangle(5,4,3);
    EXPECT_EQ (aTriangle->getArea(), 6.0);
}

TEST(TriangleTests, testKind) {
    Triangle *aTriangle = new Triangle(3, 3, 3);
    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::EQUILATERAL);
}

TEST(TriangleTests, InvalidInput) {
    EXPECT_DEATH(Triangle(6, -1, 5), "Does not satisfy triangle inequality");
}

TEST(TriangleTests, ValidInput) {
    Triangle* aTriangle = new Triangle(6, 5, 5);
    EXPECT_NO_THROW(*aTriangle);
}

TEST(TriangleTests, ValidPerimeter) {
    Triangle* aTriangle = new Triangle(4, 4, 4);
    EXPECT_EQ(aTriangle->getPerimeter(), 12);

}

TEST(TriangleTests, ValidArea) {
    Triangle* aTriangle = new Triangle(6, 5, 5);
    EXPECT_DOUBLE_EQ(aTriangle->getArea(), 12.0);
}

TEST(TriangleTests, ValidIsosceles) {
    Triangle* aTriangle = new Triangle(6, 4, 4);
    EXPECT_TRUE(aTriangle->isIsosceles());
} 





