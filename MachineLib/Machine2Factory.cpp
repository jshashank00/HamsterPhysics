/**
 * @file Machine2Factory.cpp
 * @author shash
 */
#include "pch.h"
#include "Machine2Factory.h"

#include "Machine.h"
#include "Body.h"
#include "Goal.h"
#include "Pulley.h"
#include "Hamster.h"
#include "Conveyor.h"
#include "HamsterAndConveyorFactory.h"
#include "Basket.h"
#include "HCFactory2.h"

/// The images directory in resources
const std::wstring ImagesDirectory = L"/images";


/**
 * Constructor
 * @param resourcesDir Path to the resources directory
 */
Machine2Factory::Machine2Factory(std::wstring resourcesDir) :
    mResourcesDir(resourcesDir)
{
    mImagesDir = mResourcesDir + ImagesDirectory;
}



/**
 * Factory method to create machine #1
 * @return
 */
std::shared_ptr<Machine> Machine2Factory::Create()
{
    // The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor, so it knows
    // its number.
    auto machine = std::make_shared<Machine>(2);

    // Notice: All dimensions are in centimeters and assumes
    // the Y axis is positive in the up direction.

    const double FloorWidth = 600;
    const double FloorHeight = 15;

    //
    // The floor
    //
    // The values are chosen so the top of the floor
    // is at Y=0
    //
    auto floor = std::make_shared<Body>();
    floor->GetPolygon()->Rectangle(-FloorWidth/2, -FloorHeight, FloorWidth, FloorHeight);
    floor->GetPolygon()->SetImage(mImagesDir + L"/floor.png");
    machine->AddComponent(floor);

    //
    // Create the top beam and the basketball
    // that rolls off of it
    //
    TopBeamAndRamp(machine);

    //
    // Create the beam with the hamster driving a
    // spinning arm that hits the ball to make it roll
    //
    BeamAndSpinningArm(machine);

    //
    // Create a stack of dominos
    //
    const auto DominoStack1Position = wxPoint2DDouble(-230, 0);

    DominoStack(machine, DominoStack1Position);

//    //
//    // Create another stack of dominos
//    //
//    const auto DominoStack2Position = wxPoint2DDouble(115, 0);
//
//    DominoStack(machine, DominoStack2Position);

    auto basket = std::make_shared<Basket>(mImagesDir);
     basket->SetPosition(-250, 0);
     basket->BasketAnimation(wxPoint2DDouble(1, 7));
     machine->AddComponent(basket);

    auto br7 = std::make_shared<Basket>(mImagesDir);
    br7->SetPosition(250, 0);
    br7->BasketAnimation(wxPoint2DDouble(-1, 8));
    machine->AddComponent(br7);

//    auto basket4 = std::make_shared<Basket>(mImagesDir);
//    basket4->SetPosition(170, 80);
//    basket4->BasketAnimation(wxPoint2DDouble(-1, 8));
//    machine->AddComponent(basket4);

    auto basket2 = std::make_shared<Basket>(mImagesDir);
    basket2->SetPosition(200, 0);
    basket2->BasketAnimation(wxPoint2DDouble(1, 7));
    machine->AddComponent(basket2);
//    auto basket3 = std::make_shared<Basket>(mImagesDir);
//    basket3->SetPosition(150, 0);
//    basket3->BasketAnimation(wxPoint2DDouble(-1, 8));
//    machine->AddComponent(basket3);

//    auto basket5 = std::make_shared<Basket>(mImagesDir);
//    basket5->SetPosition(100, 0);
//    basket5->BasketAnimation(wxPoint2DDouble(-1, 8));
//    machine->AddComponent(basket5);

    auto basketball3 = std::make_shared<Body>();
    basketball3->GetPolygon()->Circle(12);
    basketball3->GetPolygon()->SetImage(mImagesDir + L"/basketball2.png");
    basketball3->GetPolygon()->SetInitialPosition(-90, 360);
    basketball3->GetPolygon()->SetDynamic();
    basketball3->GetPolygon()->SetPhysics(1, 0.5, 0.72);
    machine->AddComponent(basketball3);

    auto basketball9 = std::make_shared<Body>();
    basketball9->GetPolygon()->Circle(12);
    basketball9->GetPolygon()->SetImage(mImagesDir + L"/basketball2.png");
    basketball9->GetPolygon()->SetInitialPosition(-250, 60);
    basketball9->GetPolygon()->SetDynamic();
    basketball9->GetPolygon()->SetPhysics(1, 0.5, 0.72);
    machine->AddComponent(basketball9);


    auto basketball4 = std::make_shared<Body>();
    basketball4->GetPolygon()->Circle(12);
    basketball4->GetPolygon()->SetImage(mImagesDir + L"/basketball2.png");
    basketball4->GetPolygon()->SetInitialPosition(250, 30);
    basketball4->GetPolygon()->SetDynamic();
    basketball4->GetPolygon()->SetPhysics(1, 0.5, 0.72);
    machine->AddComponent(basketball4);

    auto basketball5 = std::make_shared<Body>();
    basketball5->GetPolygon()->Circle(12);
    basketball5->GetPolygon()->SetImage(mImagesDir + L"/basketball2.png");
    basketball5->GetPolygon()->SetInitialPosition(200, 50);
    basketball5->GetPolygon()->SetDynamic();
    basketball5->GetPolygon()->SetPhysics(1, 0.5, 0.72);
    machine->AddComponent(basketball5);

    auto basketball6 = std::make_shared<Body>();
    basketball6->GetPolygon()->Circle(12);
    basketball6->GetPolygon()->SetImage(mImagesDir + L"/basketball1.png");
    basketball6->GetPolygon()->SetInitialPosition(250, 60);
    basketball6->GetPolygon()->SetDynamic();
    basketball6->GetPolygon()->SetPhysics(1, 0.5, 0.72);
    machine->AddComponent(basketball6);





    //
    // Create a factory that will manufacture hamster, pulley,
    // pulley, and conveyor assemblies
    //
    HCFactory2 HCFactory2(machine, mImagesDir);




    HCFactory2.Create(wxPoint2DDouble(-50, 0), wxPoint2DDouble(100, 90));
    HCFactory2.AddBall(40);
    //auto hamster1 = HCFactory2.GetHamster();
    auto conveyor1 = HCFactory2.GetConveyor();
    //hamster1->SetSpeed(-1);

//
//
//
   wxPoint2DDouble conveyor2position(-180, 130);
//
//    // Dominos on a beam that the conveyor ball will knock down.
//    // Add this first, so it is behind the second conveyor pulleys
//    DominoesOnBeam(machine, conveyor2position + wxPoint2DDouble(140, 0));
//
//    HCFactory2.Create(conveyor1->GetPosition() + wxPoint2DDouble(-105, -40), conveyor2position);
//    HCFactory2.AddBall(-40);
//    //auto hamster2 = HCFactory2.GetHamster();
//    //auto conveyor2 = HCFactory2.GetConveyor();




    wxPoint2DDouble conveyor3position(150, 200);

//    HCFactory2.Create(conveyor2position + wxPoint2DDouble(260, 20), conveyor3position);
//    HCFactory2.AddBall(-40);
//    auto hamster3 = HCFactory2.GetHamster();
//    hamster3->SetSpeed(1.5);
    //auto conveyor3 = HCFactory2.GetConveyor();



    //
    // We add the baskedball goal last, so all basketballs
    // will draw behind it.
    //
    BasketballGoal(machine);

    return machine;
}



