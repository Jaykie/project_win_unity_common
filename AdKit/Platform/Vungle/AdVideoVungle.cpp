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
	sdkInstance = AdSDKInitVungle::Main()->GetSDKInstance();
}

void AdVideoVungle::SetObjectInfo(String ^ objName, String ^ objMethod)
{
}

void AdVideoVungle::LoadAd()
{
	String ^ adId = AdConfig::Main()->GetAdId(SOURCE_VUNGLE, AD_TYPE_VIDEO);
	std::string placement = PlatformString2string(adId);
	sdkInstance->LoadAd(ref new Platform::String(std::wstring(placement.begin(), placement.end()).c_str()));
}
void AdVideoVungle::ShowAd()
{
	//this.Invoke(() = >
	//{
	//	//update UI code
	//
	//});
	if (isLoading == true)
	{
		//return;
	}
	isLoading = true;
	//interstitialAd->RequestAd(AdType::Video, L"d25517cb-12d4-4699-8bdc-52040c712cab", L"11389925");
	String ^ appId = AdConfig::Main()->GetAppId(SOURCE_VUNGLE);
	String ^ adId = AdConfig::Main()->GetAdId(SOURCE_VUNGLE, AD_TYPE_VIDEO);

	std::string placement = PlatformString2string(adId);
	//Play ad for placement1
	sdkInstance->PlayAdAsync(ref new VungleSDK::AdConfig, ref new Platform::String(std::wstring(placement.begin(), placement.end()).c_str()));
	 
}

 

//adinsert  

//Event handler for OnInitComleted event
void AdVideoVungle::OnInitCompleted(Platform::Object ^sender, VungleSDK::ConfigEventArgs ^args)
{
	//isLoading = false;

	//AdVideoCallBack::Main()->AdDidClose();
}

// Event handler called when e->AdPlayable is changed
void AdVideoVungle::OnOnAdPlayableChanged(Platform::Object ^sender, VungleSDK::AdPlayableEventArgs ^args)
{
	/*
	//Run asynchronously on the UI thread
	CoreApplication::MainView->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
		ref new Windows::UI::Core::DispatchedHandler(
			[this, args]
	{
		// args->AdPlayable - true if an ad is available to play, false otherwise
		// args->Placement  - placement ID in string

		//Change IsEnabled property for each button
		bool adPlayable = args->AdPlayable;
		//args->
		const wchar_t* wide_chars = args->Placement->Data();
		char chars[512];
		size_t converted;
		wcstombs_s(&converted, chars, 512, wide_chars, 512);
		std::string placement = chars;
		if (placement.compare(placement1) == 0) {
			this->PlayPlacement1->IsEnabled = adPlayable;
		}
		else if (placement.compare(placement2) == 0) {
			this->PlayPlacement2->IsEnabled = adPlayable;
		}
		else if (placement.compare(placement3) == 0) {
			this->PlayPlacement3->IsEnabled = adPlayable;
		}

		std::stringstream dmess;
		dmess << std::endl << "OnAdPlayable: " << placement << " - " << adPlayable << std::endl;

		OutputDebugStringA(dmess.str().c_str());
	}));
	*/
}

// Event Handler called before playing an ad
void AdVideoVungle::OnAdStart(Platform::Object^ sender, VungleSDK::AdEventArgs^ e)
{

	// e.Id        - Vungle app ID in string
	// e.Placement - placement ID in string
	/*
	std::stringstream dmess;
	size_t converted;
	const wchar_t* wcId = e->Id->Data();
	char cId[512];
	wcstombs_s(&converted, cId, 512, wcId, 512);
	const wchar_t* wcPlacement = e->Placement->Data();
	char cPlacement[512];
	wcstombs_s(&converted, cPlacement, 512, wcPlacement, 512);

	dmess << std::endl << "OnAdStart(" << cId << "): " << cPlacement << std::endl;

	OutputDebugStringA(dmess.str().c_str());

	//sdkInstance->LoadAd(ref new Platform::String(std::wstring(placement2.begin(), placement2.end()).c_str()));
	*/

	isLoading = false;
	// The ad is ready to show; show it.

	CoreApplication::GetCurrentView()->TitleBar->ExtendViewIntoTitleBar = true;
}

// DEPRECATED - use SdkInstance_OnAdEnd() instead
void AdVideoVungle::OnVideoView(Platform::Object^ sender, VungleSDK::AdViewEventArgs^ e) { }

// Event handler called when the user leaves ad and control is return to the hosting app
void AdVideoVungle::OnAdEnd(Platform::Object^ sender, VungleSDK::AdEndEventArgs^ e)
{
	/*
	// e->Id                  - Vungle app ID in string
	// e->Placement           - placement ID in string
	// e->IsCompletedView     - true when 80% or more of the video was watched
	// e->CallToActionClicked - true when the user has clicked download button on end card
	// e->WatchedDuration     - duration of video watched
	// e->VideoDuration       - DEPRECATED
	std::stringstream dmess;
	size_t converted;
	const wchar_t* wcId = e->Id->Data();
	char cId[512];
	wcstombs_s(&converted, cId, 512, wcId, 512);

	const wchar_t* wcPlacement = e->Placement->Data();
	char cPlacement[512];
	wcstombs_s(&converted, cPlacement, 512, wcPlacement, 512);

	dmess << std::endl << "OnVideoEnd(" << cId << "): " << "\n\tPlacement: " << cPlacement << "\n\tIsCompletedView: " << e->IsCompletedView;
	dmess << "\n\tCallToActionClicked: " << e->CallToActionClicked << "\n\tWatchedDuration: " << e->WatchedDuration.Duration << std::endl;

	OutputDebugStringA(dmess.str().c_str());


	//sdkInstance->LoadAd(ref new Platform::String(std::wstring(placement2.begin(), placement2.end()).c_str()));
	*/

	isLoading = false;
	AdVideoCallBack::Main()->AdDidFinish();
}

// Event handler called when SDK wants to print diagnostic logs
void AdVideoVungle::Diagnostic(Platform::Object^ sender, VungleSDK::DiagnosticLogEvent^ e)
{
	/*
	std::stringstream dmess;
	size_t converted;
	const wchar_t* wcLevel = e->Level.ToString()->Data();
	char cLevel[512];
	wcstombs_s(&converted, cLevel, 512, wcLevel, 512);

	const wchar_t* wcType = e->Type.Name->Data();
	char cType[512];
	wcstombs_s(&converted, cType, 512, wcType, 512);

	const wchar_t* wcException = e->Exception.ToString()->Data();
	char cException[512];
	wcstombs_s(&converted, cException, 512, wcException, 512);

	const wchar_t* wcMessage = e->Message->Data();
	char cMessage[512];
	wcstombs_s(&converted, cMessage, 512, wcMessage, 512);

	dmess << std::endl << "Diagnostics: " << cLevel << " " << cType << " " << cException << " " << cMessage;

	OutputDebugStringA(dmess.str().c_str());
	*/
}

