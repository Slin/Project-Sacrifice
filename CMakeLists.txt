#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)
project(Project-Sacrifice)

# Enable debug symbols by default
#if(CMAKE_BUILD_TYPE STREQUAL "")
#    set(CMAKE_BUILD_TYPE Debug)
#endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

# Define sources and executable
set(EXECUTABLE_NAME "Project_Sacrifice")

set(SOURCE_FILES
        source/main.cpp
        source/Entity.h
        source/World.cpp
        source/World.h
        source/TexturePool.cpp
        source/TexturePool.h
        source/EntityManager.cpp
        source/EntityManager.h
        source/PhysicsEntity.cpp
        source/PhysicsEntity.h
        source/Background.cpp
        source/Background.h source/Ragdoll.cpp source/Ragdoll.h source/Animal.cpp source/Animal.h source/Priest.cpp source/Priest.h source/ParticleEmitter.cpp source/ParticleEmitter.h source/BloodParticle.cpp source/BloodParticle.h)
add_executable(Project_Sacrifice ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Detect and add SFML
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

# Detect and add BOX2D
find_package(BOX2D REQUIRED)
if(BOX2D_FOUND)
    include_directories(${BOX2D_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${BOX2D_LIBRARIES})
endif()


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

