/**
 * @file MachineDlg.cpp
 * @author shash
 */
#include "pch.h"
#include "MachineDlg.h"
#include "MachineToCanadianAdapter.h"
#include <wx/xrc/xmlres.h>
#include <wx/valnum.h>


MachineDlg::MachineDlg(wxWindow *parent, std::shared_ptr<MachineToCanadianAdapter> machine)
{
    mMachine = machine;
    wxXmlResource::Get()->LoadDialog(this, parent, L"MachineProperties1");

    mStart = machine->GetStartTime();
    mEnd = machine->GetEndTime();

    Bind(wxEVT_BUTTON, &MachineDlg::OnOK, this, wxID_OK);

    auto numFramesCtrl = XRCCTRL(*this, "startTime", wxTextCtrl);
    wxIntegerValidator<int> numFramesValidator(&mStart);
    numFramesValidator.SetRange(0, 1000);
    numFramesCtrl->SetValidator(numFramesValidator);

    auto frameRateCtrl = XRCCTRL(*this, "endTime", wxTextCtrl);
    wxIntegerValidator<int> frameRateValidator(&mEnd);
    frameRateValidator.SetRange(0, 1000);
    frameRateCtrl->SetValidator(frameRateValidator);

}

/**
 * Handle an OK button press
 * @param event Button event
 */
void MachineDlg::OnOK(wxCommandEvent& event)
{
    if ( Validate() && TransferDataFromWindow() )
    {
        // Success! Set values in the class
        mMachine->SetStartTime(mStart);
        mMachine->SetEndTime(mEnd);

        EndModal(wxID_OK);
    }
}

