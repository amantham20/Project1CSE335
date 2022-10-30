cmake_minimum_required(VERSION 3.23)
project(SpartyLib)

set(SOURCE_FILES pch.h MainFrame.cpp MainFrame.h SpartyView.cpp SpartyView.h SpartyGame.cpp SpartyGame.h Score.cpp Score.h Item.cpp Item.h ScoreDisplay.cpp ScoreDisplay.h Score.cpp Slingshot.cpp Slingshot.h WoodenSlingshot.cpp WoodenSlingshot.h Goalpost.cpp Goalpost.h Level.cpp Level.h Physics.cpp Physics.h PositionalItem.cpp PositionalItem.h Block.h Block.cpp Poly.cpp Poly.h Picture.cpp Picture.h Consts.h Background.cpp Background.h BodyItem.cpp BodyItem.h PictureManager.cpp PictureManager.h Foe.cpp Foe.h Angry.cpp Angry.h ids.h HelmetSparty.cpp HelmetSparty.h GruffSparty.cpp GruffSparty.h DebugDraw.h DebugDraw.cpp ids.h PlayingArea.cpp PlayingArea.h ItemVisitor.h SpartyTracker.cpp SpartyTracker.h FoeTracker.cpp FoeTracker.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} box2d)

include(FetchContent)
FetchContent_Declare(
        box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v2.4.1
)

FetchContent_MakeAvailable(box2d)
include_directories(${box2d_SOURCE_DIR}/include/box2d)

