////////////////////////////////////////////////////
//	
//	© 2015 Turbulant Games, all rights reserved
//
//	File: File.cpp
//
//	CREATION
//  Creator: JAMES	
//	Time Created: 5/24/2016 3:27 PM
//
//	EDITS
//	Last Editor Name: JAMES
//	Last Edit Time: 5/24/2016 3:27 PM
//
////////////////////////////////////////////////////
#include "File.hpp"

#include <sys\stat.h>
#include <fstream>

using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::ios;

namespace SmartIO
{
	File::File(const char* aFileName)
	{
		//If the argument is null, make this null.
		if (aFileName == nullptr)
		{
			mFileName = nullptr;
			return;
		}

		//Allocate a size for mFileName, and copy the string over.
		mFileName = static_cast<char*>(malloc(strlen(aFileName)));
		strcpy(mFileName, aFileName);
	}

	File::File(const File& aOtherFile)
	{
		*this = aOtherFile;
	}

	File::~File()
	{
		//Free and set to null
		free(mFileName);
		mFileName = nullptr;
	}

	string EncryptDecrypt(const string& aToEncrypt)
	{
		//Create the encryption key array and copy the parameter
		char key[3] = { 'K', 'C', 'Q' };
		string output = aToEncrypt;
		
		//Loop through the string
		for (unsigned int iter = 0; iter < aToEncrypt.size(); iter++)
		{
			//Encrypt/Decrypt the file string using the XOR operator
			output[iter] = aToEncrypt[iter] ^ key[iter % (sizeof(key) / sizeof(char))];
		}

		//Return the output of the encryption/decryption
		return output;
	}

	bool File::Create(bool aOverrite)
	{
		//Check if the file exists
		if (!Exists() || aOverrite)
		{
			//Attempt to open the file
			FILE* file = fopen(mFileName, "w");

			//Check if it exists now
			if (file == nullptr)
			{
				//Print the error message.
				printf_s("File '%s' could not be created!\n", mFileName);
			}
			else
			{
				//The file created so return true.
				return true;
			}
		}
		else
		{
			//Print the error message.
			printf_s("File '%s' could not be created as it already exists and I wasn't told to overrite!\n", mFileName);
		}

		//Already exists or didn't create, so return false
		return false;
	}

	bool File::Delete()
	{
		//Check if the file exists
		if (Exists())
		{
			//Attempt to delete file
			if (remove(mFileName) != 0)
			{
				//Print the error message.
				printf_s("File '%s' could not be deleted!\n", mFileName);
			}
			else
			{
				//The file was created so return true.
				return true;
			}
		}
		else
		{
			//Print the error message.
			printf_s("File '%s' could not be deleted as it does not exist!\n", mFileName);
		}

		//The file didn't exist or failed to delete so return false.
		return false;
	}

	bool File::Exists()
	{
		//Try and check if the file exists
		struct stat buffer;
		return (stat(mFileName, &buffer) == 0);
	}

	bool File::Encrypt()
	{
		//Check if the file exists
		if (Exists())
		{
			//Attempt to read the file
			vector<string> fileContents = ReadAll();

			//Check we got data out of the file
			if (fileContents.size() > 0)
			{
				//Loop through all the file contents
				for (auto& iter : fileContents)
				{
					//Attempt to encrypt to line
					iter = EncryptDecrypt(iter);
				}

				//Open the file for write.
				ofstream file(mFileName, ios::out);
				if (file.is_open())
				{
					//Clear the file and close it.
					file.clear();
					file.close();
				}

				//Loop through all the file contents
				for (auto& iter : fileContents)
				{
					//Write this line to the file.
					Write(iter.c_str());
				}

				//We successfully encrypted the file so return true
				return true;
			}
			else
			{
				//Print the error message.
				printf_s("File '%s' could not be encrypted as it has no contents!\n", mFileName);
			}
		}
		else
		{
			//Print the error message.
			printf_s("File '%s' could not be encrypted as it does not exist!\n", mFileName);
		}

		//We could encrypt the file as it wasn't found or couldn't be read.
		return false;
	}

	bool File::Decrypt()
	{
		//Check if the file exists
		if (Exists())
		{
			//Attempt to read the file
			vector<string> fileContents = ReadAll();

			//Check we got data out of the file
			if (fileContents.size() > 0)
			{
				//Loop through all the file contents
				for (auto& iter : fileContents)
				{
					//Attempt to decrypted to line
					iter = EncryptDecrypt(iter);
				}

				//Open the file for write.
				ofstream file(mFileName, ios::out);
				if (file.is_open())
				{
					//Clear the file and close it.
					file.clear();
					file.close();
				}

				//Loop through all the file contents
				for (auto& iter : fileContents)
				{
					//Write this line to the file.
					Write(iter.c_str());
				}

				//We successfully decrypted the file so return true
				return true;
			}
			else
			{
				//Print the error message.
				printf_s("File '%s' could not be decrypted as it has no contents!\n", mFileName);
			}
		}
		else
		{
			//Print the error message.
			printf_s("File '%s' could not be decrypted as it does not exist!\n", mFileName);
		}

		//We could decrypt the file as it wasn't found or couldn't be read.
		return false;
	}

