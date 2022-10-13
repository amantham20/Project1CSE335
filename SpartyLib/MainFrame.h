/**
 * @file MainFrame.h
 * @author Ian Valdovinos Granados
 *
 *
 */

#ifndef ANGRYSPARTY_MAINFRAME_H
#define ANGRYSPARTY_MAINFRAME_H

class MainFrame : public wxFrame {
private:
    void OnExit(wxCommandEvent& event);
    void OnMenuHelpAbout(wxCommandEvent &event);

public:
    void Initialize();

};

#endif //ANGRYSPARTY_MAINFRAME_H
