/**
 * @file Pulley.cpp
 * @author Shashank Jayaram
 */
#include "pch.h"
#include "Pulley.h"
void Pulley::Reset()
{
    mVelocity = 0.0;
    mRotation = 0.0;

}
Pulley::Pulley(double radius) : mRadius(radius),  mAssociatedPulley(nullptr)
{
    mSink.SetComponent(this);
    auto diameter = mRadius *2;
    mPulley.CenteredSquare(diameter);
//    if (mAssociatedPulley)
//    mAssociatedPulley->mPulley.CenteredSquare(diameter);

}
void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics) {
    if (mAssociatedPulley) {
        double radiusFactor = mMultiplier / mAssociatedPulley->mMultiplier;

        auto topLineX = GetXPosition();
        auto topLineY = GetYPosition();
        auto botLineX = mAssociatedPulley->GetXPosition();
        auto botLineY = mAssociatedPulley->GetYPosition();

        double offset = 10 * radiusFactor; // Proportional offset based on radius

        topLineY += offset;
        botLineY += offset;

        graphics->PushState();
        wxPen pen(*wxBLACK, 1);
        graphics->SetPen(pen);
        graphics->StrokeLine(topLineX, topLineY, botLineX, botLineY);

        topLineY -= 2 * offset; // Adjust for the lower line position
        botLineY -= 2 * offset;

        graphics->StrokeLine(topLineX, topLineY, botLineX, botLineY);
        graphics->PopState();
    }

    mPulley.DrawPolygon(graphics, mXPos, mYPos, mRotation);
}


void Pulley::Rotate(double rotation, double velocity)
{
    mRotation = rotation;
    mRotation = mRotation * mMultiplier;
    mVelocity = velocity;
    mRotSource.Rotate(mRotation, mVelocity);
//    if (mAssociatedPulley)
//    mAssociatedPulley->Rotate(mRotation , mVelocity*mMultiplier);


}
void Pulley::Update(double elapsed)
{

}
void Pulley::SetImage(std::wstring img)
{
    mPulley.SetImage(img);


}
void Pulley::Drive(std::shared_ptr<Pulley> pulley)
{
    mAssociatedPulley = pulley;
    double multiplier = mAssociatedPulley->mRadius/ mRadius;
    mMultiplier = multiplier;

    mRotSource.AddSink(pulley->GetSink());
    pulley->mMultiplier = (mMultiplier/pulley->mMultiplier);

}
void Pulley::SetPosition(double x, double y)
{
    mXPos = x;
    mYPos = y;
}
void Pulley::InstallPhysics(std::shared_ptr<b2World> world, std::shared_ptr<ContactListener> contactListener)
{

}

