#include "pch.h"
#include "AdVideoVungle.h"
#include "Common.h"
#include "AdKit/Video/AdVideoCommon.h"
#include "AdKit/AdConfig/AdConfig.h"
#include "AdSDKInitVungle.h"

using namespace Common;
using namespace Windows::Foundation;
using namespace Windows::ApplicationModel::Core;

//Using VungleSDK namespace
//using namespace VungleSDK;


AdVideoVungle ^ s_AdVideoVungle = nullptr;
AdVideoVungle ^ AdVideoVungle::Main()
{
	if (s_AdVideoVungle != nullptr)
	{
		return s_AdVideoVungle;
	}
	s_AdVideoVungle = ref new AdVideoVungle();
	return s_AdVideoVungle;
}

AdVideoVungle::AdVideoVungle()
{
	source = SOURCE_VUNGLE;
	isLoading =false;
}



void AdVideoVungle::InitAd(String ^ appId, String ^ appKey)
{
	strAppId = appId;
	strAppKey = appKey;  
}

void AdVideoVungle::SetObjectInfo(String ^ objName, String ^ objMethod)
{
}

void AdVideoVungle::LoadAd()
{
 
}
void AdVideoVungle::ShowAd()
{
 
}

  

