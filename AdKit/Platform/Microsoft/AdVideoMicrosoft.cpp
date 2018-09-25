#include "pch.h"
#include "AdVideoMicrosoft.h"
#include "Common.h"
#include "AdKit/Video/AdVideoCommon.h"
using namespace Common;
using namespace Windows::Foundation;
using namespace Windows::ApplicationModel::Core;

AdVideoMicrosoft^ s_AdVideoMicrosoft = nullptr;
AdVideoMicrosoft^ AdVideoMicrosoft::Main()
{
	if (s_AdVideoMicrosoft != nullptr) {
		return s_AdVideoMicrosoft;
	}
	s_AdVideoMicrosoft = ref new AdVideoMicrosoft();
	return s_AdVideoMicrosoft;
}

AdVideoMicrosoft::AdVideoMicrosoft()
{ 
	source = SOURCE_MICROSOFT;
	interstitialAd = ref new InterstitialAd();
	// Attach event handlers
	interstitialAd->ErrorOccurred += ref new EventHandler<AdErrorEventArgs^>(this, &AdVideoMicrosoft::OnErrorOccurred);
	interstitialAd->AdReady += ref new EventHandler<Object^>(this, &AdVideoMicrosoft::OnAdReady);
	interstitialAd->Cancelled += ref new EventHandler<Object^>(this, &AdVideoMicrosoft::OnAdCancelled);
	interstitialAd->Completed += ref new EventHandler<Object^>(this, &AdVideoMicrosoft::OnAdCompleted);
	isLoading = false;
}

 

  void  AdVideoMicrosoft::InitAd(String^ appId, String^ appKey) 
{
	strAppId = appId;
	strAppKey = appKey;
	


}
   
void AdVideoMicrosoft::SetObjectInfo(String^ objName, String^ objMethod)
{

}


void AdVideoMicrosoft::ShowAd()
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
	//interstitialAd->RequestAd(AdType::Video, L"d25517cb-12d4-4699-8bdc-52040c712cab", L"11389925");
	String^ appId = AdConfig::Main()->GetAppId(SOURCE_MICROSOFT);
	String^ adId = AdConfig::Main()->GetAdId(SOURCE_MICROSOFT, AD_TYPE_VIDEO);
	interstitialAd->RequestAd(AdType::Video, appId, adId);
}
 


//adinsert
// This is an event handler for the interstitial ad. It is triggered when the interstitial ad information has been downloaded and is ready to show.
void AdVideoMicrosoft::OnAdReady(Object^ sender, Object^ e)
{
	isLoading = false;
	// The ad is ready to show; show it.
	interstitialAd->Show();
	//关闭app窗口标题栏
	CoreApplication::GetCurrentView()->TitleBar->ExtendViewIntoTitleBar = true;
}

// This is an event handler for the interstitial ad. It is triggered when the interstitial ad is cancelled.
void AdVideoMicrosoft::OnAdCancelled(Object^ sender, Object^ e)
{
	isLoading = false;
	
	AdVideoCallBack::Main()->AdDidClose();
	//rootPage->NotifyUser("Ad cancelled", NotifyType::StatusMessage);
}

// This is an event handler for the interstitial ad. It is triggered when the interstitial ad has completed playback.
void AdVideoMicrosoft::OnAdCompleted(Object^ sender, Object^ e)
{
	isLoading = false;
	AdVideoCallBack::Main()->AdDidFinish();
	//rootPage->NotifyUser("Ad completed", NotifyType::StatusMessage);
}

// This is an error handler for the interstitial ad.
void AdVideoMicrosoft::OnErrorOccurred(Object^ sender, AdErrorEventArgs^ e)
{
	isLoading = false;
	AdVideoCallBack::Main()->AdDidFail();
	//rootPage->NotifyUser("An error occurred. " + e->ErrorCode.ToString() + ": " + e->ErrorMessage, NotifyType::ErrorMessage);
}
