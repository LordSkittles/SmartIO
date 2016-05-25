////////////////////////////////////////////////////
//	
//	© 2015 Turbulant Games, all rights reserved
//
//	File: Binary.hpp
//
//	CREATION
//  Creator: JESSE	
//	Time Created: 5/25/2016 1:17 PM
//
//	EDITS
//	Last Editor Name: JESSE
//	Last Edit Time: 5/25/2016 1:17 PM
//
////////////////////////////////////////////////////
#ifndef _BINARY_H_
#define _BINARY_H_

namespace SmartIO
{
	//!The binary class provides functionality to interchange between
	//!binary files and standard, non-binary files. The user can encode
	//!and decode data using a list of "format plugins"; which define
	//!how the type of file (that the plugin is dedicated to) interchanges
	//!between binary and standard format.
	//!
	//!@author Jesse Farag
	//!@version 1.0
	class Binary
	{
	public:
		//!Foo.
		//!
		//!@param aFooArg - Foo foo foo.
		//!@return bool - Boo.
		static bool Foo(const char* aFooArg);

	};
}

#endif //_BINARY_H_