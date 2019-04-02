#include "pch.h"
#include "AdInsertVungle.h"
#include "Common.h"
#include "AdKit/Insert/AdInsertCommon.h"
using namespace Common;
using namespace Windows::Foundation; 
using namespace Windows::ApplicationModel::Core;
using namespace Windows::UI::ViewManagement;
 
AdInsertVungle^ s_AdInsertVungle = nullptr;
AdInsertVungle^ AdInsertVungle::Main()
{
	if (s_AdInsertVungle != nullptr) {
		return s_AdInsertVungle;
	}
	s_AdInsertVungle = ref new AdInsertVungle();
	return s_AdInsertVungle;
}

AdInsertVungle::AdInsertVungle()
{
	source = SOURCE_VUNGLE;
	 
	isLoading = false;
}



void  AdInsertVungle::InitAd(String^ appId, String^ appKey)
{
	strAppId = appId;
	strAppKey = appKey;



}

void AdInsertVungle::SetObjectInfo(String^ objName, String^ objMethod)
{

}


void AdInsertVungle::ShowAd()
{
	//this.Invoke(() = >
	//{
	//	//update UI code
	//
	//});
	if (isLoading == true)
	{
		return;
	}
	isLoading = true;

	
	String^ appId = AdConfig::Main()->GetAppId(SOURCE_VUNGLE); 
	String^ adId = AdConfig::Main()->GetAdId(SOURCE_VUNGLE, AD_TYPE_INSERT);
	OutputDebugString(appId->Data());
	OutputDebugString(L"\n");
	OutputDebugString(adId->Data());
	OutputDebugString(L"\n");
	 
}


 
