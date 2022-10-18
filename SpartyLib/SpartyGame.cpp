/**
 * @file SpartyGame.cpp
 * @author Rajmeet Singh Chandok
 *
 */

#include "pch.h"
#include "SpartyGame.h"

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
    for (const auto& item : mItems)
    {
        item->XmlSave(root);
    }

    if(!xmlDoc.Save(filename, wxXML_NO_INDENTATION))
    {
        wxMessageBox(L"Write to XML failed");
        return;
    }
}