cmake_minimum_required (VERSION 2.6)
project (Simulation)
# The version number.
set (Simulation_VERSION_MAJOR 1)
set (Simulation_VERSION_MINOR 0)

set (CMAKE_CXX_STANDARD 11)

message("Source directory: ")
message(${PROJECT_SOURCE_DIR})


# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# include_directories("${PROJECT_SOURCE_DIR}/simulation/")


####################################################
#################   Simulation things
####################################################

set(sim_SRC
   ${PROJECT_SOURCE_DIR}/simulation/main.c
   ${PROJECT_SOURCE_DIR}/simulation/globaldata.c
   ${PROJECT_SOURCE_DIR}/simulation/initializer.c
   ${PROJECT_SOURCE_DIR}/simulation/running.c)

add_library(sim STATIC ${sim_SRC})

target_include_directories(sim PUBLIC
  ${PROJECT_SOURCE_DIR}/simulation)

# add the executable
add_executable(simulation ${sim_SRC})

target_link_libraries(simulation m)




####################################################
##############   Plotting things
####################################################


find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/freeglut_mingw/include)


set(plotting_SRC
  ${PROJECT_SOURCE_DIR}/plotting/main.cpp
  ${PROJECT_SOURCE_DIR}/plotting/drawing.cpp
  ${PROJECT_SOURCE_DIR}/plotting/globaldata.cpp)

 
add_executable(plotting ${plotting_SRC})

target_link_libraries(plotting ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
target_link_libraries(plotting ${PROJECT_SOURCE_DIR}/freeglut_mingw/lib/libfreeglut.a)

target_link_libraries(plotting m)

if (UNIX)
  target_link_libraries(plotting glut)
endif (UNIX)



add_custom_command(
        TARGET simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/parameters/parameters.txt
                ${CMAKE_CURRENT_BINARY_DIR}/parameters/parameters.txt)

add_custom_command(
        TARGET plotting POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/freeglut_mingw/bin/freeglut.dll
                ${CMAKE_CURRENT_BINARY_DIR}/freeglut.dll)

 
