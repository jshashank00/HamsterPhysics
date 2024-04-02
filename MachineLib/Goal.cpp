/**
 * @file Goal.cpp
 * @author Shashank Jayaram
 */
#include "pch.h"
#include "Goal.h"

#include <utility>

/// Image to draw for the goal
const std::wstring GoalImage = L"/goal.png";

/// Size to draw the entire goal post image
/// This does not go into the physics system at all
const auto GoalSize = wxSize(65, 247);

/// Size to create a rectangle in the physics system only
/// (does not draw) to reflect off of the backboard and post
const auto PostSize = wxSize(10, 250);

/// Size of a target object inside the goal net that
/// we'll consider a score when touched by a ball
const auto TargetSize = wxSize(20, 5);

/// The color of the scoreboard background
const auto ScoreboardBackgroundColor = wxColor(24, 69, 59);

/// Width of the black line around the scoreboard
const int ScoreboarderLineWidth = 3;

/// Scoreboard font size (height) in cm
/// The font color is white
const int ScoreboardFontSize = 20;

/// Rectangle that represents the location relative to the
/// goal position for the scoreboard and its size.
const auto ScoreboardRectangle = wxRect2DDouble(5, 280, 30, 20);

/// Location of the scoreboard text relative to the
/// scoreboard location in cm.
const auto ScoreboardTextLocation = wxPoint2DDouble(9, 299);

/// Position of the goalpost polygon relative to the entire goal
/// This plus the location set by SetPosition is where to draw
/// the goalpost PhysicsPolygon object.
const wxPoint2DDouble PostPosition = wxPoint2DDouble(22, 0);

/// Position of the basket goal polygon relative to the entire goal
/// This plus the location set by SetPosition is where to draw
/// the goalpost PhysicsPolygon object.
const wxPoint2DDouble GoalPosition = wxPoint2DDouble(-12, 165);

Goal::Goal(std::wstring imagePath): mImagePath(std::move(imagePath))
{
    mGoalImage.BottomCenteredRectangle(GoalSize);
    mGoalImage.SetImage(mImagePath + GoalImage);
    mPost.BottomCenteredRectangle(PostSize);
    mPost.SetColor(*wxBLUE);

    mGoal.BottomCenteredRectangle(TargetSize);
    mGoal.SetColor(*wxBLUE);


}


void Goal::BeginContact(b2Contact *contact)
{
    mScore += 2;

//    b2ContactListener::BeginContact(contact);
}
void Goal::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    //mGoal.Draw(graphics);
    //mPost.Draw(graphics);
    mGoalImage.DrawPolygon(graphics, mXPos, mYPos, 0);

    //mGoalImage.DrawPolygon(graphics);

    // Scoreboard top-left corner, relative to the goal
    wxPoint2DDouble scoreboardTopLeft(mXPos + ScoreboardRectangle.m_x, mYPos + ScoreboardRectangle.m_y);
    wxSize scoreboardSize(ScoreboardRectangle.m_width, ScoreboardRectangle.m_height);

    // Draw scoreboard background
    graphics->SetBrush(wxBrush(ScoreboardBackgroundColor));
    graphics->DrawRectangle(scoreboardTopLeft.m_x, scoreboardTopLeft.m_y, scoreboardSize.GetWidth(), scoreboardSize.GetHeight());

    // Draw scoreboard border
    graphics->SetPen(wxPen(*wxBLACK, ScoreboarderLineWidth));
    graphics->DrawRectangle(scoreboardTopLeft.m_x, scoreboardTopLeft.m_y, scoreboardSize.GetWidth(), scoreboardSize.GetHeight());

    // Font to draw the score
    wxFont font(wxSize(0, ScoreboardFontSize),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, *wxWHITE);

    std::wstring scoreText = std::to_wstring(mScore);

    // Measure text size
    wxDouble textWidth, textHeight;
    graphics->GetTextExtent(scoreText, &textWidth, &textHeight);

    // Calculate text position to center it in the scoreboard
    wxDouble textX = scoreboardTopLeft.m_x + (scoreboardSize.GetWidth() - textWidth) / 2;
    wxDouble textY = scoreboardTopLeft.m_y + (scoreboardSize.GetHeight() - textHeight) / 2;

    // Adjust for upside-down text due to negative scaling
    graphics->PushState();
    graphics->Translate(textX, textY + textHeight); // Adjusted for bottom-left reference point
    graphics->Scale(1, -1); // Reverse the Y-axis scaling for text

    // Draw the score text
    graphics->DrawText(scoreText, 0, 0); // Drawing at the new origin
    graphics->PopState();

}
void Goal::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
    contact->SetEnabled(false);

}
void Goal::Update(double elapsed)
{
    //::Update(elapsed);



}
void Goal::SetPosition(double x, double y)
{
    mPost.SetInitialPosition(x+PostPosition.m_x, y+PostPosition.m_y);
    mGoal.SetInitialPosition(x+GoalPosition.m_x, y+GoalPosition.m_y);
    mXPos=x;
    mYPos=y;

}
void Goal::InstallPhysics(std::shared_ptr<b2World> world, std::shared_ptr<ContactListener> contactListener)
{

    mPost.InstallPhysics(world);
    mGoal.InstallPhysics(world);
    contactListener->Add(mGoal.GetBody(), this);
}
void Goal::Rotate(double rotation, double velocity)
{

}
void Goal::Reset()
{
    mScore = 0;

}

