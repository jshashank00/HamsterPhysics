/**
 * @file Basket.h
 * @author shash
 *
 * Basket class
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_BASKET_H
#define CANADIANEXPERIENCE_MACHINELIB_BASKET_H

#include "Component.h"
#include "Polygon.h"
#include "PhysicsPolygon.h"

/**
 * @class Basket
 * @brief Represents a base basket within the CanadianExperience machine.
 *
 */
class Basket : public Component, public b2ContactListener
{
private:

    /// Basket
    cse335::Polygon mBasket;

    /// Bottom
    cse335::PhysicsPolygon mBottom;

    /// Right side
    cse335::PhysicsPolygon mRight;

    /// Left side
    cse335::PhysicsPolygon mLeft;

    /// X Pos
    double mXPos = 0;
    /// Y Pos
    double mYPos = 0;

    /// Seconds
    double mSeconds = 0;

    ///If ball is inside
    bool mInside = false;

    ///Movement direction
    wxPoint2DDouble mMovement = wxPoint2DDouble(0, 0);

    /// resources dir
    std::wstring mResourcesDir;

public:

        /**
     * @brief Constructs a Basket object.
     * @param resourcesDir The directory for resources related to the Basket.
     *
     * This constructor initializes a Basket object using the specified directory
     * for associated resources, such as images or files.
     */
    Basket(std::wstring resourcesDir);


    /// Default constructor (disabled)
    Basket() = delete;

    /// Copy constructor (disabled)
    Basket(const Basket &) = delete;

    /// Assignment operator
    void operator=(const Basket &) = delete;



    /**
     * @brief Draws the conveyor.
     * @param graphics Shared pointer to the graphics context.
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * @brief Updates the conveyor based on elapsed time.
     * @param elapsed Elapsed time since the last update.
     */
    void Update(double elapsed) override;

    /**
     * @brief Rotates the basket by a given angle and velocity.
     * @param rotation Angle of rotation.
     * @param velocity Velocity of rotation.
     */
    void Rotate(double rotation, double velocity) override;

    /**
     * @brief Resets the conveyor to its initial state.
     */
    void Reset() override;

    /**
     * @brief Sets the position of the conveyor.
     * @param x X-coordinate position.
     * @param y Y-coordinate position.
     */
    void SetPosition(double x, double y);

    /**
     * @brief Installs physics for the basket in the Box2D world.
     * @param world Shared pointer to the Box2D world.
     * @param contactListener Shared pointer to the contact listener object.
     */
    void InstallPhysics(std::shared_ptr<b2World> world, std::shared_ptr<ContactListener> contactListener) override;

    /**
     * @brief Triggered before a Box2D collision resolution.
     * @param contact Pointer to the Box2D contact object.
     * @param oldManifold Pointer to the old manifold.
     */
    void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;

    /**
       * @brief Basket animation
       * @param animation wxPoint2DDouble
       */
    void BasketAnimation(wxPoint2DDouble animation);

    /**
       * @brief Basket handler
       * @param contact b2Contact
       */
    void InBasket(b2Contact *contact);
};

#endif //CANADIANEXPERIENCE_MACHINELIB_BASKET_H
