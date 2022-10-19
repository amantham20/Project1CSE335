/**
 * @file SpartyGame.cpp
 * @author Rajmeet Singh Chandok
 *
 */

#include "pch.h"
#include "SpartyGame.h"

/**
 * constructor
 */
SpartyGame::SpartyGame()
{
    mTotalScore = new Score(0);
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
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        if(name == L"items")
        {
            // Items tag found. LOAD EVERY ITEM IN THE ITEMS TAG

            //LoadXMLItems(child);

        } else if (name == L"angry")
        {
            // Angry tag found. LOAD EVERY ANGRY SPARTY IN THE ANGRY TAG
            //LoadXMLSparties(child);

        }
    }
}

/**
 * Loads every item in the items parent tag
 * @param node
 *//*

void SpartyGame::LoadXMLItems(wxXmlNode *node)
{
    // Get the first item in the items parent tag
    auto child = node->GetChildren();

    // Iterate over every item inside the items tag
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        // todo: Load every item in the items tag

    }

}

*/
/**
 * Loads every angry sparty in the angry parent tag
 * @param node
 *//*

void SpartyGame::LoadXMLSparties(wxXmlNode *node)
{
    // todo: Implement load function to load the angry sparties

}*/
