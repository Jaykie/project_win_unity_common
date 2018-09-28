#include "pch.h"
#include "AdInsertMicrosoft.h"
#include "Common.h"
#include "AdKit/Insert/AdInsertCommon.h"
using namespace Common;
using namespace Windows::Foundation; 
using namespace Windows::ApplicationModel::Core;
using namespace Windows::UI::ViewManagement;
 
AdInsertMicrosoft^ s_AdInsertMicrosoft = nullptr;
AdInsertMicrosoft^ AdInsertMicrosoft::Main()
{
	if (s_AdInsertMicrosoft != nullptr) {
		return s_AdInsertMicrosoft;
	}
	s_AdInsertMicrosoft = ref new AdInsertMicrosoft();
	return s_AdInsertMicrosoft;
}

AdInsertMicrosoft::AdInsertMicrosoft()
{
	source = SOURCE_MICROSOFT;
	interstitialAd = ref new InterstitialAd();
	// Attach event handlers
	interstitialAd->ErrorOccurred += ref new EventHandler<AdErrorEventArgs^>(this, &AdInsertMicrosoft::OnErrorOccurred);
	interstitialAd->AdReady += ref new EventHandler<Object^>(this, &AdInsertMicrosoft::OnAdReady);
	interstitialAd->Cancelled += ref new EventHandler<Object^>(this, &AdInsertMicrosoft::OnAdCancelled);
	interstitialAd->Completed += ref new EventHandler<Object^>(this, &AdInsertMicrosoft::OnAdCompleted);
	isLoading = false;
}



void  AdInsertMicrosoft::InitAd(String^ appId, String^ appKey)
{
	strAppId = appId;
	strAppKey = appKey;



}

void AdInsertMicrosoft::SetObjectInfo(String^ objName, String^ objMethod)
{

}


void AdInsertMicrosoft::ShowAd()
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

	//interstitialAd->RequestAd(AdType::Display, L"d25517cb-12d4-4699-8bdc-52040c712cab", L"11389925");
	String^ appId = AdConfig::Main()->GetAppId(SOURCE_MICROSOFT); 
	String^ adId = AdConfig::Main()->GetAdId(SOURCE_MICROSOFT, AD_TYPE_INSERT);
	OutputDebugString(appId->Data());
	OutputDebugString(L"\n");
	OutputDebugString(adId->Data());
	OutputDebugString(L"\n");
	interstitialAd->RequestAd(AdType::Display, appId, adId);

}



//adinsert
// This is an event handler for the interstitial ad. It is triggered when the interstitial ad information has been downloaded and is ready to show.
void AdInsertMicrosoft::OnAdReady(Object^ sender, Object^ e)
{
	isLoading = false;
	// The ad is ready to show; show it.
	interstitialAd->Show(); 
	//关闭app窗口标题栏
	CoreApplication::GetCurrentView()->TitleBar->ExtendViewIntoTitleBar = true;
	auto view = ApplicationView::GetForCurrentView();
	//if (view->TryEnterFullScreenMode())
	//{
	//	ApplicationView::PreferredLaunchWindowingMode = ApplicationViewWindowingMode::FullScreen;
	//	// The SizeChanged event will be raised when the entry to full-screen mode is complete.
	//}
 
}

// This is an event handler for the interstitial ad. It is triggered when the interstitial ad is cancelled.
void AdInsertMicrosoft::OnAdCancelled(Object^ sender, Object^ e)
{
	isLoading = false;
	//rootPage->NotifyUser("Ad cancelled", NotifyType::StatusMessage);
	AdInsertCallBack::Main()->AdDidClose();
	
}

// This is an event handler for the interstitial ad. It is triggered when the interstitial ad has completed playback.
void AdInsertMicrosoft::OnAdCompleted(Object^ sender, Object^ e)
{
	isLoading = false;
	AdInsertCallBack::Main()->AdDidFinish();
	//rootPage->NotifyUser("Ad completed", NotifyType::StatusMessage);
}

// This is an error handler for the interstitial ad.
void AdInsertMicrosoft::OnErrorOccurred(Object^ sender, AdErrorEventArgs^ e)
{
	isLoading = false;
	AdInsertCallBack::Main()->AdDidFail();
	//rootPage->NotifyUser("An error occurred. " + e->ErrorCode.ToString() + ": " + e->ErrorMessage, NotifyType::ErrorMessage);
}
 
