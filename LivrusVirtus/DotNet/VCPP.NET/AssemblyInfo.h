// Copyright (C) 2002 Microsoft Corporation
// All rights reserved.
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER 
// EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF 
// MERCHANTIBILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// Requires the Trial or Release version of Visual Studio .NET Professional (or greater).

#pragma once

[assembly: AssemblyTitleAttribute(S"VC.NET How-To: Menus")];
[assembly: AssemblyDescriptionAttribute(S"Microsoft Visual C++ .NET How-To: Menus")];
[assembly: AssemblyCompanyAttribute(S"Microsoft Corporation")];
[assembly: AssemblyProductAttribute(S"Microsoft Visual C++ .NET How To: 2003")];
[assembly: AssemblyCopyrightAttribute(S"Copyright  2002-2003 Microsoft Corporation.  All rights reserved.")];
[assembly: AssemblyVersionAttribute(S"1.0.1")];
[assembly: CLSCompliant(true)];

namespace Livrus
{
	// This class uses the System.Reflection.Assembly class to access assembly metadata
	// This class is not a normal feature of AssemblyInfo.h
	public __gc class AssemblyInfo
	{
		// Used by Helper Functions to access information from Assembly Attributes
	private: 
		Type* myType;

	public:
		AssemblyInfo() { myType = GetType(); }

		__property System::String* get_AsmName(void)
		{
			return myType->Assembly->GetName()->Name; 
		}

		__property System::String* get_AsmFQName(void)
		{
			return myType->Assembly->get_FullName();
		}

		__property System::String* get_CodeBase(void)
		{
			return myType->Assembly->CodeBase;
		}

		__property System::String* get_Copyright(void)
		{
			Type* at = __typeof(AssemblyCopyrightAttribute);
			Object* r[] = myType->Assembly->GetCustomAttributes(at, false);
			AssemblyCopyrightAttribute* ct = static_cast<AssemblyCopyrightAttribute*>(r[0]);
			return ct->Copyright;
		}

		__property System::String* get_Company(void)
		{
			Type* at = __typeof(AssemblyCompanyAttribute);
			Object* r[] = myType->Assembly->GetCustomAttributes(at, false);
			AssemblyCompanyAttribute* ct = static_cast<AssemblyCompanyAttribute*>(r[0]);
			return ct->Company;
		}
		
		__property System::String* get_Description(void) 
		{ 
			Type* at = __typeof(AssemblyDescriptionAttribute);
			Object* r[] = myType->Assembly->GetCustomAttributes(at, false);
			AssemblyDescriptionAttribute* ct = static_cast<AssemblyDescriptionAttribute*>(r[0]);
			return ct->Description;
		}
		
		__property System::String* get_Product(void)		
		{ 
			Type* at = __typeof(AssemblyProductAttribute);
			Object* r[] = myType->Assembly->GetCustomAttributes(at, false);
			AssemblyProductAttribute* ct = static_cast<AssemblyProductAttribute*>(r[0]);
			return ct->Product;
		}
		
		__property System::String* get_Title(void)		
		{ 
			Type* at = __typeof(AssemblyTitleAttribute);
			Object* r[] = myType->Assembly->GetCustomAttributes(at, false);
			AssemblyTitleAttribute* ct = static_cast<AssemblyTitleAttribute*>(r[0]);
			return ct->Title;
		}
		
		__property System::String* get_Version(void)		
		{
			return myType->Assembly->GetName()->Version->ToString();
		}
	};
}