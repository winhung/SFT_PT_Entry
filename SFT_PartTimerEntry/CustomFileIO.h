#include <fstream>
#include <string>
#include <iostream> //cout, cin

namespace SFT
{
	class CustomFileIO
	{
	public:
		enum DataType
		{
			DEPT = 0,
			FULLNAME = 1,
			USERNAME = 2,
			EMAIL = 3	
		};

		//ctor
		CustomFileIO( char *pFileName )
		{
			if( ReadFile( pFileName ) )
				std::cout << "Read File Successful." << std::endl;
			else
				std::cout << "Read File Failed." << std::endl;

			//init all to empty string, just to be sure
			Dept , FullName, Username, Email = "";
			
			std::cout << std::endl;
		}//ctor

		~CustomFileIO()
		{
		}//dtor

		bool ReadFile( char *pFilename );
		bool WriteFile( char *pFileToWrite, char *pContent );
		
		//Move to end of file
		//bool NextLineUntilCannot ();

		//test func to check if the contents of the file can be viewed
		void DisplayContent();

		//func to check if file was open proplery
		bool IsFileOpenSuccessfully();

		//Set fullname
		void SetData( DataType d );

		//Set username
		void SetUsername( char *pUsername );

		//Ensure that the username given is one word only. Eg.whchan
		bool VerifyUsernameSyntax( const char *pUsername );

		//Set email
		void SetEmail( char *pEmail );
				
		//Ensure that user enters a valid email. Meaning, must be seperated by only one '@'
		bool VerifyEmailSyntax ( const char *pEmail );

		//set dept
		void SetDept( char *pDept );
				
	private:
		std::string Dept, FullName, Username, Email;
		std::fstream fs;
	};



}//SFT