/**
 * Generate the top beam and its basketball
 *
 * The top beam and ramp and basketball that
 * rolls right and goes through the hoop.
 * @param machine Beam to generate
 */
void Machine2Factory::TopBeamAndRamp(std::shared_ptr<Machine> machine)
{
    const double BeamX = -25;
    auto beam1 = std::make_shared<Body>();
    beam1->GetPolygon()->BottomCenteredRectangle(400, 20);
    beam1->GetPolygon()->SetImage(mImagesDir + L"/beam.png");
    beam1->GetPolygon()->SetInitialPosition(BeamX, 300);
    machine->AddComponent(beam1);

    auto wedge1 = std::make_shared<Body>();
    wedge1->GetPolygon()->AddPoint(-25, 0);
    wedge1->GetPolygon()->AddPoint(25, 0);
    wedge1->GetPolygon()->AddPoint(25, 4.5);
    wedge1->GetPolygon()->AddPoint(-25, 25);
    wedge1->GetPolygon()->SetImage(mImagesDir + L"/wedge.png");
    wedge1->GetPolygon()->SetInitialPosition(BeamX-175, 320);
    machine->AddComponent(wedge1);

    // Basketball 1
    auto basketball1 = std::make_shared<Body>();
    basketball1->GetPolygon()->Circle(12);
    basketball1->GetPolygon()->SetImage(mImagesDir + L"/basketball1.png");
    basketball1->GetPolygon()->SetInitialPosition(BeamX-186, 353);
    basketball1->GetPolygon()->SetDynamic();
    basketball1->GetPolygon()->SetPhysics(1, 0.5, 0.6);
    machine->AddComponent(basketball1);
}

