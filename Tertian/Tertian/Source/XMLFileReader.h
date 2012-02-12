#ifndef XMLFILEREADER_H_
#define XMLFILEREADER_H_

#include <iostream>
using namespace std;

#include "tinyxml.h"

class XMLFileReader{
public:
	XMLFileReader(char* file_path);
	XMLFileReader();
	~XMLFileReader();

	bool OpenFile(char* file_path);

	const char* GetToken(char* tag, unsigned int instance_of_tag = 0);

private:
	TiXmlDocument doc;
};


#endif