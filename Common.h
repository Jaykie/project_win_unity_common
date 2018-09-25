#pragma once

#include <windows.h>  
#include <string>   

//#include "AdKit/Banner/AdBannerCommon.h"
//#include "AdKit/Insert/AdInsertCommon.h"
//#include "AdKit/Video/AdVideoCommon.h"
#define DLLExport _declspec(dllexport)

/* @moon
要引用Windows相关reference需要将工程的consume windows runtime extension 设置为yes
*/
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

#define SOURCE_MICROSOFT "microsoft"//microsoft

extern "C"
{
	//banner
	DLLExport void AdBanner_SetUIParent(Panel^ parent);
	DLLExport void AdBanner_InitAd(char* source);
	DLLExport void AdBanner_ShowAd(bool isShow);
	DLLExport void AdBanner_SetScreenSize(int w, int h);
	DLLExport void AdBanner_SetScreenOffset(int x, int y);

	//insert

	DLLExport void AdInsert_InitAd(char* source);
	DLLExport void AdInsert_ShowAd();
	DLLExport void AdInsert_SetObjectInfo(char* objName);

	//Video 
	DLLExport void AdVideo_InitAd(char* source);
	DLLExport void AdVideo_SetType(int type);
	DLLExport void AdVideo_ShowAd();
	DLLExport void AdVideo_SetObjectInfo(char* objName, char*objMethod);
	DLLExport void AdVideo_OnClickAd();
	
	//adconfig 
	DLLExport void AdConfig_InitPlatform(char* source, int type, char* appId, char* appKey, char* adKey);
	DLLExport void AdConfig_SetNoAd();
	
	/*DLLExport void AdConfig_SetAdSource(int type, char* source);
	DLLExport void AdConfig_SetAppId(char* source, char* appid);
	DLLExport void AdConfig_SetAdKey(char* source, int type, char* key);
	DLLExport void AdConfig_SetConfig(int type, char* source, char* appid, char* adkey);
*/

	//string
	DLLExport std::wstring s2ws(const std::string& s);
	DLLExport std::string ws2s(std::wstring& inputws);
	DLLExport String^ string2PlatformString(const std::string& s);
	DLLExport std::string  PlatformString2string(String^ s);
	
	//appinfo
	DLLExport char* Common_GetAppName();
	DLLExport char* Common_GetAppPackage();
	DLLExport char* Common_GetAppVerssion();
}