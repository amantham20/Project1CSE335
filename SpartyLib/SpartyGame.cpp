/**
 * @file SpartyGame.cpp
 * @author Rajmeet Singh Chandok
 *
 */

#include "pch.h"
#include "SpartyGame.h"
#include "Block.h"
#include "Level.h"
#include "Background.h"

/**
 * constructor
 */
SpartyGame::SpartyGame()
{
    mTotalScore = new Score(0);
    testlevel = new Level(this);


}

/**
 * Draw the SpartyGame
 * @param dc The device context to draw on
 */
void SpartyGame::OnDraw(wxDC *dc)
{
    testlevel->Draw(dc);
}

/**
 * Save the SpartyGame as a .sparty XML file.
 *
 * Open an XML file and stream the aquarium data to it.
 *
 * @param filename The filename of the file to save the aquarium to
 */
void SpartyGame::Save(const wxString &filename)
{
    wxXmlDocument xmlDoc;

    auto root = new wxXmlNode(wxXML_ELEMENT_NODE, L"sparty");
    xmlDoc.SetRoot(root);

    // Iterate over all items and save them
/*    for (const auto& level : Level)
    {
        item->XmlSave(root);
    }*/

    if(!xmlDoc.Save(filename, wxXML_NO_INDENTATION))
    {
        wxMessageBox(L"Write to XML failed");
        return;
    }
}

/**
 * Loads the contents of the xml file into the SpartyGame
 * @param filename
 */
void SpartyGame::Load(const wxString &filename)
{
    // Make sure the given file(s) can be opened
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Level file");
        return;
    }

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //
    auto child = root->GetChildren();
    for( ; child; child=child->GetNext()) {
        testlevel->Load(child);
    }
}
