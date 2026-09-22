cmake_minimum_required(VERSION 3.30)
project(Applied_Algo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Applied_Algo main.cpp)
add_executable(P_1_1 P_1/P_1_1.cpp)
add_executable(P_1_2 P_1/P_1_2.cpp)
add_executable(P_1_3 P_1/P_1_3.cpp)
add_executable(P_1_4 P_1/P_1_4.cpp)

add_executable(Largest_Black_Sub_Rectangle LAB/Lab1/Largest_Black_Sub_Rectangle.cpp)
add_executable(Range_minimum LAB/Lab1/Range_minimum_query.cpp)
add_executable(Telco_data LAB/Lab1/Telco_data.cpp)

add_executable(P_2_1 P_2/P_2_1.cpp)
add_executable(P_2_2 P_2/P_2_2.cpp)
add_executable(P_2_3 P_2/P_2_3.cpp)
add_executable(P_2_4 P_2/P_2_4.cpp)