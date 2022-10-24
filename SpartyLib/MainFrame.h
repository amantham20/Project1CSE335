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
 * Main frame class for the Angry Sparty game
 */
class MainFrame : public wxFrame {
private:
    void OnExit(wxCommandEvent& event);
    void OnMenuHelpAbout(wxCommandEvent &event);

public:
    void Initialize();

};

#endif //ANGRYSPARTY_MAINFRAME_H
