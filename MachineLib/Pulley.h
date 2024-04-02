/**
 * @file Pulley.h
 * @author shash
 *
 * Pulley class
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
#define CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
#include "Component.h"
#include "Polygon.h"
#include "RotationSink.h"
#include "RotationSource.h"
/**
 * @class Pulley
 * Represents a pulley within the CanadianExperience machine.
 * The Pulley class manages the behavior and attributes of a pulley object,
 * including its radius, position, velocity, associated pulley, and rendering.
 */
class Pulley : public Component,  public std::enable_shared_from_this<Pulley>
{
private:
    /// Radius of the pulley.
    double mRadius = 0.0;

    /// Represents the pulley as a Polygon object.
    cse335::Polygon mPulley;

    /// X-coordinate position of the pulley.
    double mXPos = 0.0;

    /// Y-coordinate position of the pulley.
    double mYPos = 0.0;

    /// Velocity of the pulley.
    double mVelocity = 1.0;

    /// Multiplier value associated with the pulley.
    double mMultiplier = 1.0;

    /// Associated Pulley object.
    std::shared_ptr<Pulley> mAssociatedPulley;

    /// RotationSink object associated with the pulley.
    RotationSink mSink;

    /// RotationSource object associated with the pulley.
    RotationSource mRotSource;

    /// Current rotation angle of the pulley.
    double mRotation = 0.0;



public:
    /**
     * Resets the pulley
     *
     */
    void Reset() override;

    /// Default constructor (disabled)
    Pulley() = delete;

    /// Copy constructor (disabled)
    Pulley(const Pulley &) = delete;

    /// Assignment operator
    void operator=(const Pulley &) = delete;

    /**
   * @brief Constructs a Pulley object with a specified radius.
   * @param radius Radius of the pulley.
   */
    Pulley(double radius);

    /**
     * @brief Draws the pulley.
     * @param graphics Shared pointer to the graphics context.
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * @brief Updates the pulley based on elapsed time.
     * @param elapsed Elapsed time since the last update.
     */
    void Update(double elapsed) override;

    /**
     * @brief Rotates the pulley by a given angle and velocity.
     * @param rotation Angle of rotation.
     * @param velocity Velocity of rotation.
     */
    void Rotate(double rotation, double velocity) override;

    /**
     * @brief Retrieves the RotationSource object associated with the pulley.
     * @return Pointer to the RotationSource object.
     */
    RotationSource *GetSource() { return &mRotSource; }

    /**
     * @brief Retrieves the RotationSink object associated with the pulley.
     * @return Pointer to the RotationSink object.
     */
    RotationSink *GetSink() { return &mSink; }

    /**
     * @brief Sets the image of the pulley.
     * @param img Path to the image.
     */
    void SetImage(std::wstring img);

    /**
     * @brief Drives the pulley using another pulley.
     * @param pulley Shared pointer to another Pulley object.
     */
    void Drive(std::shared_ptr<Pulley> pulley);

    /**
     * @brief Sets the position of the pulley.
     * @param x X-coordinate position.
     * @param y Y-coordinate position.
     */
    void SetPosition(double x, double y);

    /**
     * @brief Installs physics for the pulley in the Box2D world.
     * @param world Shared pointer to the Box2D world.
     * @param contactListener Shared pointer to the contact listener object.
     */
    void InstallPhysics(std::shared_ptr<b2World> world, std::shared_ptr<ContactListener> contactListener) override;

    /**
     * @brief Retrieves the X-coordinate position of the pulley.
     * @return The X-coordinate position.
     */
    double GetXPosition() { return mXPos; }

    /**
     * @brief Retrieves the Y-coordinate position of the pulley.
     * @return The Y-coordinate position.
     */
    double GetYPosition() { return mYPos; }


};

#endif //CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
