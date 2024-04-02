/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"


/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the resources for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

    auto picture = std::make_shared<Picture>();

    // Create the background and add it
    auto background = std::make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            std::make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    auto adapter1 = std::make_shared<Actor>(L"Machine Adapter");
    adapter1->SetPosition(wxPoint(0,0));
    auto machine = std::make_shared<MachineToCanadianAdapter>(L"Machine", resourcesDir, 1);
    adapter1->AddDrawable(machine);
    adapter1->SetRoot(machine);
    machine->SetMachineFrames(90, 300);
    picture->AddActor(adapter1);
    picture->SetMachine(machine);

    auto adapter2 = std::make_shared<Actor>(L"Machine Adapter 2");
    adapter2->SetPosition(wxPoint(600,0));
    auto machine2 = std::make_shared<MachineToCanadianAdapter>(L"Machine 2", resourcesDir, 2);
    adapter2->AddDrawable(machine2);
    adapter2->SetRoot(machine2);
    machine2->SetMachineFrames(0, 300);
    picture->AddActor(adapter2);
    picture->SetMachine2(machine2);
    //timeline's frame rate * total frames = end frame


    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 600));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(550, 620));
    picture->AddActor(sparty);

    return picture;
}

