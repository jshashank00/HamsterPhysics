/**
 * @file RotationSink.h
 * @author shash
 *
 * @brief Declaration of the RotationSink class,
 * representing a sink for rotation in the CanadianExperience machine.
 */


#ifndef CANADIANEXPERIENCE_MACHINELIB_ROTATIONSINK_H
#define CANADIANEXPERIENCE_MACHINELIB_ROTATIONSINK_H

#include "Component.h"
class RotationSource;
/**
 * @class RotationSink
 * @brief Represents a sink for rotation within the CanadianExperience machine.
 * @details The RotationSink class manages rotation and interacts with Component and RotationSource objects.
 */
class RotationSink
{
private:
    /// Pointer to a component object
    Component * mComponent = nullptr;
    /// Rotation value
    double mRotation = 0.0;
    /// Pointer to a rotation source
    RotationSource* mRotSource;
public:

    /**
      * @brief Rotates the sink by a given angle and velocity.
      * @param rotation Angle of rotation.
      * @param velocity Velocity of rotation.
      */
    void Rotate(double rotation, double velocity);

    /**
     * @brief Default constructor for RotationSink.
     */
    RotationSink();

    /// Copy constructor (disabled)
    RotationSink(const RotationSink &) = delete;

    /// Assignment operator
    void operator=(const RotationSink &) = delete;

    /**
     * @brief Sets the RotationSource for the RotationSink.
     * @param rotSource Pointer to the RotationSource object.
     */
    void SetSource(RotationSource* rotSource);

    /**
     * @brief Sets the Component for the RotationSink.
     * @param component Pointer to the Component object.
     */
    void SetComponent(Component* component);
};

#endif //CANADIANEXPERIENCE_MACHINELIB_ROTATIONSINK_H
