cmake_minimum_required(VERSION 3.16...3.27)

project(mu2p_project)

option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/mac)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)
file(GLOB macros  ${PROJECT_SOURCE_DIR}/mac/*.mac)
file(COPY ${macros} DESTINATION ${PROJECT_BINARY_DIR}/Release)

add_executable(mu2p main.cpp ${sources} ${headers})
target_link_libraries(mu2p ${Geant4_LIBRARIES})

add_custom_target(mu2p_project DEPENDS mu2p)