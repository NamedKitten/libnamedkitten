cmake_minimum_required(VERSION 3.6)
project(namedkitten CXX)
enable_language(CXX)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE namedkitten_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE namedkitten_HEADERS ${PROJECT_SOURCE_DIR}/include/*.hpp)

include_directories(namedkitten ${PROJECT_SOURCE_DIR}/include)


set(Boost_USE_STATIC_LIBS    ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost REQUIRED date_time)


option(STATIC_namedkitten "Build static library." ON)
option(SHARED_namedkitten "Build shared library" OFF)

if (STATIC_namedkitten)
  add_library(namedkitten STATIC ${namedkitten_SOURCES} ${namedkitten_HEADERS})
endif()

if (SHARED_namedkitten)
  add_library(namedkitten SHARED ${namedkitten_SOURCES} ${namedkitten_HEADERS})
endif()

set_target_properties(namedkitten PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(namedkitten ${Boost_LIBRARIES})
