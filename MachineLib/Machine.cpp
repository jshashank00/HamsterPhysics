/**
 * @file Machine.cpp
 * @author shash
 */
#include "pch.h"
#include "Machine.h"
#include "ContactListener.h"
#include "Goal.h"

/// Gravity in meters per second per second
const float Gravity = -9.8f;

/// Number of velocity update iterations per step
const int VelocityIterations = 6;

/// Number of position update iterations per step
const int PositionIterations = 2;

Machine::Machine(int machineNum) {
    mWorld = std::make_shared<b2World>(b2Vec2(0.0f, Gravity));

    mMachineNum = machineNum ;

}
void Machine::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);

}
void Machine::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
   for (auto component: mComponents){
       component->Draw(graphics);
   }


}

/**
 * Update the machine in time
 * @param elapsed Elapsed time in seconds
 */
void Machine::Update(double elapsed)
{
    // Call Update on all of our components so they can advance in time
    for (auto component:mComponents){
        component->Update(elapsed);
    }
    // Advance the physics system one frame in time
    mWorld->Step(elapsed, VelocityIterations, PositionIterations);
}

void Machine::Reset(){
    mWorld = std::make_shared<b2World>(b2Vec2(0.0f, Gravity));


    // Create and install the contact filter
    mContactListener = std::make_shared<ContactListener>();
    mWorld->SetContactListener(mContactListener.get());

    for (auto component: mComponents){
        component->InstallPhysics(mWorld, mContactListener);
        component->Reset();

    }

}

//body.install physics mpolygon.installphysics
