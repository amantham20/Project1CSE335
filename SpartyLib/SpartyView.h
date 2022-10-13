/**
 * @file SpartyView.h
 * @author Ian Valdovinos Granados
 *
 *
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
