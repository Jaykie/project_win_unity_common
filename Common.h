#pragma once

#include <windows.h>
#include <string>
#include "Source.h"
//#include "AdKit/Banner/AdBannerCommon.h"
//#include "AdKit/Insert/AdInsertCommon.h"
//#include "AdKit/Video/AdVideoCommon.h"
#define DLLExport _declspec(dllexport)
typedef void(__stdcall *AdBannerCallbackUnity)(char *source, char *method, int w, int h);
typedef void(__stdcall *AdInsertCallbackUnity)(char *source, char *method);
typedef void(__stdcall *AdVideoCallbackUnity)(char *source, char *method);
typedef void(__stdcall *MediaPlayerEventCallbackUnity)(char *status);


/* @moon
要引用Windows相关reference需要将工程的consume windows runtime extension 设置为yes
*/
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

extern "C"
{
	//banner
	DLLExport void AdBanner_SetUIParent(Panel ^ parent);
	DLLExport void AdBanner_InitAd(char *source);
	DLLExport void AdBanner_ShowAd(bool isShow);
	DLLExport void AdBanner_SetScreenSize(int w, int h);
	DLLExport void AdBanner_SetScreenOffset(int x, int y);
	DLLExport void AdBanner_SetCallbackUnity(AdBannerCallbackUnity callback); //c#回调函数

	//insert

	DLLExport void AdInsert_InitAd(char *source);
	DLLExport void AdInsert_ShowAd();
	DLLExport void AdInsert_SetObjectInfo(char *objName);
	DLLExport void AdInsert_SetCallbackUnity(AdInsertCallbackUnity callback); //c#回调函数

	//Video
	DLLExport void AdVideo_InitAd(char *source);
	DLLExport void AdVideo_PreLoad(char *source);
	DLLExport void AdVideo_SetType(int type);
	DLLExport void AdVideo_ShowAd();
	DLLExport void AdVideo_SetObjectInfo(char *objName, char *objMethod);
	DLLExport void AdVideo_OnClickAd();
	DLLExport void AdVideo_SetCallbackUnity(AdVideoCallbackUnity callback); //c#回调函数

	//adconfig
	DLLExport void AdConfig_InitPlatform(char *source, int type, char *appId, char *appKey, char *adKey);
	DLLExport void AdConfig_SetNoAd();

	//Media
	DLLExport void MediaPlayer_Open(char *url);
	DLLExport void MediaPlayer_Close();
	DLLExport void MediaPlayer_Play();
	DLLExport void MediaPlayer_Pause();
	DLLExport void MediaPlayer_SetCallbackUnity(MediaPlayerEventCallbackUnity callback); //c#回调函数


	/*DLLExport void AdConfig_SetAdSource(int type, char* source);
	DLLExport void AdConfig_SetAppId(char* source, char* appid);
	DLLExport void AdConfig_SetAdKey(char* source, int type, char* key);
	DLLExport void AdConfig_SetConfig(int type, char* source, char* appid, char* adkey);
*/

	//string
	DLLExport std::wstring s2ws(const std::string &s);
	DLLExport std::string ws2s(std::wstring &inputws);
	DLLExport String ^ string2PlatformString(const std::string &s);
	DLLExport std::string PlatformString2string(String ^ s);

	//appinfo
	DLLExport char *Common_GetAppName();
	DLLExport char *Common_GetAppPackage();
	DLLExport char *Common_GetAppVerssion();
}