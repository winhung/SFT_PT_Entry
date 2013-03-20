#include "CustomFileIO.h"

namespace SFT
{
	
	bool CustomFileIO::ReadFile( char *pFilename )
	{
		fs.open( pFilename );

		return IsFileOpenSuccessfully();
	}//ReadFile
	
	bool CustomFileIO::IsFileOpenSuccessfully()
	{
		if( fs.fail() )
			return false; //File opened successfully

		//Cannot open file properly
		return true;
	}//IsFileOpenSuccessfully

	void CustomFileIO::DisplayContent()
	{
		while( fs.good() )
		{
			char c = fs.get();
			std::cout << c;		
		}//while	
	}//DisplayContent

	//Set Basic parameters
	void CustomFileIO::SetData( CustomFileIO::DataType d )
	{
		char reply = 'n';
		std::string CurrQn = "", CurrData = "";

		//Decide which question to ask
		switch( d )
		{
			case DEPT:
				CurrQn = "department";
				break;

			case FULLNAME:
				CurrQn = "full name";
				break;

			case USERNAME:
				CurrQn = "username";
				break;

			case EMAIL:
				CurrQn = "email";
				break;

			default:
				break;		
		}//switch-case

		while(reply != 'y')
		{
			CurrData = "";//instantiate it with empty string
			CurrData.clear(); //clear it's flags

			std::cout << "Please enter part-timer's " << CurrQn << std::endl;
			std::getline(std::cin, CurrData);

			if( d == DataType::USERNAME )
			{
				if( !VerifyUsernameSyntax(CurrData.c_str()) )
					continue; //restart !
			}//if
			else if( d == DataType::EMAIL )
			{
				if( !VerifyEmailSyntax(CurrData.c_str()) )
					continue; //restart !
			}//else-if

			std::cout << "You entered " << CurrData << std::endl;
			std::cout << "Is this correct ?" << std::endl;
			std::cout << "Please key in y for YES and n for NO." << std::endl;
			std::cin >> reply;

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear(); //clear it's flags			
		}//while

		//Set the data to the correct variables
		switch( d )
		{
			case DEPT:
				Dept = CurrData;
				break;

			case FULLNAME:
				FullName = CurrData;
				break;

			case USERNAME:
				Username = CurrData;
				break;

			case EMAIL:
				Email = CurrData;
				break;

			default:
				break;		
		}//switch-case



	}//SetFullname

	//Ensure that the username given is one word only. Eg.whchan
	bool CustomFileIO::VerifyUsernameSyntax( const char *pUsername )
	{
		return true;
		//return false;
	}//VerifyUsernameSyntax

	//Set email

	//Ensure that user enters a valid email. Meaning, must be seperated by only one '@'
	bool CustomFileIO::VerifyEmailSyntax ( const char *pEmail )
	{
		return true;
		//return false;
	}//VerifyEmailSyntax

	//set dept


}//SFT