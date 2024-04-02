/**
 * @file Hamster.h
 * @author shash
 *
 *Declaration of the Hamster class, representing a hamster object in the CanadianExperience machine.
 */



#ifndef CANADIANEXPERIENCE_MACHINELIB_HAMSTER_H
#define CANADIANEXPERIENCE_MACHINELIB_HAMSTER_H
#include "Component.h"
#include "PhysicsPolygon.h"
#include "RotationSource.h"
#include <b2_world_callbacks.h>

#include <utility>
#include <array>

/**
 * @class Hamster
 * Represents a hamster within the CanadianExperience machine.
 * The Hamster class manages the behavior and attributes of a hamster object,
 * including its movement, rotation, and physical properties.
 */
class Hamster : public Component,public b2ContactListener
{
private:
    /// bool to check if running
    bool mInitiallyRunning = false;
    ///  wheel
    cse335::Polygon mWheel;
    /// cage
    cse335::PhysicsPolygon mCage;
    /// hamster
    cse335::Polygon mHamster;
    /// rotation
    double mRotation = 0.0;
    /// speed
    double mSpeed = 1.0;
    /// images Directory
    std::wstring mImagesDir;
    /// X position
    double mXPos=0;
    /// Y position
    double mYPos=0;
    /// Array of Hamsters
    std::array<std::unique_ptr<cse335::Polygon>, 4> mHamsters;
    /// Hamster Image number
    int mHamsterImgNum = 0;
    /// Rotation Source
    RotationSource mRotationSource;
    /// If already running
    bool mAlreadyRunning = false;






public:
    /**
    * @brief Draws the hamster.
    * @param imagesDir
    */
    Hamster(std::wstring imagesDir);
    /// Default constructor (disabled)
    Hamster() = delete;

    /// Copy constructor (disabled)
    Hamster(const Hamster &) = delete;

    /// Assignment operator
    void operator=(const Hamster &) = delete;

    /**
 * @brief Draws the hamster.
 * @param graphics Shared pointer to the graphics context.
 */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

/**
 * @brief Updates the hamster based on elapsed time.
 * @param elapsed Elapsed time since the last update.
 */
    void Update(double elapsed) override;

/**
 * @brief Sets the position of the hamster.
 * @param x X-coordinate position.
 * @param y Y-coordinate position.
 */
    void SetPosition(double x, double y);

/**
 * @brief Sets whether the hamster is initially running.
 * @param InitiallyRunning Boolean indicating if the hamster is initially running.
 */
    void SetInitiallyRunning(bool InitiallyRunning);

/**
 * @brief Triggered upon contact with another object in the Box2D world.
 * @param contact Pointer to the Box2D contact object.
 */
    void BeginContact(b2Contact *contact) override;

/**
 * @brief Sets the speed of the hamster.
 * @param speed Speed value to set.
 */
    void SetSpeed(double speed);

/**
 * @brief Gets the rotation source of the hamster.
 * @return Pointer to the RotationSource object.
 */
    RotationSource *GetSource() { return &mRotationSource; }

/**
 * @brief Rotates the hamster by a given angle and velocity.
 * @param rotation Angle of rotation.
 * @param velocity Velocity of rotation.
 */
    void Rotate(double rotation, double velocity) override;

/**
 * @brief Resets the hamster to its initial state.
 */
    void Reset() override;

/**
 * @brief Get a pointer to the polygon used by this body.
 * @return Pointer to the PhysicsPolygon object.
 */
    cse335::PhysicsPolygon *GetPolygon() { return &mCage; }

/**
 * @brief Retrieves the shaft position of the hamster.
 * @return The shaft position as a wxPoint2DDouble object.
 */
    wxPoint2DDouble GetShaftPosition();

/**
 * @brief Installs physics for the hamster in the Box2D world.
 * @param world Shared pointer to the Box2D world.
 * @param contactListener Shared pointer to the contact listener object.
 */
    void InstallPhysics(std::shared_ptr<b2World> world, std::shared_ptr<ContactListener> contactListener) override;

};

#endif //CANADIANEXPERIENCE_MACHINELIB_HAMSTER_H
