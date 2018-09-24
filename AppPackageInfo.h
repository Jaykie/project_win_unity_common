#pragma once
using namespace Platform;

class AppPackageInfo
{
public:
	AppPackageInfo();
	~AppPackageInfo();

	static AppPackageInfo* Main();

	String^ GetAppName();
	String^ GetPackage();
	String^ GetAppVersion();
	 
};

