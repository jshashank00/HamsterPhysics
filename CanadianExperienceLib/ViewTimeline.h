/**
 * @file ViewTimeline.h
 * @author Charles B. Owen
 *
 * View class for the timeline area of the screen.
 */

#ifndef CANADIANEXPERIENCE_VIEWTIMELINE_H
#define CANADIANEXPERIENCE_VIEWTIMELINE_H

#include "PictureObserver.h"

/**
 * View class for the timeline area of the screen.
 */
class ViewTimeline final : public wxScrolledCanvas, public PictureObserver {
private:
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnPaint(wxPaintEvent& event);
    void OnTimer(wxTimerEvent& event);

    void OnEditTimelineProperties(wxCommandEvent& event);
    void OnEditSetKeyframe(wxCommandEvent& event);
    void OnEditDeleteKeyframe(wxCommandEvent& event);
    void OnPlayPlay(wxCommandEvent& event);
    void OnPlayStop(wxCommandEvent& event);
    void OnPlayPlayFromBeginning(wxCommandEvent& event);
    void OnFileSaveAs(wxCommandEvent& event);
    void OnFileOpen(wxCommandEvent& event);

    /// Bitmap image for the pointer
    std::unique_ptr<wxImage> mPointerImage;

    /// Graphics bitmap to display
    wxGraphicsBitmap mPointerBitmap;

    /// Flag to indicate we are moving the pointer
    bool mMovingPointer = false;

    /// The timer that allows for playing the animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// Are we playing?
    bool mPlaying = false;

public:
    static const int Height = 90;      ///< Height to make this window


    ViewTimeline(wxFrame* parent, std::wstring imagesDir);

    void UpdateObserver() override;



    void Stop();

    /**
 * @brief Handles the event when machine properties are edited.
 *
 * This function is triggered by a wxWidgets command event when editing machine properties.
 *
 * @param event The event that triggers the editing of machine properties.
 */
    void OnEditMachineProperties(wxCommandEvent &event);

/**
 * @brief Handles the event when machine 2 properties are edited.
 *
 * This function is triggered by a wxWidgets command event when editing machine 2 properties.
 *
 * @param event The event that triggers the editing of machine 2 properties.
 */
    void OnEditMachine2Properties(wxCommandEvent& event);

};


#endif //CANADIANEXPERIENCE_VIEWTIMELINE_H
