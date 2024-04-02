/**
 * @file Goal.h
 * @author shash
 *
 * Declaration of the Goal class, representing a goal object in the CanadianExperience machine.
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_GOAL_H
#define CANADIANEXPERIENCE_MACHINELIB_GOAL_H

#include <b2_world_callbacks.h>
#include "Component.h"
#include "PhysicsPolygon.h"

/**
 * @class Goal
 * Represents a goal within the CanadianExperience machine.
 * The Goal class manages the attributes and behavior of a goal object
 */
class Goal : public Component, public b2ContactListener
{
private:
    /// Image Path
    std::wstring mImagePath;
    /// Post
    cse335::PhysicsPolygon mPost;
    ///Goal
    cse335::PhysicsPolygon mGoal;
    /// Goal Image
    cse335::Polygon   mGoalImage;
    /// X position
    double mXPos=0;
    /// Y position
    double mYPos=0;
    /// Score
    int mScore = 00;
public:
    /**
     * Constructs a Goal object.
     * @param imagePath Path to the image associated with the goal.
     */
    explicit Goal(std::wstring  imagePath);

//    /// Default constructor (disabled)
//    Goal() = delete;
    /// Copy constructor (disabled)
    Goal(const Goal &) = delete;

    /// Assignment operator
    void operator=(const Goal &) = delete;

    /**
     *  Draws the goal.
     * @param graphics Shared pointer to the graphics context.
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Triggered when a Box2D contact begins.
     * @param contact Pointer to the Box2D contact object.
     */
    void BeginContact(b2Contact *contact) override;

    /**
     * Triggered before a Box2D collision resolution.
     * @param contact Pointer to the Box2D contact object.
     * @param oldManifold Pointer to the old manifold.
     */
    void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;

    /**
     *  Updates the goal based on elapsed time.
     * @param elapsed Elapsed time since the last update.
     */
    void Update(double elapsed) override;

    /**
     *  Sets the position of the goal.
     * @param x X-coordinate position.
     * @param y Y-coordinate position.
     */
    void SetPosition(double x, double y);

    /**
     *  Installs physics for the goal in the Box2D world.
     * @param world Shared pointer to the Box2D world.
     * @param contactListener Shared pointer to the contact listener object.
     */
    void InstallPhysics(std::shared_ptr<b2World> world, std::shared_ptr<ContactListener> contactListener) override;

    /**
     *  Rotates the goal by a given angle and velocity.
     * @param rotation Angle of rotation.
     * @param velocity Velocity of rotation.
     */
    void Rotate(double rotation, double velocity) override;

    /**
     *  Resets the goal to its initial state.
     */
    void Reset() override;




};

#endif //CANADIANEXPERIENCE_MACHINELIB_GOAL_H
