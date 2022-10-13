/**
 * @file SpartyView.cpp
 * @author Ian Valdovinos Granados, Zhiqiang ni
 */
#include "pch.h"
#include "SpartyView.h"
#include <wx/dcbuffer.h>

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void SpartyView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();
}

void SpartyView::Initialize(wxFrame* parent)
{

}


