cmake_minimum_required(VERSION 3.16)

set(This CleanStrike)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)


enable_testing()

add_subdirectory(libs/googletest)

include_directories(include)
set(Headers
    include/CleanStrike/headers/Player.hpp
    include/CleanStrike/headers/Board.hpp
    include/CleanStrike/headers/Match.hpp
    include/CleanStrike/headers/Operations.hpp
    include/CleanStrike/headers/Coin.hpp
    include/CleanStrike/headers/VariadicTable.h
    include/CleanStrike/Player.cpp
    include/CleanStrike/Operations.cpp
    include/CleanStrike/Board.cpp
    include/CleanStrike/Match.cpp
    include/CleanStrike/Coin.cpp
)

file(COPY src/inputs DESTINATION .)
#file(COPY logs DESTINATION .)

set(Sources
    src/main.cpp 
)





add_executable(CleanStrikeByHrishi ${Sources} ${Headers})

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)