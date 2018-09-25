#pragma once
#include <vector>
#include <string>
using namespace Platform;

#define AD_TYPE_SPLASH  0
#define AD_TYPE_BANNER  1
#define AD_TYPE_INSERT  2
#define AD_TYPE_SPLASH_INSERT  3//¿ª»ú²åÆÁ
#define AD_TYPE_NATIVE  4
#define AD_TYPE_VIDEO  5

class AdInfo
{
public:
	AdInfo() 
	{}
	~AdInfo() {} 
	void print()
	{
		 
	}

 
public:
	std::string source;
	std::string appId;
	std::string appKey;
	std::string bannerId;
	std::string insertId;
	std::string videoId;
};

class AdConfig
{
public:
	AdConfig();
	~AdConfig();
	static AdConfig* Main();
	String^ GetAppId(std::string source);
	String^ GetAppKey(std::string source);
	String^ GetAdId(std::string source, int type);
	AdInfo* GetAd(std::string source);
	void InitPlatform(char* source, int type, char* appId, char* appKey, char* adKey);
	void SetNoAd();
/*
	void SetAdSource(int type, char* source);
	void SetAppId(char* source, char* appid);
	void SetAdKey(char* source, int type, char* key);
	void SetConfig(int type, char* source, char* appid, char* adkey);
*/
	std::vector<AdInfo*> listAd;
	 

};

