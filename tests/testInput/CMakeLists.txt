cmake_minimum_required (VERSION 3.12)
project (myPong)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Find SDL2 and its related libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
#find_package(SDL2_net REQUIRED)
#find_package(SDL2_gfx REQUIRED)


# message(${SDL2_INCLUDE_DIRS})
# message(${SDL2_LIBRARIES})
# message(${SDL2_TTF_INCLUDE_DIRS})
# message(${SDL2_TTF_LIBRARIES})
# message(${SDL2_IMAGE_INCLUDE_DIRS})
# message(${SDL2_IMAGE_LIBRARIES})
# message(${SDL2_MIXER_INCLUDE_DIRS})
# message(${SDL2_MIXER_LIBRARIES})



file(GLOB SOURCES *.cpp)

include_directories(
	include
	${SDL2_INCLUDE_DIRS}
	${SDL2_TTF_INCLUDE_DIRS}
	${SDL2_IMAGE_INCLUDE_DIRS}
	${SDL2_MIXER_INCLUDE_DIRS}
)

add_executable(pong ${SOURCES})

target_link_libraries(pong
	${SDL2_LIBRARIES}
	${SDL2_TTF_LIBRARIES}
	${SDL2_IMAGE_LIBRARIES}
	${SDL2_MIXER_LIBRARIES}
)