cmake_minimum_required(VERSION 3.16)

set(This CleanStrikeTests)

set(Sources
    Example.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    CleanStrike
)

add_test(
    NAME ${This}
    COMMAND ${This}
)