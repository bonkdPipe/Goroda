add_library(city_reader city_reader.cpp "include/city_reader/rapidcsv.h" "include/city_reader/city_reader.h")

target_include_directories(city_reader PUBLIC include)

find_path(RAPIDCSV_INCLUDE_DIRS "rapidcsv.h")
    target_include_directories(city_reader PRIVATE ${RAPIDCSV_INCLUDE_DIRS})