project(MachineLib)

set(SOURCE_FILES
        pch.h
        IMachineSystem.h
        MachineSystemFactory.cpp MachineSystemFactory.h
        MachineStandin.cpp MachineStandin.h
        Polygon.cpp Polygon.h
        DebugDraw.cpp DebugDraw.h
        Consts.h
        MachineDialog.cpp MachineDialog.h include/machine-api.h
        PhysicsPolygon.cpp
        PhysicsPolygon.h
        ContactListener.cpp
        ContactListener.h
        MachineSystemStandin.cpp
        MachineSystemStandin.h
        MachineSystem.cpp
        MachineSystem.h
        Machine.cpp
        Machine.h
        Component.cpp
        Component.h
        Machine1Factory.h
        Machine1Factory.cpp
        Body.cpp
        Body.h
        Goal.cpp
        Goal.h
        HamsterAndConveyorFactory.h
        HamsterAndConveyorFactory.cpp
        Hamster.cpp
        Hamster.h
        RotationSource.cpp
        RotationSource.h
        RotationSink.cpp
        RotationSink.h
        Pulley.cpp
        Pulley.h
        Conveyor.cpp
        Conveyor.h
        Machine2Factory.cpp
        Machine2Factory.h
        Basket.cpp
        Basket.h
        HCFactory2.cpp
        HCFactory2.h
)

# Removed:
# Motor.cpp Motor.h Pulley.cpp Pulley.h

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

#
# Use Box2D
#
include(FetchContent)
FetchContent_Declare(
        box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v2.4.1
)

FetchContent_MakeAvailable(box2d)
include_directories()

target_include_directories(${PROJECT_NAME} PUBLIC "${box2d_SOURCE_DIR}/include/box2d")
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} box2d)
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)