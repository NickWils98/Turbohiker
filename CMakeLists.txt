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
SET(SRC main.cpp Game.cpp Game.h logic/Entity.cpp logic/Entity.h logic/World.cpp logic/World.h sfml/HikerSFML.cpp sfml/HikerSFML.h logic/Hiker.cpp logic/Hiker.h Factory/HikerFactory/HikerFactory.h Factory/HikerFactory/PlayerFactory.cpp Factory/HikerFactory/PlayerFactory.h sfml/LanesSFML.cpp sfml/LanesSFML.h logic/Lanes.cpp logic/Lanes.h Factory/LayoutFactory/LineFactory.cpp Factory/LayoutFactory/LineFactory.h logic/Singletons/Transformation.cpp logic/Singletons/Transformation.h logic/Collider.cpp logic/Collider.h logic/Singletons/RandomeNumber.cpp logic/Singletons/RandomeNumber.h Factory/HikerFactory/KnightFactory.cpp Factory/HikerFactory/KnightFactory.h sfml/PlayerSFML.cpp sfml/PlayerSFML.h logic/HikerPlayer.cpp logic/HikerPlayer.h sfml/EnemySFML.cpp sfml/EnemySFML.h logic/HikerEnemy.cpp logic/HikerEnemy.h Factory/HikerFactory/EnemyFactory.cpp Factory/HikerFactory/EnemyFactory.h logic/HikerPassing.cpp logic/HikerPassing.h sfml/PassingSFML.cpp sfml/PassingSFML.h Factory/LayoutFactory/LayoutFactory.h Factory/HikerFactory/VerminFactory.cpp Factory/HikerFactory/VerminFactory.h Factory/LayoutFactory/SpeechBubbleFactory.cpp Factory/LayoutFactory/SpeechBubbleFactory.h logic/Balloon.cpp logic/Balloon.h sfml/SpeechBubbleSFML.cpp sfml/SpeechBubbleSFML.h logic/Observer/SubjectInterface.cpp logic/Observer/SubjectInterface.h logic/Observer/ObserverInterface.cpp logic/Observer/ObserverInterface.h logic/Observer/Subject.cpp logic/Observer/Subject.h logic/Observer/Observer.cpp logic/Observer/Observer.h logic/ScoreTextField.cpp logic/ScoreTextField.h sfml/TextFieldSFML.cpp sfml/TextFieldSFML.h Factory/LayoutFactory/ScoreFactory.cpp Factory/LayoutFactory/ScoreFactory.h logic/Coordinates.cpp logic/Coordinates.h)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(Turbohiker_sfml ${SRC})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(Turbohiker_sfml ${SFML_LIBRARIES})

INSTALL(TARGETS Turbohiker_sfml DESTINATION ${PROJECT_SOURCE_DIR}/bin)