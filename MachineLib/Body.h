/**
 * @file Body.h
 * @author shash
 *
 * Body class
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_BODY_H
#define CANADIANEXPERIENCE_MACHINELIB_BODY_H

#include "Component.h"
#include "PhysicsPolygon.h"
//#include "IRotationSink.h"
#include "RotationSink.h"

/**
 * @class Body
 * @brief Represents a base body within the CanadianExperience machine.
 *
 */
class Body : public Component
{
private:
    /// Polygon object
    cse335::PhysicsPolygon mPolygon;
    /// Rotation Sink
    RotationSink mSink;



public:
    /// destructor
    ~Body(){}

    /// Copy constructor (disabled)
    Body(const Body &) = delete;

    /// Assignment operator
    void operator=(const Body &) = delete;


    /**
  * @brief Default constructor for the Body class.
  */
    Body();

    /**
     * @brief Draws the body.
     * @param graphics Shared pointer to the graphics context.
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * @brief Updates the body based on elapsed time.
     * @param elapsed Elapsed time since the last update.
     */
    void Update(double elapsed) override;

    /**
     * @brief Retrieves the RotationSink object associated with the body.
     * @return Pointer to the RotationSink object.
     */
    RotationSink *GetSink() { return &mSink; }

    /**
     * @brief Gets a pointer to the polygon used by this body.
     * @return Pointer to the PhysicsPolygon object.
     */
    cse335::PhysicsPolygon* GetPolygon() { return &mPolygon; }

    /**
     * @brief Rotates the body by a given angle and velocity.
     * @param rotation Angle of rotation.
     * @param velocity Velocity of rotation.
     */
    void Rotate(double rotation, double velocity) override;

    /**
     * @brief Installs physics for the body in the Box2D world.
     * @param world Shared pointer to the Box2D world.
     * @param contactListener Shared pointer to the contact listener object.
     */
    void InstallPhysics(std::shared_ptr<b2World> world, std::shared_ptr<ContactListener> contactListener) override;

    /**
     * @brief Sets the initial position of the body.
     * @param position Initial position as a wxPoint2DDouble object.
     */
    void SetInitialPosition(wxPoint2DDouble position);

    /**
     * @brief Resets the body to its initial state.
     */
    void Reset() override;

};

#endif //CANADIANEXPERIENCE_MACHINELIB_BODY_H
