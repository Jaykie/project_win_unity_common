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
	source = SOURCE_Vungle;
	interstitialAd = ref new InterstitialAd();
	// Attach event handlers
	interstitialAd->ErrorOccurred += ref new EventHandler<AdErrorEventArgs^>(this, &AdInsertVungle::OnErrorOccurred);
	interstitialAd->AdReady += ref new EventHandler<Object^>(this, &AdInsertVungle::OnAdReady);
	interstitialAd->Cancelled += ref new EventHandler<Object^>(this, &AdInsertVungle::OnAdCancelled);
	interstitialAd->Completed += ref new EventHandler<Object^>(this, &AdInsertVungle::OnAdCompleted);
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
	interstitialAd->RequestAd(AdType::Display, appId, adId);
	//interstitialAd->RequestAd(AdType::Display, L"d25517cb-12d4-4699-8bdc-52040c712cab", L"11389925");
	//interstitialAd->RequestAd(AdType::Display, L"9ngqjvv1jh1x", L"1100032471");
	//interstitialAd->RequestAd(AdType::Display, L"9n1lt0gg40ht", L"1100032935");
	  
}



//adinsert
// This is an event handler for the interstitial ad. It is triggered when the interstitial ad information has been downloaded and is ready to show.
void AdInsertVungle::OnAdReady(Object^ sender, Object^ e)
{
	isLoading = false;
	// The ad is ready to show; show it.
	interstitialAd->Show(); 
	//�ر�app���ڱ�����
	CoreApplication::GetCurrentView()->TitleBar->ExtendViewIntoTitleBar = true;
	auto view = ApplicationView::GetForCurrentView();
	//if (view->TryEnterFullScreenMode())
	//{
	//	ApplicationView::PreferredLaunchWindowingMode = ApplicationViewWindowingMode::FullScreen;
	//	// The SizeChanged event will be raised when the entry to full-screen mode is complete.
	//}
 
}

// This is an event handler for the interstitial ad. It is triggered when the interstitial ad is cancelled.
void AdInsertVungle::OnAdCancelled(Object^ sender, Object^ e)
{
	isLoading = false;
	//rootPage->NotifyUser("Ad cancelled", NotifyType::StatusMessage);
	AdInsertCallBack::Main()->AdDidClose();
	
}

// This is an event handler for the interstitial ad. It is triggered when the interstitial ad has completed playback.
void AdInsertVungle::OnAdCompleted(Object^ sender, Object^ e)
{
	isLoading = false;
	AdInsertCallBack::Main()->AdDidFinish();
	//rootPage->NotifyUser("Ad completed", NotifyType::StatusMessage);
}

// This is an error handler for the interstitial ad.
void AdInsertVungle::OnErrorOccurred(Object^ sender, AdErrorEventArgs^ e)
{
	isLoading = false;
	AdInsertCallBack::Main()->AdDidFail();
	//rootPage->NotifyUser("An error occurred. " + e->ErrorCode.ToString() + ": " + e->ErrorMessage, NotifyType::ErrorMessage);
}
 
