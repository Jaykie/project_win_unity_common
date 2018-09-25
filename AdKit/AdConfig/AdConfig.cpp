#include "pch.h"
#include "AdConfig.h"
#include "Common.h"

 void AdConfig_InitPlatform(char* source, int type, char* appId, char* appKey, char* adKey)
 {
	 AdConfig::Main()->InitPlatform(source, type, appId, appKey, adKey);
 }
 void AdConfig_SetNoAd()
 {
	 AdConfig::Main()->SetNoAd();
 }
/*
 void AdConfig_SetAdSource(int type, char* source)
 {

 }
 void AdConfig_SetAppId(char* source, char* appid)
 {

 }
 void AdConfig_SetAdKey(char* source, int type, char* key)
 {

 }
 void AdConfig_SetConfig(int type, char* source, char* appid, char* adkey)
 {

 }
*/

 AdConfig *s_AdConfig = NULL;
 AdConfig* AdConfig::Main()
 {
	 if (s_AdConfig != NULL) {
		 return s_AdConfig;
	 }
	 s_AdConfig = new AdConfig();
	 return s_AdConfig;
 }


 AdConfig::AdConfig()
 {
 }


 AdConfig::~AdConfig()
 {
 } 

 void AdConfig::InitPlatform(char* source, int type, char* appId, char* appKey, char* adKey)
 {
	 AdInfo* ad = GetAd(source);
	 bool isnew_ad = false;
	 if (ad== NULL)
	 {
		 ad = new AdInfo();
		 isnew_ad = true;
	 }
	 ad->source = source;
	 ad->appId = appId;
	 ad->appKey = appKey;
	 switch(type)
	 {
	 case AD_TYPE_SPLASH:
		 break;
	 case AD_TYPE_BANNER:
		 ad->bannerId = adKey;
		 break;
	 case AD_TYPE_INSERT:
		 ad->insertId = adKey;
		 break;
	 case AD_TYPE_SPLASH_INSERT:
		 break;
	 case AD_TYPE_NATIVE:
		 break;
	 case AD_TYPE_VIDEO:
		 ad->videoId = adKey;
		 break;
	 }
	 if (isnew_ad) {
		 listAd.push_back(ad);
	 }
	 else {
		 //
	 }

 }
 void AdConfig::SetNoAd()
 {

 }
 
 AdInfo* AdConfig::GetAd(std::string source)
 {
	 AdInfo *ad = NULL; 
	 int idx = 0;
	 for (std::vector<AdInfo*>::iterator iter = listAd.begin(); iter!=listAd.end(); iter++)
	 {
		 if (source == (*iter)->source) 
		 {
			 ad = listAd[idx];
			 break;
		 }
		 idx++;
	 }
	 return ad;
 }

 String^  AdConfig::GetAppId(std::string source)
 {
	 std::string ret = "";
	 AdInfo *ad = GetAd(source);
	 if (ad != NULL) {
		 ret = ad->appId;
	 }
	 return string2PlatformString(ret);
 }
 String^  AdConfig::GetAppKey(std::string source)
 {
	 std::string ret = "";
	 AdInfo *ad = GetAd(source);
	 if (ad != NULL) {
		 ret = ad->appKey;
	 }
	 return string2PlatformString(ret);
 }
 String^  AdConfig::GetAdId(std::string source,int type)
 {
	 std::string ret = "";
	 AdInfo *ad = GetAd(source);
	 if (ad!=NULL) {
		 switch (type)
		 {
		 case AD_TYPE_SPLASH:
			 break;
		 case AD_TYPE_BANNER:
			 ret = ad->bannerId;
			 break;
		 case AD_TYPE_INSERT:
			 ret = ad->insertId;
			 break;
		 case AD_TYPE_SPLASH_INSERT:
			 break;
		 case AD_TYPE_NATIVE:
			 break;
		 case AD_TYPE_VIDEO:
			 ret = ad->videoId;
			 break;
		 }
	 }
	 return string2PlatformString(ret);
 }

 /*
 void AdConfig::SetAdSource(int type, char* source)
 {

 }
 void AdConfig::SetAppId(char* source, char* appid)
 {

 }
 void AdConfig::SetAdKey(char* source, int type, char* key)
 {

 }
 void AdConfig::SetConfig(int type, char* source, char* appid, char* adkey)
 {

 }
*/

