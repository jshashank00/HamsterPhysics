/**
 * @file MachineDlg.h
 * @author shash
 * @brief Declaration of the MachineDlg class.
 *
 * This file contains the declaration of the MachineDlg class, which represents
 * a dialog for configuring a MachineToCanadianAdapter.
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDLG_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDLG_H

#include "MainFrame.h"

class Timeline;
class MachineToCanadianAdapter;

/**
 * @brief Represents a dialog for configuring a MachineToCanadianAdapter.
 *
 * This dialog provides a way to configure settings for a MachineToCanadianAdapter.
 * It allows setting the start and end values, as well as other properties of the machine.
 */
class MachineDlg : public wxDialog {
private:
    int mStart = 0; /**< @brief The starting value. */
    int mEnd = 0; /**< @brief The ending value. */
    std::shared_ptr<MachineToCanadianAdapter> mMachine; /**< @brief The machine being configured. */
    MainFrame * mMainFrame; /**< @brief Pointer to the main frame. */


    void OnOK(wxCommandEvent& event);

public:
    /**
     * @brief Constructs a MachineDlg object.
     * @param parent Pointer to the parent window.
     * @param machine Shared pointer to the MachineToCanadianAdapter to configure.
     */
    MachineDlg(wxWindow* parent, std::shared_ptr<MachineToCanadianAdapter> machine);
};



#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDLG_H
