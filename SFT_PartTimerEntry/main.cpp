#include "CustomFileIO.h"
#include <string>

#define _DEBUG true

int main()
{
	SFT::CustomFileIO Test_IO("SFT_STAFF.txt");
	SFT::CustomFileIO::DataType DT;	

	if(_DEBUG)
		Test_IO.DisplayContent();

	std::cout << "Welcome !" << std::endl;

	//Enter fullname, department, username and email	
	Test_IO.SetData(DT = SFT::CustomFileIO::DataType::FULLNAME);
	Test_IO.SetData(DT = SFT::CustomFileIO::DataType::DEPT);
	Test_IO.SetData(DT = SFT::CustomFileIO::DataType::USERNAME);
	Test_IO.SetData(DT = SFT::CustomFileIO::DataType::EMAIL);



	return 0;

}//main
