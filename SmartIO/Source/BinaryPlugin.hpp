////////////////////////////////////////////////////
//	
//	© 2015 Turbulant Games, all rights reserved
//
//	File: BinaryPlugin.hpp
//
//	CREATION
//  Creator: JESSE	
//	Time Created: 6/19/2016 6:35 PM
//
//	EDITS
//	Last Editor Name: JESSE
//	Last Edit Time: 6/19/2016 7:24 PM
//
////////////////////////////////////////////////////
#ifndef _BINARYPLUGIN_H_
#define _BINARYPLUGIN_H_

namespace SmartIO
{
	//!The binary plugin class is a derivable object. It provides the core logic needed by the Binary class
	//!to convert between a particular filetype, and a block of memory retrieved from the target binary file.
	//!
	//!@author Jesse Farag
	//!@version 1.0
	class BinaryPlugin
	{
		friend class Binary;

	public:

		//Remove the default constructor.
		BinaryPlugin() = delete;


	protected:

		//!The custom constructor sets the internal file name to the passed char string.
		//!
		//!@param aExtension - The extension of the filetype format that this plugin is for. Eg, ".obj", or ".png".
		BinaryPlugin(const char* aExtension);

	private:

		//!The copy constructor copies all members over from the other to this.
		//!
		//!@param aOtherFile - The object to copy from.
		BinaryPlugin(const BinaryPlugin& aOtherFile);

		//!The destructor deletes any memory allocated by this class.
		~BinaryPlugin();

		//!This will copy over member data from the other to this.
		//!
		//!@return BinaryPlugin - This object.
		BinaryPlugin& operator=(const BinaryPlugin& aOtherBinary);

		//!DESC
		//!
		//!@param NAME - DESC
		//!@return TYPE - DESC
	};
}

#endif //_BINARYPLUGIN_H_