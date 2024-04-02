/**
 * @file Conveyor.cpp
 * @author shash
 */

#include "pch.h"
#include "Conveyor.h"

/// The offset from the bottom center of the conveyor
/// to the center of the drive shaft.  48
const auto ConveyorShaftOffset = wxPoint2DDouble(48, 4);

/// The size of the conveyor in cm
const auto ConveyorSize = wxSize(125, 14);

/// The conveyor image to use
const std::wstring ConveyorImageName = L"/conveyor.png";

void Conveyor::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mConveyor.Draw(graphics);

}

void Conveyor::Update(double elapsed)
{
    auto contact = mConveyor.GetBody()->GetContactList();
    while(contact != nullptr)
    {
        if(contact->contact->IsTouching())
        {
            contact->other->SetLinearVelocity(b2Vec2(mVelocity, 0));
        }

        contact = contact->next;
    }

}
void Conveyor::Rotate(double rotation, double velocity)
{
    mVelocity = -velocity;

}
void Conveyor::Reset()
{
    mVelocity = 0;


}
void Conveyor::InstallPhysics(std::shared_ptr<b2World> world, std::shared_ptr<ContactListener> contactListener)
{
    mConveyor.InstallPhysics(world);
    contactListener->Add(mConveyor.GetBody(), this);


}
Conveyor::Conveyor(std::wstring imagesDir)
{
    mSink.SetComponent(this);
    mConveyor.BottomCenteredRectangle(ConveyorSize);
    mConveyor.SetImage(imagesDir + ConveyorImageName);
}
void Conveyor::SetPosition(double x, double y)
{
    mConveyor.SetInitialPosition(x, y);
    mXPos = x;
    mYPos = y;

}
void Conveyor::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
    contact->SetTangentSpeed(mVelocity);
}
wxPoint2DDouble Conveyor::GetShaftPosition(){
    wxPoint2DDouble conveyorPosition = wxPoint2DDouble(mXPos, mYPos);
    return conveyorPosition + ConveyorShaftOffset;

}
wxPoint2DDouble Conveyor::GetPosition(){
    wxPoint2DDouble conveyorPosition = wxPoint2DDouble(mXPos, mYPos);
    return conveyorPosition;
}