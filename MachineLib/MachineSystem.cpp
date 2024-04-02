/**
 * @file MachineSystem.cpp
 * @author shash
 */
#include "pch.h"
#include "MachineSystem.h"
#include "Machine.h"
#include "Machine1Factory.h"
#include "Machine2Factory.h"
using namespace std;

/**
 * Constructor
 * @param resourcesDir Resources directory
 */
MachineSystem::MachineSystem(std::wstring resourcesDir) :
    mResourcesDir(resourcesDir)
{

   // mMachine = make_shared<Machine>();
//   Machine1Factory factory(resourcesDir);
//   mMachine = factory.Create();
   SetMachineNumber(GetMachineNumber());

}
void MachineSystem::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) {


    graphics->PushState();
    graphics->Translate(mLocation.x, mLocation.y);
    graphics->Scale(mPixelsPerCentimeter, -mPixelsPerCentimeter);
    mMachine->Draw(graphics);



    graphics->PopState();

}
void MachineSystem::SetLocation(wxPoint location) {
 mLocation = location;
}
void MachineSystem::SetMachineNumber(int machine) {
    mMachineNum = machine;
    std::cout << mMachineNum;
    if (mMachineNum == 1){
        Machine1Factory factory(mResourcesDir);
        mMachine = factory.Create();

    }
    if (mMachineNum == 2){
        //mMachine = std::make_shared<Machine>(2);

        Machine2Factory factory2(mResourcesDir);
        mMachine = factory2.Create();


    }

    mMachine->Reset();

}
void MachineSystem::SetMachineFrame(int frame) {
    if(frame < mFrame)
    {
        mFrame = 0;
        mMachine->Reset();
    }

    for( ; mFrame < frame;  mFrame++)
    {
        mMachine->Update(1.0 / mFrameRate);
    }
    mTime = mFrame/mFrameRate;
    // May need more than these, but you'll figure that out...
}
double MachineSystem::GetMachineTime() {
    return mTime;
}
void MachineSystem::SetFrameRate(double rate) {
    mFrameRate = rate;
}
