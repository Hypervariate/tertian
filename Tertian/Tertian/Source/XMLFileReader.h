#ifndef XMLFILEREADER_H_
#define XMLFILEREADER_H_

#include <iostream>
#include <string>

using namespace std;
#include "tinyxml.h"

class XMLFileReader{
public:
	XMLFileReader();
	~XMLFileReader();

	bool OpenFile(char* file_path);
	bool CloseFile();

	string GetToken(char* tag);

private:
	TiXmlDocument doc;
};


#endif