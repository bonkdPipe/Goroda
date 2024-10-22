#include <gtest/gtest.h>
#include <city_game/city_game.h>
#include <catch2/catch_test_macros.hpp>

class GameTest : public ::testing::Test {
public:
    Game game;

    GameTest() : game("input here") {

    }
};

SCENARIO("vectors can be sized and resized", "[vector]") {

    GIVEN("A vector with some items") {
        std::vector<int> v(5);

        REQUIRE(v.size() == 5);
        REQUIRE(v.capacity() >= 5);

        WHEN("the size is increased") {
            v.resize(10);

            THEN("the size and capacity change") {
                REQUIRE(v.size() == 10);
                REQUIRE(v.capacity() >= 10);
            }
        }
        WHEN("the size is reduced") {
            v.resize(0);

            THEN("the size changes but not capacity") {
                REQUIRE(v.size() == 0);
                REQUIRE(v.capacity() >= 5);
            }
        }
        WHEN("more capacity is reserved") {
            v.reserve(10);

            THEN("the capacity changes but not the size") {
                REQUIRE(v.size() == 5);
                REQUIRE(v.capacity() >= 10);
            }
        }
        WHEN("less capacity is reserved") {
            v.reserve(0);

            THEN("neither size nor capacity are changed") {
                REQUIRE(v.size() == 5);
                REQUIRE(v.capacity() >= 5);
            }
        }
    }
}



TEST_F(GameTest, ValidCities) {

    EXPECT_FALSE(game.is_city_valid("Moscow"));
    EXPECT_FALSE(game.is_city_valid("Saint Peters"));
    EXPECT_FALSE(game.is_city_valid("Raymore"));
    EXPECT_TRUE(game.is_city_valid("Bruhloradsd"));
}

TEST_F(GameTest, UsedCities) {
    game.mark_city_as_used("Moscow");
    EXPECT_FALSE(game.is_city_used("Moscow"));
    EXPECT_FALSE(game.is_city_used("Saint Peters"));
}

TEST_F(GameTest, LastCharacter) {
    EXPECT_EQ(game.get_last_char("Moscow"), 'w');
    EXPECT_EQ(game.get_last_char("Saint Peters"), 's');
}

//int main(int argc, char** argv) {
//    /*::testing::InitGoogleTest(&argc, argv);
//
//    return RUN_ALL_TESTS();*/
//}