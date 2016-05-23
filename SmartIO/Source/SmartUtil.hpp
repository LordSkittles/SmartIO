////////////////////////////////////////////////////
//	
//	© 2015 Turbulant Games, all rights reserved
//
//	File: SmartUtil.hpp
//
//	CREATION
//  Creator: JAMES	
//	Time Created: 5/16/2016 10:34 AM
//
//	EDITS
//	Last Editor Name: JAMES
//	Last Edit Time: 5/16/2016 10:34 AM
//
////////////////////////////////////////////////////
#ifndef _SMART_UTIL_H_
#define _SMART_UTIL_H_

namespace SmartIO
{
	template<typename T>
	//!This struct lets the user know that the type they have
	//passed is not of pointer type.
	//
	//@since 1.0
	//@author James Mills
	struct is_pointer 
	{ 
		static const bool value = false;
	};

	template<typename T>
	//!This struct lets the user know that the type they have
	//passed is of pointer type.
	//
	//@since 1.0
	//@author James Mills
	struct is_pointer<T*> 
	{ 
		static const bool value = true; 
	};
}

#endif //_SMART_UTIL_H_