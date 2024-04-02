/**
 * @file Component.h
 * @author shash
 *  Declaration of the Component class,
 * representing a base component in the CanadianExperience machine.
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
#define CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
#include "box2d.h"
#include "ContactListener.h"

/**
 * @class Component
 * @brief Represents a base component within the CanadianExperience machine.
 * @details The Component class serves as a base class for various components,
 * providing an interface for common functionalities.
 */
class Component
{
private:
    /// Name
    std::string mName;

public:

    /**
     * @brief Pure virtual function to draw the object.
     * @param graphics Shared pointer to the graphics context.
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;

    /**
     * @brief Pure virtual function to update the object based on elapsed time.
     * @param elapsed Elapsed time since the last update.
     */
    virtual void Update(double elapsed) = 0;

    /**
     * @brief Pure virtual function to rotate the object by a given angle and velocity.
     * @param rotation Angle of rotation.
     * @param velocity Velocity of rotation.
     */
    virtual void Rotate(double rotation, double velocity) = 0;

    /**
     * @brief Pure virtual function to reset the object to its initial state.
     */
    virtual void Reset() = 0;

    /**
     * @brief Pure virtual function to install physics for the object in the Box2D world.
     * @param world Shared pointer to the Box2D world.
     * @param contactListener Shared pointer to the contact listener object.
     */
    virtual void InstallPhysics(std::shared_ptr<b2World> world, std::shared_ptr<ContactListener> contactListener) = 0;

};

#endif //CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
