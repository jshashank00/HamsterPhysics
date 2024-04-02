/**
 * @file RotationSource.h
 * @author shash
 *
 * Declaration of the RotationSource class, representing a source of rotation in the CanadianExperience machine.
 */


#ifndef CANADIANEXPERIENCE_MACHINELIB_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_MACHINELIB_ROTATIONSOURCE_H

class RotationSink;
/**
 * @class RotationSource
 * @brief Represents a source of rotation within the CanadianExperience machine.
 * @details The RotationSource class manages rotation and provides functionality
 * to interact with RotationSink objects.
 */
class RotationSource
{
private:
    /// Vector of Rotation Sinks
    std::vector<RotationSink*> mSinksVector;
public:
    /**
     * @brief Default constructor for RotationSource.
     */
    RotationSource();

    /**
     * Adds a RotationSink to the RotationSource.
     * @param rotSink Pointer to the RotationSink to be added.
     */
    void AddSink(RotationSink* rotSink);

    /**
     *  Rotates the source by a given angle and velocity.
     * @param rotation Angle of rotation.
     * @param velocity Velocity of rotation.
     */
    void Rotate(double rotation, double velocity);

    /// Copy constructor (disabled)
    RotationSource(const RotationSource &) = delete;

    /// Assignment operator
    void operator=(const RotationSource &) = delete;



};

#endif //CANADIANEXPERIENCE_MACHINELIB_ROTATIONSOURCE_H
