#include <city_game/city_game.h>

bool Game::is_city_valid(std::string city) {
    if (std::find(cities.begin(), cities.end(), city) == cities.end()) {
        std::cout << "There is no city of " << city << " You lose. " << std::endl;
        return true;
    }
    else {
        return false;
    }
}

bool Game::is_city_used(std::string city) {
    if (std::find(usedCities.begin(), usedCities.end(), city) != usedCities.end()) {
        std::cout << "This city was used. Try Again" << std::endl;
        return true;
    }
    else {
        return false;
    }
}

char Game::get_last_char(const std::string& city) {
    return city.back();
}

void Game::mark_city_as_used(const std::string& city) {
    std::string cityLower = city;
    transform(cityLower.begin(), cityLower.end(), cityLower.begin(), ::tolower);
    usedCities.push_back(cityLower);
}
