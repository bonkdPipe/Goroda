add_library(city_game city_game.cpp "include/city_game/city_game.h")

target_link_libraries(city_game PUBLIC city_reader)

target_include_directories(city_game PUBLIC include)