/**
 * Create a stack of 9 dominos.
 * @param machine Machine to add to
 * @param position The position to draw the domino stack at
 */
void Machine2Factory::DominoStack(std::shared_ptr<Machine> machine, wxPoint2DDouble position)
{
    Domino(machine, position + wxPoint2DDouble(30, DominoHeight/2), 0, DominoColor::Red);
    Domino(machine, position + wxPoint2DDouble(10, DominoHeight/2), 0, DominoColor::Blue);
    Domino(machine, position + wxPoint2DDouble(20, DominoHeight + DominoWidth/2), 0.25, DominoColor::Green);

    Domino(machine, position + wxPoint2DDouble(-10, DominoHeight/2), 0, DominoColor::Red);
    Domino(machine, position + wxPoint2DDouble(-30, DominoHeight/2), 0, DominoColor::Green);
    Domino(machine, position + wxPoint2DDouble(-20, DominoHeight + DominoWidth/2), 0.25, DominoColor::Black);

    const int DominoLevel2 = DominoHeight + DominoWidth;

    Domino(machine, position + wxPoint2DDouble(10, DominoLevel2 + DominoHeight/2), 0, DominoColor::Red);
    Domino(machine, position + wxPoint2DDouble(-10, DominoLevel2 + DominoHeight/2), 0, DominoColor::Green);
    Domino(machine, position + wxPoint2DDouble(0, DominoLevel2 + DominoHeight + DominoWidth/2), 0.25, DominoColor::Black);
}

/**
 * This is the second beam from the top and the spinning arm that hits the ball
 * @param machine Machine to add to
 */
void Machine2Factory::BeamAndSpinningArm(std::shared_ptr<Machine> machine)
{
    const double Beam2X = -25;
    auto beam2 = std::make_shared<Body>();
    beam2->GetPolygon()->BottomCenteredRectangle(400, 20);
    beam2->GetPolygon()->SetImage(mImagesDir + L"/beam.png");
    beam2->GetPolygon()->SetInitialPosition(Beam2X, 240);
    machine->AddComponent(beam2);

    // Basketball 2
    auto basketball2 = std::make_shared<Body>();
    basketball2->GetPolygon()->Circle(12);
    basketball2->GetPolygon()->SetImage(mImagesDir + L"/basketball2.png");
    basketball2->GetPolygon()->SetInitialPosition(Beam2X - 170, 240 + 12 + 20);
    basketball2->GetPolygon()->SetDynamic();
    basketball2->GetPolygon()->SetPhysics(1, 0.5, 0.75);
    machine->AddComponent(basketball2);

    // Basketball 7
    auto basketball7 = std::make_shared<Body>();
    basketball7->GetPolygon()->Circle(12);
    basketball7->GetPolygon()->SetImage(mImagesDir + L"/basketball1.png");
    basketball7->GetPolygon()->SetInitialPosition(Beam2X - 150, 240 + 12 + 20);
    basketball7->GetPolygon()->SetDynamic();
    basketball7->GetPolygon()->SetPhysics(1, 0.5, 0.75);
    machine->AddComponent(basketball7);

    // Basketball 8

    auto basketball8 = std::make_shared<Body>();
    basketball8->GetPolygon()->Circle(12);
    basketball8->GetPolygon()->SetImage(mImagesDir + L"/basketball1.png");
    basketball8->GetPolygon()->SetInitialPosition(-150,  50);
    basketball8->GetPolygon()->SetDynamic();
    basketball8->GetPolygon()->SetPhysics(1, 0.5, 0.75);
    machine->AddComponent(basketball8);





    auto hamster = std::make_shared<Hamster>(mImagesDir);
    hamster->SetPosition(-220, 185);
    hamster->SetInitiallyRunning(true);      // Initially running
    hamster->SetSpeed(0.60);
    machine->AddComponent(hamster);
    auto hamster1shaft = hamster->GetShaftPosition();

    auto arm = std::make_shared<Body>();
    arm->GetPolygon()->SetInitialPosition(hamster1shaft.m_x, hamster1shaft.m_y);
    arm->GetPolygon()->AddPoint(-7, 10);
    arm->GetPolygon()->AddPoint(7, 10);
    arm->GetPolygon()->AddPoint(7, -60);
    arm->GetPolygon()->AddPoint(-7, -60);
    arm->GetPolygon()->SetImage(mImagesDir + L"/arm.png");
    arm->GetPolygon()->SetKinematic();
    machine->AddComponent(arm);

    hamster->GetSource()->AddSink(arm->GetSink());
}

