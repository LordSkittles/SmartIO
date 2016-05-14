////////////////////////////////////////////////////
//	
//	© 2015 Turbulant Games, all rights reserved
//
//	File: BinaryFormatter.hpp
//
//	CREATION
//  Creator: JAMES	
//	Time Created: 5/12/2016 7:35:17 AM
//
//	EDITS
//	Last Editor Name: JAMES
//	Last Edit Time: 5/12/2016 7:35:17 AM
//
////////////////////////////////////////////////////
#ifndef _BINARY_FORMATTER_H_
#define _BINARY_FORMATTER_H_

#include <fstream>
#include <vector>
#include <stdarg.h>

using std::ios;
using std::fstream;

namespace SmartIO
{
	//Define the byte type.
	typedef unsigned __int8 byte;

	//!The BinaryFormatter class takes in the passed data and sends it to the
	//relevant Binary file. This class is able to put any data into the binary
	//file being created as long as it is valid data.
	//
	//@since 1.0
	//@author James Mills
	class BinaryFormatter
	{
	public:
		//Remove base constructor of the BinaryFormatter class to force user 
		//to use custom constructor
		BinaryFormatter() = delete;

		//!The custom constructor of the BinaryFormatter class, this formatter
		//takes in the name of the file being written or read. Will default
		//the parameter to null string.
		//
		//@param aFileName - The name of the file that will be written or read,
		//defaults to null string.
		BinaryFormatter(const char* aFileName = "");

		template<typename T>
		//!Writes the data passed to the internal binary file. Can take as many
		//of one type at any time as needed. Will convert all to characters and
		//then add it to the file.
		//
		//@param aWriteAmount - The amount of data we wish to add to the binary
		//file.
		//@param Params - The data being added to the binary file. Uses variable
		//parameter lists.
		void Write(unsigned int aWriteAmount, T...)
		{
			//Attempt to open the binary file and check it didn't fail
			mBinaryFile.open(mFileName, ios::out | ios::binary);
			if (mBinaryFile.is_open() && !mBinaryFile.fail())
			{
				//Create the variable argument list and start it
				va_list variableList;
				va_start(variableList, aWriteAmount);

				//Loop through all the passed parameters and write them
				for (unsigned int iter = 0; iter < aWriteAmount; iter++)
				{
					//Get the value and write it
					T argVal = va_arg(variableList, T);
					mBinaryFile.write((char*)&argVal, sizeof(T));
				}

				//End the variable list
				va_end(variableList);
			}

			//Close the file
			mBinaryFile.close();
		}

		template<typename T>
		//!Reads the data into the passed variable parameter list. The list passed
		//must be references to data so that it can be added directly into it.
		//
		//@param aReadAmount - The amount of parameters that are being read from
		//the binary file.
		//@param Params - The data being read into from the binary file. Can be
		//as many parameters as was written into the function.
		void Read(unsigned int aReadAmount, T&...)
		{
			//Attempt to open the binary file and check it didn't fail
			mBinaryFile.open(mFileName, ios::in | ios::binary);
			if (mBinaryFile.is_open() && !mBinaryFile.fail())
			{
				//Create the variable argument list and start it
				va_list variableList;
				va_start(variableList, aReadAmount);

				//Loop through all the passed parameters and write them
				for (unsigned int iter = 0; iter < aReadAmount; iter++)
				{
					//Get the value and write it
					T& argVal = va_arg(variableList, T);
					mBinaryFile.read((char*)&argVal, sizeof(T));
				}

				//End the variable list
				va_end(variableList);
			}

			//Close the file
			mBinaryFile.close();
		}

	private:
		const char* mFileName; //!< The name and location of the file that is being written or read.
		fstream mBinaryFile; //!< The file being written to and read from.

	};
}

#endif