#pragma once
 
#include "AdKit/Video/AdVideoBase.xaml.h"
#include "AdVideoCallBack.h"
#include "AdKit/AdConfig/AdConfig.h"
using namespace Common;
class AdVideoCommon
{
public:
	AdVideoCommon();
	~AdVideoCommon();

	static  AdVideoCommon* Main();
	void CreateAdBase(String^ source);
	void InitAd(char* source);
	void SetType(int type);
	void ShowAd();
	void SetObjectInfo(char* objName, char*objMethod);
	void OnClickAd();

protected:
	AdVideoBase^ adVideoBase;
};

