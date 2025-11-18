cmake_minimum_required(VERSION 3.15)
project(jogoDePerguntas VERSION 2.0 LANGUAGES C)

include(FetchContent)
FetchContent_Declare(
  nixjson
  GIT_REPOSITORY https://github.com/juliodf24/NixJson.git
  GIT_TAG developer
)
FetchContent_MakeAvailable(nixjson)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_executable(jogoperguntas ${SOURCES})

target_include_directories(jogoperguntas PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(jogoperguntas PRIVATE nixjson)
