cmake_minimum_required(VERSION 3.23)
project(SpartyLib)

set(SOURCE_FILES pch.h MainFrame.cpp MainFrame.h SpartyView.cpp SpartyView.h Shape.cpp Shape.h SpartyGame.cpp SpartyGame.h Score.cpp Score.h Item.cpp Item.h ScoreDisplay.cpp ScoreDisplay.h Score.cpp)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)