/**
 * @file MachineSystem.h
 * @author shash
 * Machine System class
 *
 */


#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEM_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEM_H

#include "IMachineSystem.h"
class Machine;

/**
 * @class MachineSystem
 * @brief Represents a machine system
 */
class MachineSystem : public IMachineSystem
{
private:
    /// Machine Number
    int mMachineNum = 1;
    /// pointer to Machine
    std::shared_ptr<Machine>  mMachine;
    /// flag
    int mFlag = 0;
    /// frame rate
    double mFrameRate = 30.0;
    /// Location
    wxPoint mLocation = wxPoint(0,0);
    /// Time
    double mTime = 0.0;
    /// FrameNum
    int mFrameNum = 0;
    /// Frame
    int mFrame = 0;
    /// How many pixels there are for each CM
    double mPixelsPerCentimeter = 1.5;

    /// The resources directory
    std::wstring mResourcesDir;

public:
    /// Constructor
    MachineSystem(std::wstring resourcesDir);
    /// Default constructor (disabled)
    MachineSystem() = delete;

    /// Copy constructor (disabled)
    MachineSystem(const MachineSystem &) = delete;

    /// Assignment operator
    void operator=(const MachineSystem &) = delete;





    /**
    * Set the position for the root of the machine
    * @param location The x,y location to place the machine
    */
    void SetLocation(wxPoint location) override;

    /**
     * Get the location of hte machine
     * @return Location x,y in pixels as a point
     */
    wxPoint GetLocation() override { return wxPoint(0,0);};

    /**
    * Draw the machine at the currently specified location
    * @param graphics Graphics object to render to
    */
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
    * Set the current machine animation frame
    * @param frame Frame number
    */
    void SetMachineFrame(int frame) override;

    /**
     * Set the expected frame rate in frames per second
     * @param rate Frame rate in frames per second
     */
    void SetFrameRate(double rate) override;;

    /**
    * Set the machine number
    * @param machine An integer number. Each number makes a different machine
    */
    void SetMachineNumber(int machine) override;

    /**
     * Get the current machine number
     * @return Machine number integer
     */
     int GetMachineNumber() override {return mMachineNum;}

    /**
     * Get the current machine time.
     * @return Machine time in seconds
     */
    double GetMachineTime() override;

    /**
     * Set the flag from the control panel
     * @param flag Flag to set
     */
    void SetFlag(int flag) override{};



};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEM_H
