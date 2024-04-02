/**
 * @file Conveyor.h
 * @author shash
 *
 * Declaration of the Conveyor class, representing a conveyor object in the CanadianExperience machine.
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_CONVEYOR_H
#define CANADIANEXPERIENCE_MACHINELIB_CONVEYOR_H

#include "Component.h"
#include "PhysicsPolygon.h"
#include "RotationSink.h"
#include <b2_world_callbacks.h>

/**
 * @class Conveyor
 * Represents a conveyor within the CanadianExperience machine.
 * The Conveyor class manages the behavior and attributes of a conveyor object,
 * including its position, velocity, contact handling, and rendering.
 */
class Conveyor : public Component, public b2ContactListener
{
private:
    /// Represents the conveyor as a PhysicsPolygon object.
    cse335::PhysicsPolygon mConveyor;

    /// X-coordinate position of the conveyor.
    double mXPos = 0.0;

    ///  Y-coordinate position of the conveyor.
    double mYPos = 0.0;

    /// Shared pointer to a ContactListener object for managing contacts.
    std::shared_ptr<ContactListener> mContact;

    /// Velocity of the conveyor.
    double mVelocity = 0.0;

    /// RotationSink object associated with the conveyor.
    RotationSink mSink;





public:
    /**
     * @brief Constructs a Conveyor object.
     * @param imagesDir Directory containing images for the conveyor.
     */
    Conveyor(std::wstring imagesDir);
    /// Default constructor (disabled)
    Conveyor() = delete;

    /// Copy constructor (disabled)
    Conveyor(const Conveyor &) = delete;

    /// Assignment operator
    void operator=(const Conveyor &) = delete;




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
     * @brief Rotates the conveyor by a given angle and velocity.
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
     * @brief Installs physics for the conveyor in the Box2D world.
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
     * @brief Retrieves the shaft position of the conveyor.
     * @return The shaft position as a wxPoint2DDouble object.
     */
    wxPoint2DDouble GetShaftPosition();

    /**
     * @brief Retrieves the RotationSink object associated with the conveyor.
     * @return Pointer to the RotationSink object.
     */
    RotationSink *GetSink() { return &mSink; }

    /**
     * @brief Retrieves the current position of the conveyor.
     * @return The current position as a wxPoint2DDouble object.
     */
    wxPoint2DDouble GetPosition();
};

#endif //CANADIANEXPERIENCE_MACHINELIB_CONVEYOR_H