/**
 * Add the basketball goal to the machine
 * @param machine Machine to add to
 */
void Machine2Factory::BasketballGoal(std::shared_ptr<Machine> machine)
{
    auto goal = std::make_shared<Goal>(mImagesDir);
    goal->SetPosition(270, 0);
    machine->AddComponent(goal);


}

/**
 * Create the beam that has 10 dominoes on it.
 * @param machine Machine to add bem to
 * @param position Location to place the beam.
 */
void Machine2Factory::DominoesOnBeam(std::shared_ptr<Machine> machine, wxPoint2DDouble position)
{
    // The beam the dominoes sit on
    auto beam = std::make_shared<Body>();
    beam->GetPolygon()->BottomCenteredRectangle(150, 15);
    beam->GetPolygon()->SetImage(mImagesDir + L"/beam.png");
    beam->GetPolygon()->SetInitialPosition(position.m_x, position.m_y);
    machine->AddComponent(beam);

    for(int d=0; d<10; d++)
    {
        // Where to put this domino
        auto dominos = position + wxPoint2DDouble(-70 + d * 15, 27);

        Domino(machine, dominos, 0, DominoColor::Green);
    }
}


/**
 * Create a Domino and add it to the machine.
 *
 * This has been created to make it easier to create
 * a lot of dominos
 *
 * @param machine Machine to add the domino to
 * @param position Position to place the center of the domino
 * @param rotation Rotation in turns
 * @param color Color code
 * @return Returns the created domino body
 */
std::shared_ptr<Body>  Machine2Factory::Domino(std::shared_ptr<Machine> machine, wxPoint2DDouble position, double rotation, DominoColor color)
{
    auto x = position.m_x;
    auto y = position.m_y;

    auto domino = std::make_shared<Body>();
    domino->GetPolygon()->Rectangle(-DominoWidth/2, -DominoHeight/2, DominoWidth, DominoHeight);
    switch(color)
    {
        case DominoColor::Black:
            domino->GetPolygon()->SetImage(mImagesDir + L"/domino-black.png");
            break;

        case DominoColor::Red:
            domino->GetPolygon()->SetImage(mImagesDir + L"/domino-red.png");
            break;

        case DominoColor::Green:
            domino->GetPolygon()->SetImage(mImagesDir + L"/domino-green.png");
            break;

        case DominoColor::Blue:
            domino->GetPolygon()->SetImage(mImagesDir + L"/domino-blue.png");
            break;
    }

    domino->GetPolygon()->SetInitialPosition(x, y);
    domino->GetPolygon()->SetInitialRotation(rotation);
    domino->GetPolygon()->SetDynamic();
    machine->AddComponent(domino);

    return domino;
}