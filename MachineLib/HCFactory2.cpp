/**
 * @file HCFactory2.cpp
 * @author shash
 */
#include "pch.h"
#include "HamsterAndConveyorFactory.h"
#include "Hamster.h"
#include "Conveyor.h"
#include "Body.h"
//#include "Pulley.h"
#include "Machine.h"
#include "Pulley.h"
#include "HCFactory2.h"

/**
 * Create a hamster that is a conveyor.
 * @param hamsterPosition Where to place the hamster
 * @param conveyorPosition Where to place the conveyor
 */
void HCFactory2::Create(wxPoint2DDouble hamsterPosition, wxPoint2DDouble conveyorPosition)
{
    auto hamster = std::make_shared<Hamster>(mImagesDir);
    mHamster = hamster;
    hamster->SetPosition(hamsterPosition.m_x, hamsterPosition.m_y);
    mMachine->AddComponent(hamster);
    auto hamsterShaft = hamster->GetShaftPosition();

    auto conveyor = std::make_shared<Conveyor>(mImagesDir);
    mConveyor = conveyor;
    conveyor->SetPosition(conveyorPosition.m_x,conveyorPosition.m_y );
    mMachine->AddComponent(conveyor);
    auto conveyorShaft = conveyor->GetShaftPosition();
//
//    // The pulley driven by the hamster
    auto pulley1 = std::make_shared<Pulley>(30);
    pulley1->SetImage(mImagesDir + L"/pulley3.png");
    pulley1->SetPosition(hamsterShaft.m_x,hamsterShaft.m_y );
    mMachine->AddComponent(pulley1);
//
    hamster->GetSource()->AddSink(pulley1->GetSink());
//
    auto pulley2 = std::make_shared<Pulley>(10.0);
    pulley2->SetImage(mImagesDir + L"/pulley3.png");
    pulley2->SetPosition(conveyorShaft.m_x, conveyorShaft.m_y);
    mMachine->AddComponent(pulley2);
    //
    pulley1->Drive(pulley2);
//
    pulley2->GetSource()->AddSink(conveyor->GetSink());
}

/**
 * Add a ball onto the conveyor belt for the just created hamster
 * conveyor belt combination.
 * @param placement Placement left (negative) to right (positive)
 * @return Gall object
 */
std::shared_ptr<Body> HCFactory2::AddBall(double placement)
{
    // Ball
    auto ball = std::make_shared<Body>();
    ball->GetPolygon()->Circle(12);
    ball->GetPolygon()->SetImage(mImagesDir + L"/ball1.png");
    ball->GetPolygon()->SetInitialPosition(mConveyor->GetPosition().m_x + wxPoint2DDouble(placement, 26).m_x, mConveyor->GetPosition().m_y + wxPoint2DDouble(placement, 26).m_y);
    ball->GetPolygon()->SetDynamic();
    ball->GetPolygon()->SetPhysics(2, 0.5, 0.1);
    mMachine->AddComponent(ball);
    return ball;
}
