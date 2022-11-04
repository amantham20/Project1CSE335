/**
 * @file MainFrame.h
 * @author Ian Valdovinos Granados, zhiqiang ni
 *
 * Main frame for the Angry Sparty game
 *
 */

#ifndef ANGRYSPARTY_MAINFRAME_H
#define ANGRYSPARTY_MAINFRAME_H

/**
 * Forward declaration for SpartyView
 */
class SpartyView;

/**
 * Main frame class for the Angry Sparty game
 */
class MainFrame : public wxFrame
{
private:
    SpartyView *mSpartyView;
    void OnExit(wxCommandEvent& event);
    void OnMenuHelpAbout(wxCommandEvent &event);
    void OnClose(wxCloseEvent& event);

public:
    void Initialize();

};

#endif //ANGRYSPARTY_MAINFRAME_H
