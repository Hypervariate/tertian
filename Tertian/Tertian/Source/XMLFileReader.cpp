#include "XMLFileReader.h"
XMLFileReader::XMLFileReader(char* file_path)
{
	OpenFile(file_path);
}
XMLFileReader::XMLFileReader()
{

}
XMLFileReader::~XMLFileReader()
{

}
//example: OpenFile("Data/Animations/test.xml");
bool XMLFileReader::OpenFile(char* file_path)
{
	
    bool loadOkay = doc.LoadFile(file_path);

    if ( loadOkay )
		cout << "Loaded xml file " << doc.Value() << endl;
	else
		cout << "Failed to load xml file " << doc.Value() << endl;
    
	return loadOkay;
}
//will return "" if the instance of the tag could not be found
const char* XMLFileReader::GetToken(char* tag, unsigned int instance_of_tag)
{
	TiXmlNode* node = doc.FirstChild();
	TiXmlElement* element = node->NextSiblingElement();
	bool tags_match = false;
	for( int i = 0; element; element=element->NextSiblingElement()){
		
		if(strcmp(tag, element->Value()) == 0)
			tags_match = true;
		else
			tags_match = false;

		if(tags_match == true)
		{
			if(i == instance_of_tag)
				return element->GetText();
			else
				i++;
		}
		
	}
	return "";
}
