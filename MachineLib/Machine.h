/**
 * @file Machine.h
 * @author shash
 *
 * Machine class
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE_H

#include "Component.h"
#include "ContactListener.h"
/**
 * @class Machine
 * @brief Represents a machine containing various components.
 * @details The Machine class manages components in a machine and provides methods
 * to control and interact with those components.
 */
class Machine
{
private:
    /// Vector of components
    std::vector<std::shared_ptr<Component>> mComponents;
    /// The box2d world
    std::shared_ptr<b2World> mWorld;
    /// The installed contact filter
    std::shared_ptr<ContactListener> mContactListener;
    /// Goal to reset Score
    int mMachineNum = 0;



public:

    /// Copy constructor (disabled)
    Machine(const Machine &) = delete;
    
    /// Assignment operator
    void operator=(const Machine &) = delete;


    /**
 * @brief Constructs a Machine object with a specified machine number.
 * @param machineNum The machine number.
 */
    Machine(int machineNum);

/**
 * @brief Adds a component to the Machine.
 * @param component Shared pointer to the Component object to be added.
 */
    void AddComponent(std::shared_ptr<Component> component);

/**
 * @brief Draws all components of the Machine.
 * @param graphics Shared pointer to the graphics context.
 */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);


    void Update(double elapsed);

/**
 * @brief Resets all components of the Machine to their initial states.
 */
    void Reset();

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
