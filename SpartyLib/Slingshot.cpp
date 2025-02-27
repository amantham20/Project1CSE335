/**
 * @file Slingshot.cpp
 * @author Milan Mihailovic
 */

#include "pch.h"
#include "Slingshot.h"
#include "Level.h"
#include "Consts.h"

using namespace std;

/**
 * Slingshot constructor
 * @param level 
 */
Slingshot::Slingshot(std::shared_ptr<Level> level) : PositionalItem(level)
{
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Slingshot::XmlLoad(wxXmlNode *node)
{
    PositionalItem::XmlLoad(node);
}

/**
 * Draws a slingshot
 * @param graphics Graphics context used to draw this slingshot
 */
void Slingshot::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    const int heightOffset = 50;

    auto tLevel = Item::GetLevel();
    auto wid = tLevel->GetWidth() * Consts::MtoCM;
    auto hit = tLevel->GetHeight()  * Consts::MtoCM;

    auto position = PositionalItem::GetPosition();
    auto image = Item::GetBitMap();

    graphics->PushState();

    graphics->Scale(1, -1);
    graphics->DrawBitmap(*Item::GetBitMap(),
            position.x * Consts::MtoCM,
            (position.y  * Consts::MtoCM) - image->GetHeight() - heightOffset,
            image->GetWidth(), image->GetHeight());


    graphics->PopState();
}

/**
 * Only draws the front portion of the slingshot
 * @param graphics
 */
void Slingshot::DrawFront(std::shared_ptr<wxGraphicsContext> graphics)
{
    const int heightOffset = 50;

    auto tLevel = Item::GetLevel();

    auto position = PositionalItem::GetPosition();
    auto image = mFrontPicture->GetBitmap();

    graphics->PushState();

    graphics->Scale(1, -1);
    graphics->DrawBitmap(*image,
            position.x * Consts::MtoCM,
            (position.y  * Consts::MtoCM) - image->GetHeight() - heightOffset,
            image->GetWidth(), image->GetHeight());


    graphics->PopState();
}

/**
 * Draw the left rubber band using graphics object
 * @param graphics
 */
void Slingshot::DrawLeftRubberBand(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();
    wxPen pen(wxColour(41,13,1), 15);
    graphics->SetPen(pen);
    wxGraphicsPath path = graphics->CreatePath();

    auto spartyPosition = mLoadedSparty->GetPosition();
    path.MoveToPoint(GetXLeftAttachment(), GetYLeftAttachment());
    path.AddLineToPoint(spartyPosition.x*Consts::MtoCM, spartyPosition.y*Consts::MtoCM);

    graphics->StrokePath(path);
    graphics->PopState();
}

/**
 * Draw the right rubber band given graphics context
 * @param graphics
 */
void Slingshot::DrawRightRubberBand(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();
    wxPen pen(wxColour(41,13,1), 15);
    graphics->SetPen(pen);
    wxGraphicsPath path = graphics->CreatePath();

    auto spartyPosition = mLoadedSparty->GetPosition();
//    auto spartyPosition = mLoadedSpartySP->GetPosition();
    path.MoveToPoint(GetXRightAttachment(), GetYRightAttachment());
    path.AddLineToPoint(spartyPosition.x*Consts::MtoCM, spartyPosition.y*Consts::MtoCM);

    graphics->StrokePath(path);
    graphics->PopState();
}

/**
 * Loads an Angry Sparty for launch
 * @param sparty Angry Sparty to load in the slingshot
 */
void Slingshot::LoadAngrySparty(Angry* sparty)
{
    // Set the Angry Sparty position between the slingshot's arms.
    sparty->SetLocation(GetXLoadSpot(), GetYLoadSpot());
    mLoadedSparty = sparty;
}


/**
 * Clears the pointer to a loaded angry sparty
 */
void Slingshot::ClearLoadedAngrySparty()
{
    mLoadedSparty = nullptr;
    mLoadedSpartySP = nullptr;
}