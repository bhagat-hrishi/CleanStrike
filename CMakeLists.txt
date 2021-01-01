cmake_minimum_required(VERSION 3.16)

set(This CleanStrike)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)


enable_testing()

add_subdirectory(libs/googletest)

include_directories(include)
set(Headers
    include/headers/Player.hpp
    include/headers/Board.hpp
    include/headers/Match.hpp
    include/headers/Operations.hpp
    include/headers/Coin.hpp
    include/headers/BlackCoin.hpp
    include/headers/RedCoin.hpp
    include/headers/VariadicTable.h
    include/Player.cpp
    include/Operations.cpp
    include/Board.cpp
    include/Match.cpp
    include/BlackCoin.cpp
    include/RedCoin.cpp
)

#file(COPY src/inputs DESTINATION .)
#file(COPY logs DESTINATION .)

set(Sources
    src/main.cpp 
)


# configure_file(src/inputs/inputFile.txt {CMAKE_CURRENT_SOURCE_DIR})


add_executable(CleanStrikeByHrishi ${Sources} ${Headers})

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)