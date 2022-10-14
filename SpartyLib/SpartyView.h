/**
 * @file SpartyView.h
 * @author Ian Valdovinos Granados, zhiqiang ni, Milan Mihailovic
 *
 * Window class in which the game is drawn.
 */

#ifndef ANGRYSPARTY_SPARTYVIEW_H
#define ANGRYSPARTY_SPARTYVIEW_H

class SpartyView : public wxWindow {
private:
    void OnPaint(wxPaintEvent& event);

public:
    void Initialize(wxFrame* parent);

};

#endif //ANGRYSPARTY_SPARTYVIEW_H
