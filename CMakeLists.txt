cmake_minimum_required(VERSION 3.5.0)
project(middleware VERSION 0.1.0 LANGUAGES C CXX)

find_package(Boost COMPONENTS REQUIRED)
link_libraries(wsock32 ws2_32 ${Boost_LIBRARIES})
add_executable(client_ client_.cpp)
add_executable(server server.cpp)
add_executable(test test.cpp)



# For later use: used for printing variable names in cmake
# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()



