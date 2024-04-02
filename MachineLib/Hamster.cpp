/**
 * @file Hamster.cpp
 * @author shash
 */
#include "pch.h"
#include "Hamster.h"

/// The center point for drawing the wheel
/// relative to the bottom center of the cage
const auto WheelCenter = wxPoint2DDouble(-12, 24);

/// The size of the hamster cage in centimeters
const auto HamsterCageSize = wxSize(75, 50);

/// Size of the hamster wheel (diameter) in centimeters
const double HamsterWheelSize = 45;

/// Size of the hamster wheel (square) in centimeters
const double HamsterSize = 45;

/// How fast the hamster runs. This is now many cycles of
/// the 3 images we make per second as images 1, 2, 3, 2, ...
const double HamsterSpeed = 4.0;

/// The offset from the bottom center of the hamster cage
/// to the center of the output shaft.
const auto HamsterShaftOffset = wxPoint2DDouble(25, 40);

/// The image for the hamster cage
const std::wstring HamsterCageImage = L"/hamster-cage.png";

/// The image for the hamster wheel
const std::wstring HamsterWheelImage = L"/hamster-wheel.png";

/// The hamster images. Image 0 is sleeping, 1-3 are
/// the running hamster animation images.
const std::wstring HamsterImages[4] =
    {L"/hamster-sleep.png", L"/hamster-run-1.png",
        L"/hamster-run-2.png", L"/hamster-run-3.png"};



Hamster::Hamster(std::wstring imagesDir) : mImagesDir(std::move(imagesDir))
{
    //SetInitiallyRunning(false);
    mCage.BottomCenteredRectangle(HamsterCageSize);
    mCage.SetImage(mImagesDir + HamsterCageImage);
    for (int i = 0; i< mHamsters.size(); i++){
        mHamsters[i] = std::make_unique<cse335::Polygon>();
        mHamsters[i]->CenteredSquare(HamsterSize);
        if (mInitiallyRunning){
            i = 1;
        }
        mHamsters[i]->SetImage(mImagesDir + HamsterImages[i]);


    }
    //mInitiallyRunning = true;
//    mHamster.SetImage(mImagesDir + HamsterImages[0]);
//    mHamster.CenteredSquare(HamsterSize);


    mWheel.SetImage(mImagesDir + HamsterWheelImage);
    mWheel.CenteredSquare(HamsterWheelSize);

//    mHamster.BottomCenteredRectangle(HamsterSize);
//    mHamster.SetImage(mImagesDir + HamsterImages[0]);

}

void Hamster::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mCage.Draw(graphics);
    //mWheel.DrawPolygon(graphics, mXPos+ WheelCenter.m_x, mYPos + WheelCenter.m_y, mRotation);
    graphics->PushState();
    graphics->Translate(mXPos+ WheelCenter.m_x, mYPos + WheelCenter.m_y);
    mWheel.DrawPolygon(graphics, 0, 0, -mRotation);


    if(mSpeed < 0)
    {
        graphics->Scale(-1, 1);
        //mRotation = -mRotation;

    }

    //mHamsters[mHamsterImgNum]->DrawPolygon(graphics, mXPos+WheelCenter.m_x, mYPos+WheelCenter.m_y, mRotation);
    mHamsters[mHamsterImgNum]->DrawPolygon(graphics, 0, 0, 0);
   // mHamster.SetImage(mImagesDir + HamsterImages[mHamsterImgNum]);
    graphics->PopState();




}
void Hamster::Update(double elapsed)
{

   if (mInitiallyRunning || mAlreadyRunning){
       mHamsterImgNum = 1;
        mRotation -= mSpeed + elapsed;
       double rotation = mRotation * 2;
       if (rotation < 0) {
           rotation = -rotation; // Convert negative rotation to positive
       }
       mHamsterImgNum = (int)(rotation * HamsterSpeed) % 3 + 1;
       mRotationSource.Rotate(mRotation, -mSpeed);

   }
   else{
       mAlreadyRunning = false;
       mHamsterImgNum = 0;
   }

//        mHamsterImgNum = static_cast<int>(fabs(mRotation) *)
//    }

}


void Hamster::SetPosition(double x, double y)
{
//    mPost.SetInitialPosition(x+PostPosition.m_x, y+PostPosition.m_y);
//    mGoal.SetInitialPosition(x+GoalPosition.m_x, y+GoalPosition.m_y);
  mCage.SetInitialPosition(x, y);
  mXPos=x;
  mYPos=y;

}
void Hamster::InstallPhysics(std::shared_ptr<b2World> world, std::shared_ptr<ContactListener> contactListener)
{
    mCage.InstallPhysics(world);
    contactListener->Add(mCage.GetBody(), this);


}
void Hamster::SetInitiallyRunning(bool InitiallyRunning)
{

    mInitiallyRunning = InitiallyRunning;


}
void Hamster::BeginContact(b2Contact *contact)
{
    mAlreadyRunning = true;


//    b2ContactListener::BeginContact(contact);
}
void Hamster::SetSpeed(double speed)
{
    mSpeed = speed;

}
wxPoint2DDouble Hamster::GetShaftPosition()
{
    return wxPoint2DDouble(mXPos, mYPos) + HamsterShaftOffset;
}
void Hamster::Rotate(double rotation, double velocity)
{

}
void Hamster::Reset()
{
    //SetInitiallyRunning(mInitiallyRunning);
   //SetInitiallyRunning(true);
   //mHamster.SetImage(mImagesDir + HamsterImages[0]);
    //mInitiallyRunning = false; // Stop the hamster from running
    //mHamsterImgNum = 0; // Set the hamster image to the sleeping image (first image)
    mHamsterImgNum = 0;
    mAlreadyRunning = false;

}


