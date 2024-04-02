/**
 * @file Body.cpp
 * @author shash
 */
#include "pch.h"
#include "Body.h"

Body::Body()
{
    mSink.SetComponent(this);

}
void Body::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPolygon.Draw(graphics);

}
void Body::Update(double elapsed)
{

}
void Body::InstallPhysics(std::shared_ptr<b2World> world, std::shared_ptr<ContactListener> contactListener)
{
    mPolygon.InstallPhysics(world);

}
void Body::Rotate(double rotation, double velocity)
{
    mPolygon.SetAngularVelocity(velocity);

}

void Body::SetInitialPosition(wxPoint2DDouble position){
    mPolygon.SetInitialPosition(position.m_x, position.m_y);
}
void Body::Reset()
{

}
