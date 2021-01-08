cmake_minimum_required(VERSION 3.9)
project(Turbohiker)

set(CMAKE_CXX_STANDARD 11)

add_executable(Turbohiker main.cpp)
# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile



#include_directories(./../turbohiker)
#target_link_libraries(Turbohiker ${./../turbohiker/cmake-build-debug/libturbohiker.so})
#find_library(TEST_LIBRARY turbohiker lib)
#target_link_libraries(Turbohiker LINK_PUBLIC ${TEST_LIBRARY})
#add_library(turbohiker SHARED logic/Entity.cpp logic/Entity.h logic/World.cpp logic/World.h  logic/Hiker.cpp logic/Hiker.h logic/Factories/HikerFactory.h logic/Lanes.h logic/Singletons/Transformation.cpp logic/Singletons/Transformation.h logic/Collider.cpp logic/Collider.h logic/Singletons/RandomeNumber.cpp logic/Singletons/RandomeNumber.h logic/HikerPlayer.cpp logic/HikerPlayer.h logic/HikerEnemy.cpp logic/HikerEnemy.h logic/HikerPassing.cpp logic/HikerPassing.h logic/Factories/LayoutFactory.h  logic/Layout.h logic/Observer/SubjectInterface.h logic/Observer/ObserverInterface.h logic/Observer/Subject.cpp logic/Observer/Subject.h logic/Observer/Observer.cpp logic/Observer/Observer.h logic/ScoreTextField.h  logic/Coordinates.h)
#SET(SRC main.cpp sfml/Game.cpp sfml/Game.h sfml/HikerSFML.cpp sfml/HikerSFML.h sfml/Factories/HikerFactories/PlayerFactory.cpp sfml/Factories/HikerFactories/PlayerFactory.h sfml/LanesSFML.cpp sfml/LanesSFML.h sfml/Factories/LayoutFactories/LineFactory.cpp sfml/Factories/LayoutFactories/LineFactory.h sfml/Factories/HikerFactories/KnightFactory.cpp sfml/Factories/HikerFactories/KnightFactory.h sfml/PlayerSFML.cpp sfml/PlayerSFML.h sfml/EnemySFML.cpp sfml/EnemySFML.h  sfml/Factories/HikerFactories/EnemyFactory.cpp sfml/Factories/HikerFactories/EnemyFactory.h sfml/PassingSFML.cpp sfml/PassingSFML.h sfml/Factories/HikerFactories/VerminFactory.cpp sfml/Factories/HikerFactories/VerminFactory.h sfml/Factories/LayoutFactories/SpeechBubbleFactory.cpp sfml/Factories/LayoutFactories/SpeechBubbleFactory.h sfml/SpeechBubbleSFML.h sfml/TextFieldSFML.cpp sfml/TextFieldSFML.h sfml/Factories/LayoutFactories/ScoreFactory.cpp sfml/Factories/LayoutFactories/ScoreFactory.h)
#SET(SRC main.cpp)



SET(SRC main.cpp sfml/Game.cpp sfml/Game.h logic/Entity.cpp logic/Entity.h logic/World.cpp logic/World.h sfml/HikerSFML.cpp sfml/HikerSFML.h logic/Hiker.cpp logic/Hiker.h logic/Factories/HikerFactory.h sfml/Factories/HikerFactories/PlayerFactory.cpp sfml/Factories/HikerFactories/PlayerFactory.h sfml/LanesSFML.cpp sfml/LanesSFML.h sfml/Factories/LayoutFactories/LineFactory.cpp sfml/Factories/LayoutFactories/LineFactory.h logic/Singletons/Transformation.cpp logic/Singletons/Transformation.h logic/Collider.cpp logic/Collider.h logic/Singletons/RandomeNumber.cpp logic/Singletons/RandomeNumber.h sfml/Factories/HikerFactories/KnightFactory.cpp sfml/Factories/HikerFactories/KnightFactory.h sfml/PlayerSFML.cpp sfml/PlayerSFML.h logic/HikerPlayer.cpp logic/HikerPlayer.h sfml/EnemySFML.cpp sfml/EnemySFML.h logic/HikerEnemy.cpp logic/HikerEnemy.h sfml/Factories/HikerFactories/EnemyFactory.cpp sfml/Factories/HikerFactories/EnemyFactory.h logic/HikerPassing.cpp logic/HikerPassing.h sfml/PassingSFML.cpp sfml/PassingSFML.h logic/Factories/LayoutFactory.h sfml/Factories/HikerFactories/VerminFactory.cpp sfml/Factories/HikerFactories/VerminFactory.h sfml/Factories/LayoutFactories/SpeechBubbleFactory.cpp sfml/Factories/LayoutFactories/SpeechBubbleFactory.h logic/Layout.h sfml/SpeechBubbleSFML.cpp sfml/SpeechBubbleSFML.h logic/Observer/SubjectInterface.h logic/Observer/ObserverInterface.h logic/Observer/Subject.cpp logic/Observer/Subject.h logic/Observer/Observer.cpp logic/Observer/Observer.h sfml/TextFieldSFML.cpp sfml/TextFieldSFML.h sfml/Factories/LayoutFactories/ScoreFactory.cpp sfml/Factories/LayoutFactories/ScoreFactory.h logic/Coordinates.h)


# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(Turbohiker_sfml ${SRC})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(Turbohiker_sfml ${SFML_LIBRARIES})

INSTALL(TARGETS Turbohiker_sfml DESTINATION ${PROJECT_SOURCE_DIR}/bin)