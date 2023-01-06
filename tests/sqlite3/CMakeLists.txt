cmake_minimum_required(VERSION 3.1) # for "CMAKE_CXX_STANDARD" version
project(sqliteCppTest VERSION 3.2.1)

#----------------------------------------------------------------
message(STATUS "project        : ${CMAKE_PROJECT_NAME}")
message(STATUS "Project version: ${PROJECT_VERSION}")
message(STATUS "CMake version  : ${CMAKE_VERSION}")
#----------------------------------------------------------------

# SQLiteC++ 3.x requires C++11 features
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 11)
elseif (CMAKE_CXX_STANDARD LESS 11)
    message(WARNING "CMAKE_CXX_STANDARD has been set to '${CMAKE_CXX_STANDARD}' which is lower than the minimum required standard (c++11).")
endif ()
message(STATUS "Using c++ standard c++${CMAKE_CXX_STANDARD}")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#----------------------------------------------------------------

  
file(GLOB SOURCES src/*.cpp)

include_directories(
	include
)


add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}
  sqlite3
  pthread
)