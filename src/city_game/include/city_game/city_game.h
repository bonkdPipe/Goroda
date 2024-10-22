#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <ctime>
#include <algorithm>
#include <city_reader/city_reader.h>

class Game {
private:
    std::vector<std::string> cities;
    std::vector<std::string> usedCities;

public:
    Game(std::string path) {

        cities = read(path);
    }

    bool is_city_valid(std::string city);

    bool is_city_used(std::string city);

    char get_last_char(const std::string& city);

    void mark_city_as_used(const std::string& city);

    void start() {
        std::string currentCity;
        char lastChar = '\0';
        int playerTurn = 1;

        while (true) {
            std::cout << "Your current turn: " << playerTurn << " Input a city name: ";
            std::cin >> currentCity;

            std::string cityLower = currentCity;


            is_city_used(cityLower);


            if (lastChar == '\0' || tolower(currentCity[0]) == tolower(lastChar)) {

                is_city_used(cityLower);


                usedCities.push_back(cityLower);
                lastChar = get_last_char(currentCity);
                playerTurn = (playerTurn == 1) ? 2 : 1;
            }
            else {
                std::cout << "Reminder --> Current last letter: '" << lastChar << "'." << std::endl;
            }
        }
    }
};