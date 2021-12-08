cmake_minimum_required(VERSION 3.17)
project(GameSFML)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameSFML main.cpp Game/Game.cpp Game/Game.h Field/Field.cpp Field/Field.h Field/FieldView.cpp Field/FieldView.h GameObjects/GameObj.h Field/Tile.cpp Field/Tile.h GameObjects/EntranceAndExit/Entrance_and_Exit.cpp GameObjects/EntranceAndExit/Entrance_and_Exit.h Field/FieldGeneration/FieldBuilder.cpp Field/FieldGeneration/FieldBuilder.h Game/CollsionMap.cpp Game/CollsionMap.h GameObjects/Entity.cpp GameObjects/Entity.h GameObjects/Player/Player.cpp GameObjects/Player/Player.h GameObjects/ObjectView.cpp GameObjects/ObjectView.h GameObjects/Player/ControllerKeyboard.cpp GameObjects/Player/ControllerKeyboard.h GameObjects/Enemies/Turret/Turret.cpp GameObjects/Enemies/Turret/Turret.h GameObjects/Enemies/troll/Troll.cpp GameObjects/Enemies/troll/Troll.h GameObjects/Enemies/EnemyController.cpp GameObjects/Enemies/EnemyController.h Game/Controller.h GameObjects/Item.cpp GameObjects/Items/Item.h GameObjects/GameObj.cpp GameObjects/Enemies/Goblin/Goblin.cpp GameObjects/Enemies/Goblin/Goblin.h GameObjects/Items/HealPotion/HealPotion.cpp GameObjects/Items/HealPotion/HealPotion.h GameObjects/Items/Sword/Sword.cpp GameObjects/Items/Sword/Sword.h GameObjects/Items/Hyperstone/Hyperstone.cpp GameObjects/Items/Hyperstone/Hyperstone.h)

include_directories(headers c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(GameSFML ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()


# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
