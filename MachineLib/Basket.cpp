/**
 * @file Basket.cpp
 * @author shash
 */
#include "pch.h"
#include "Basket.h"

/// The size of the basket in centimeters
const double BasketSize = 40;

/// Delay between when the ball hits the basket
/// and when it is shot out
const double BasketDelay = 1.0;

/// The direction we shoot the ball out of the basket
const wxPoint2DDouble BasketShot = wxPoint2DDouble(1, 7);

/// Basket Image
const std::wstring BasketImage = L"/basket.png";


Basket::Basket(std::wstring resourcesDir) : mResourcesDir(std::move(resourcesDir))
{
    mBasket.SetImage(mResourcesDir + BasketImage);
    mBasket.BottomCenteredRectangle(BasketSize);
    mBottom.BottomCenteredRectangle(wxSize(BasketSize, 7));



    mLeft.BottomCenteredRectangle(5,BasketSize);


    mRight.BottomCenteredRectangle(5,BasketSize);



}

void Basket::Draw(std::shared_ptr<wxGraphicsContext> graphics){

    mBasket.DrawPolygon(graphics, mXPos, mYPos, 0);
}
void Basket::Update(double elapsed){
    if (mInside)
    {
        mSeconds += elapsed;
    }

}
void Basket::Rotate(double rotation, double velocity)
{

}
void Basket::Reset()
{
    mSeconds = 0;
    mInside = false;

}
void Basket::SetPosition(double x, double y)
{
    mXPos = x;
    mYPos = y;
    mBottom.SetInitialPosition(mXPos, mYPos);

    double leftOffset = mXPos - (BasketSize *1/2);
    double rightOffset = mXPos + (BasketSize *1/2);
    mLeft.SetInitialPosition(leftOffset, mYPos);
    mRight.SetInitialPosition(rightOffset, mYPos);


}
void Basket::InstallPhysics(std::shared_ptr<b2World> world, std::shared_ptr<ContactListener> contactListener)
{
    mBottom.InstallPhysics(world);
    mRight.InstallPhysics(world);
    mLeft.InstallPhysics(world);
    contactListener->Add(mBottom.GetBody(), this);

}
void Basket::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
    // Ensure that contact and its fixtures are valid
    if (!contact || !contact->GetFixtureA() || !contact->GetFixtureB()) {
        return;
    }

    // Ball has made contact with the basket
    mInside = true;

    // Increase the time counter if the ball is inside the basket
    if (mInside) {
        mSeconds++;
    }

    // Handle the situation when the ball has been in the basket longer than the allowed delay
    if (mSeconds >= BasketDelay)
    {
        // Reset tracking variables
        mSeconds = 0;
        mInside = false;

        // Call the helper function to handle the object in the basket
        InBasket(contact);
    }
}


void Basket::InBasket(b2Contact *contact) {
    // Retrieve the body of the object in the basket and set its new velocity
    b2Body* bodyInBasket = contact->GetFixtureB()->GetBody();
    if (bodyInBasket) {
        double horizontalVelocity = mMovement.m_x;
        double verticalVelocity = mMovement.m_y;
        bodyInBasket->SetLinearVelocity(b2Vec2(horizontalVelocity, verticalVelocity));
    }
}


void Basket::BasketAnimation(wxPoint2DDouble animation) {
    mMovement = animation;
}




