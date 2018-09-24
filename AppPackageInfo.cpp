#include "pch.h"
#include "AppPackageInfo.h"



using namespace Platform;  
using namespace Windows::Foundation; 
using namespace Windows::ApplicationModel;
 
//
//String^ ArchitectureString(Windows::System::ProcessorArchitecture architecture)
//{
//	switch (architecture)
//	{
//	case Windows::System::ProcessorArchitecture::X86:
//		return "x86";
//	case Windows::System::ProcessorArchitecture::Arm:
//		return "arm";
//	case Windows::System::ProcessorArchitecture::X64:
//		return "x64";
//	case Windows::System::ProcessorArchitecture::Neutral:
//		return "neutral";
//	case Windows::System::ProcessorArchitecture::Unknown:
//		return "unknown";
//	default:
//		return "???";
//	}
//}

AppPackageInfo *s_AppPackageInfo = NULL;
AppPackageInfo::AppPackageInfo()
{
}


AppPackageInfo::~AppPackageInfo()
{
}


AppPackageInfo* AppPackageInfo::Main()
{
	if (s_AppPackageInfo != NULL) {
		return s_AppPackageInfo;
	}
	s_AppPackageInfo = new AppPackageInfo();
	return s_AppPackageInfo;
}

String^ AppPackageInfo::GetAppName()
{
	Package^ package = Package::Current;
	PackageId^ packageId = package->Id;
	String^ s = package->DisplayName;
	//String^ u8 = ref new String(s->Data(),);
	return s;
}

String^ AppPackageInfo::GetPackage()
{
	Package^ package = Package::Current;
	PackageId^ packageId = package->Id;
	return packageId->Name;
}

String^ AppPackageInfo::GetAppVersion()
{
	Package^ package = Package::Current;
	PackageId^ packageId = package->Id;
	PackageVersion version = packageId->Version;
	return version.Major.ToString() + "." + version.Minor.ToString() + "." +
		version.Build.ToString();// +"." + version.Revision.ToString(); 
}


