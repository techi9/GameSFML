cmake_minimum_required(VERSION 3.17)
project(GameSFML)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameSFML main.cpp Game/Game.cpp Game/Game.h Field/Field.cpp Field/Field.h Field/FieldView.cpp Field/FieldView.h GameObjects/GameObj.h Field/Tile.cpp Field/Tile.h GameObjects/Entrance_and_Exit.cpp GameObjects/Entrance_and_Exit.h Field/FieldGeneration/FieldBuilder.cpp Field/FieldGeneration/FieldBuilder.h GameObjects/CollsionMap.cpp GameObjects/CollsionMap.h)

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
