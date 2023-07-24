#pragma once
#ifndef xml
#define xml
#include <string>

//Common functions
//Parameters
class param
{
public:
	std::string path;
	std::string gvl;
	std::string adresse;
	std::string rom;
};

// Begin POU
void beginPou()
{

}

//End ST POU
void endPou()
{

}

//Begin global variables
void beginGvl()
{

}

//End global variables
void endGvl()
{

}

//Begin datatype
void beginDtu()
{

}

//End datatype
void endDtu()
{

}

//Begin variables
void beginVars()
{

}

//End variables
void endVariables()
{

}

// Program variables
void writeVars()
{

}



//CFC
//Class
class cfc
{
public:
	param parameters;
	int& master;
	int* knx;
	int* execOrder;
	int* id;
	int* x;
	int* y;
	bool* space;
};

//Comment
void drawComment(cfc& param, std::string comment)
{

}

//Input variable
void drawInput(std::string input)
{

}

//Connector
void drawConnector()
{

}

//Output
void drawOutput()
{

}

//Function
void drawFunction()
{

}

//Function block
void drawFb()
{

}

//Input variable function / fb
void drawInVar()
{

}

//InOut variable function / fb
void drawInOutVar()
{

}

//Ouput variable function / fb
void drawOutVar()
{

}
#endif