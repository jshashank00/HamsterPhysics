/**
 * @file MachineToCanadianAdapter.h
 * @author shash
 * Adapter class
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINETOCANADIANADAPTER_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINETOCANADIANADAPTER_H
#include "Drawable.h"
#include <machine-api.h>
#include "Timeline.h"

/**
 * MachineToCanadianAdapter class.
 * Inherits from Drawable.
 * Adapter class for Canadian machines.
 */
class MachineToCanadianAdapter : public Drawable
{
private:
    /// Pointer to machine system
    std::shared_ptr<IMachineSystem> mMachineSystem;
    /// Timeline pointer
    Timeline * mTimeline = nullptr;
    /// Start frame
    int mStartFrame = 0;
    /// End frame
    int mEndFrame = 30;
    /// Machine number
    int mMachineNumber = 0;

public:

    /// Default constructor (disabled)
    MachineToCanadianAdapter() = delete;

    /// Copy constructor (disabled)
    MachineToCanadianAdapter(const MachineToCanadianAdapter &) = delete;

    /// Assignment operator
    void operator=(const MachineToCanadianAdapter &) = delete;


/**
 * Constructor for MachineToCanadianAdapter class.
 * @param name The name of the adapter.
 * @param resourcesDir The directory for resources.
 * @param num The machine number.
 */
    MachineToCanadianAdapter(const std::wstring &name, const std::wstring &resourcesDir, int num);

/**
 * Draws using the given graphics context.
 * @param graphics A shared pointer to the wxGraphicsContext.
 */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

/**
 * Checks if the given position is within the object.
 * @param pos The position to test.
 * @return True if the position is within the object, false otherwise.
 */
    bool HitTest(wxPoint pos) override;

/**
 * Sets the timeline for the object.
 * @param timeline Pointer to the Timeline object.
 */
    void SetTimeline(Timeline *timeline) override;

/**
 * Sets a keyframe for the object.
 */
    void SetKeyframe() override;

/**
 * Retrieves the keyframe of the object.
 */
    void GetKeyframe() override;

/**
 * Sets the actor for the object.
 * @param actor Pointer to the Actor object.
 */
    void SetActor(Actor *actor) override;

/**
 * Sets the machine number for the adapter.
 * @param num The machine number to set.
 */
    void SetMachineNumber(int num);

/**
 * Selects a machine for operation.
 * @param parent A pointer to the parent window.
 * @param num The machine number to select.
 */
    void SelectMachine(wxWindow *parent, int num);

/**
 * Sets the start and end frames for the machine.
 * @param startFrame The start frame number.
 * @param endFrame The end frame number.
 */
    void SetMachineFrames(int startFrame, int endFrame);

/**
 * Retrieves the start time of the machine.
 * @return The start time.
 */
    int GetStartTime();

/**
 * Retrieves the end time of the machine.
 * @return The end time.
 */
    int GetEndTime();

/**
 * Sets the start time of the machine.
 * @param time The start time to set.
 */
    void SetStartTime(int time);

/**
 * Sets the end time of the machine.
 * @param time The end time to set.
 */
    void SetEndTime(int time);

/**
 * Opens a dialog window for machine settings.
 * @param parent A pointer to the parent window.
 * @param num The machine number.
 */
    void MachineSetDialog(wxWindow *parent, int num);

/**
 * Retrieves the machine number.
 * @return The machine number.
 */
    int GetMachineNumber();

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINETOCANADIANADAPTER_H
