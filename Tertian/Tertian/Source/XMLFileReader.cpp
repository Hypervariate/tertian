#include "XMLFileReader.h"

XMLFileReader::XMLFileReader()
{

}
XMLFileReader::~XMLFileReader()
{

}

bool XMLFileReader::OpenFile(char* file_path)
{
	
    bool loadOkay = doc.LoadFile(file_path);

    if ( loadOkay )
    {
        // Your document is loaded - do what you like
        // with it.
        //
        // Here we'll dump the structure to STDOUT,
        // just for example
        cout << "Loaded xml file " << doc.Value() << endl << endl;
		
    }
    else
    {
        // load failed
		cout << "failed to load xml file" << endl;
    }
	
	return loadOkay;
}
bool XMLFileReader::CloseFile()
{
	return false;
}
string XMLFileReader::GetToken(char* tag)
{
	TiXmlElement* element = doc.FirstChildElement(tag);
	string value = element->GetText();
	cout << value << endl;
	return value;
}