/**
 * @file MachineToCanadianAdapter.cpp
 * @author shash
 */
#include "pch.h"
#include "MachineToCanadianAdapter.h"
#include "MachineDlg.h"

MachineToCanadianAdapter::MachineToCanadianAdapter(const std::wstring &name, const std::wstring &resourcesDir, int num) : Drawable(name)
{
    MachineSystemFactory msFactory(resourcesDir);
    mMachineSystem = msFactory.CreateMachineSystem();
    mMachineSystem->SetMachineNumber(num);
    mMachineNumber = num;



}
void MachineToCanadianAdapter::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    int currentFrame = mTimeline->GetCurrentFrame();
    int difference = currentFrame - mStartFrame;

        double scale = 0.5f;
        graphics->PushState();
        graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
        graphics->Scale(scale, scale);
        mMachineSystem->SetLocation(wxPoint(600, 600));
        if (difference>= 0){
            mMachineSystem->SetMachineFrame(difference);
        }
        else{
            mMachineSystem->SetMachineFrame(0);
        }

        mMachineSystem->DrawMachine(graphics);
        graphics->PopState();



}
void MachineToCanadianAdapter::SetMachineFrames(int startFrame, int endFrame) {
    // Ensure the start frame is within the valid range
    if (startFrame >= 0 && startFrame < endFrame) {
        mStartFrame = startFrame;
        mEndFrame = endFrame;
    } else {
        // Handle invalid frame range
        // For example, throw an exception or handle it in a way suitable for your application
    }
}

bool MachineToCanadianAdapter::HitTest(wxPoint pos)
{
    return false;
}
void MachineToCanadianAdapter::SetTimeline(Timeline *timeline)
{
    //Drawable::SetTimeline(timeline);
    mTimeline = timeline;
}
void MachineToCanadianAdapter::SetKeyframe()
{
    //Drawable::SetKeyframe();
}
void MachineToCanadianAdapter::GetKeyframe()
{
    //Drawable::GetKeyframe();
}
void MachineToCanadianAdapter::SetActor(Actor *actor)
{
    Drawable::SetActor(actor);
}
void MachineToCanadianAdapter::SelectMachine(wxWindow *parent, int num)
{
    MachineDialog dlg(parent, mMachineSystem);
    if (dlg.ShowModal() == wxID_OK)
    {
        // A machine has been selected
        //mMachineSystem->SetMachineNumber(num);

    }
   mMachineNumber= mMachineSystem->GetMachineNumber();

}


void MachineToCanadianAdapter::SetMachineNumber(int num) {

    mMachineSystem->SetMachineNumber(num);

}

void MachineToCanadianAdapter::SetStartTime(int time){
    mStartFrame = time;
}
void MachineToCanadianAdapter::SetEndTime(int time){
    mEndFrame = time;
}

int MachineToCanadianAdapter::GetStartTime(){
    return mStartFrame;
}
int MachineToCanadianAdapter::GetEndTime(){
    return mEndFrame;
}
int MachineToCanadianAdapter::GetMachineNumber(){
    return mMachineNumber;
}