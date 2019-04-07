#include "pch.h"
#include "AdSDKInitVungle.h"
#include "Common.h" 
#include "AdKit/AdConfig/AdConfig.h"
 
using namespace Common;
using namespace Windows::Foundation;
using namespace Windows::ApplicationModel::Core;

AdSDKInitVungle^ s_AdSDKInitVungle = nullptr;
AdSDKInitVungle^ AdSDKInitVungle::Main()
 {
	 if (s_AdSDKInitVungle != nullptr) {
		 return s_AdSDKInitVungle;
	 }
	 s_AdSDKInitVungle = ref new AdSDKInitVungle();
	 return s_AdSDKInitVungle;
 }


 AdSDKInitVungle::AdSDKInitVungle()
 {
 }
  

 void AdSDKInitVungle::Init(char* appId, char* appKey, char* adKey)
 {
	 InitSDK(string2PlatformString(appId), string2PlatformString(appKey));
 } 


 VungleSDK::VungleAd^ AdSDKInitVungle::GetSDKInstance()
 {
	 return sdkInstance;
 }

 bool AdSDKInitVungle::isPlacementEmpty(std::string placement)
 {
	 bool ret = false;
	 if (placement.empty() || (placement == "0"))
	 {
		 ret = true;
	 }

	 return ret;
 }

 void AdSDKInitVungle::InitSDK(String ^ appId, String ^ appKey)
 {
	 std::string appID = PlatformString2string(appId);// "598a531697c455bc70001f98";
	 std::string placement1 = "DEFAULT59086";
	 std::string placement2 = "NONREWA96669";
	 std::string placement3 = "REWARDE30999";

	 String ^ adIdVideo = AdConfig::Main()->GetAdId(SOURCE_VUNGLE, AD_TYPE_VIDEO);
	 if (adIdVideo==nullptr)
	 {
		 return;
	 }
	 placement1 = PlatformString2string(adIdVideo);
	 
	 String ^ adIdInsert = AdConfig::Main()->GetAdId(SOURCE_VUNGLE, AD_TYPE_INSERT);
	 if (adIdInsert == nullptr)
	 {
		 return;
	 }
	 placement2 = PlatformString2string(adIdInsert);
 

	 //Platform::Array<Platform::String^>^ placementsAlt = ref new Platform::Array<Platform::String^>(3);
	 //placementsAlt[0] = ref new Platform::String(std::wstring(placement1.begin(), placement1.end()).c_str());

	 //Obtain Vungle SDK instance
	 Platform::Array<Platform::String^>^ placements = ref new Platform::Array<Platform::String^>(2);
	 placements[0] = ref new Platform::String(std::wstring(placement1.begin(), placement1.end()).c_str());
	 placements[1] = ref new Platform::String(std::wstring(placement2.begin(), placement2.end()).c_str());
	// placements[2] = ref new Platform::String(std::wstring(placement3.begin(), placement3.end()).c_str());
	 sdkInstance = VungleSDK::AdFactory::GetInstance(ref new Platform::String(std::wstring(appID.begin(), appID.end()).c_str()), placements);

	 //Register event handlers
	 sdkInstance->OnAdPlayableChanged += ref new EventHandler<VungleSDK::AdPlayableEventArgs ^>(this, &AdSDKInitVungle::OnOnAdPlayableChanged);
	 sdkInstance->OnAdStart += ref new EventHandler<VungleSDK::AdEventArgs ^>(this, &AdSDKInitVungle::OnAdStart);
	 sdkInstance->OnAdEnd += ref new EventHandler<VungleSDK::AdEndEventArgs ^>(this, &AdSDKInitVungle::OnAdEnd);
	 //sdkInstance->Diagnostic += ref new EventHandler<VungleSDK::DiagnosticLogEvent ^>(this, &CPP_sample::MainPage::Diagnostic);
	 sdkInstance->OnInitCompleted += ref new EventHandler<VungleSDK::ConfigEventArgs ^>(this, &AdSDKInitVungle::OnInitCompleted);

 }



 //Event handler for OnInitComleted event
 void AdSDKInitVungle::OnInitCompleted(Platform::Object ^sender, VungleSDK::ConfigEventArgs ^args)
 {
	 //isLoading = false;

	 //AdVideoCallBack::Main()->AdDidClose();
 }

 // Event handler called when e->AdPlayable is changed
 void AdSDKInitVungle::OnOnAdPlayableChanged(Platform::Object ^sender, VungleSDK::AdPlayableEventArgs ^args)
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
 void AdSDKInitVungle::OnAdStart(Platform::Object^ sender, VungleSDK::AdEventArgs^ e)
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
 }

 // DEPRECATED - use SdkInstance_OnAdEnd() instead
 void AdSDKInitVungle::OnVideoView(Platform::Object^ sender, VungleSDK::AdViewEventArgs^ e) { }

 // Event handler called when the user leaves ad and control is return to the hosting app
 void AdSDKInitVungle::OnAdEnd(Platform::Object^ sender, VungleSDK::AdEndEventArgs^ e)
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

 }

 // Event handler called when SDK wants to print diagnostic logs
 void AdSDKInitVungle::Diagnostic(Platform::Object^ sender, VungleSDK::DiagnosticLogEvent^ e)
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