	bool File::Move(const char* aNewLocation)
	{
		//Check if the file exists
		if (Exists())
		{
			//Copy param to string
			string newLocation = aNewLocation;
			
			//Check if the parameter has an extension at the end
			if (newLocation.rfind(".") != string::npos)
			{
				//Get the current filename and extension
				string fileName = mFileName;
				fileName = fileName.substr(fileName.find_last_of("/") + 1, string::npos);

				//Add it to the new location
				newLocation.append(fileName);
			}

			//Attempt to delete file
			if (rename(mFileName, newLocation.c_str()) != 0)
			{
				//Print the error message.
				printf_s("File '%s' could not be moved!\n", mFileName);
			}
			else
			{
				//Resize the file name.
				free(mFileName);
				mFileName = static_cast<char*>(malloc(strlen(newLocation.c_str()) + 1));

				//Set the internal filename
				strcpy(mFileName, newLocation.c_str());

				//The file was created so return true.
				return true;
			}
		}
		else
		{
			//Print the error message.
			printf_s("File '%s' could not be moved as it does not exist!\n", mFileName);
		}

		//The file didn't exist or failed to move so return false.
		return false;
	}

	bool File::Write(const char* aDataToWrite, bool aAppend)
	{
		//Check if the file exists
		if (Exists())
		{
			//Attempt to open the file
			ofstream file(mFileName, ios::out | (aAppend ? ios::app : 0));
			if (file.is_open())
			{
				//Write the data to the file and close
				file << aDataToWrite;
				file.close();

				//Return successful
				return true;
			}
			else
			{
				//Print the error message.
				printf_s("File '%s' could not be written to as it could not open!\n", mFileName);
			}
		}
		else
		{
			//Print the error message.
			printf_s("File '%s' could not be written to as it does not exist!\n", mFileName);
		}

		//We could write to the file as it wasn't found or couldn't be read.
		return false;
	}

	string File::ReadLine()
	{
		//Create temp string variable
		string line = "";

		//Check if the file exists
		if (Exists())
		{
			//Attempt to open the file
			ifstream file(mFileName, ios::in);
			if (file.is_open())
			{
				//read the line from the file and close
				getline(file, line);
				file.close();

				//Return successful
				return line;
			}
			else
			{
				//Print the error message.
				printf_s("File '%s' could not be written to as it could not open!\n", mFileName);
			}
		}
		else
		{
			//Print the error message.
			printf_s("File '%s' could not be written to as it does not exist!\n", mFileName);
		}

		//We could write to the file as it wasn't found or couldn't be read.
		return line;
	}

	string File::ReadLineAt(unsigned int aLineIndex)
	{
		//Create temp string variable
		string line = "";

		//Check if the file exists
		if (Exists())
		{
			//Attempt to open the file
			ifstream file(mFileName, ios::in);
			if (file.is_open())
			{
				int index = 0;
				//Read all lines until we get to the correct index
				while (getline(file, line))
				{
					//Check if this is the correct index
					if (index == aLineIndex) break;

					//It wasn't so increment
					index++;
				}

				file.close();

				//Return successful
				return line;
			}
			else
			{
				//Print the error message.
				printf_s("File '%s' could not be written to as it could not open!\n", mFileName);
			}
		}
		else
		{
			//Print the error message.
			printf_s("File '%s' could not be written to as it does not exist!\n", mFileName);
		}

		//We could write to the file as it wasn't found or couldn't be read.
		return line;
	}

	vector<string> File::ReadAll()
	{
		//Create temp string variable
		vector<string> lines;
		string line = "";

		//Check if the file exists
		if (Exists())
		{
			//Attempt to open the file
			ifstream file(mFileName, ios::in);
			if (file.is_open())
			{
				//Read all lines until we get to the correct index
				while (getline(file, line))
				{
					//Add this line to the vector
					lines.push_back(line);
				}

				file.close();

				//Return successful
				return lines;
			}
			else
			{
				//Print the error message.
				printf_s("File '%s' could not be written to as it could not open!\n", mFileName);
			}
		}
		else
		{
			//Print the error message.
			printf_s("File '%s' could not be written to as it does not exist!\n", mFileName);
		}

		//We could write to the file as it wasn't found or couldn't be read.
		return lines;
	}
}