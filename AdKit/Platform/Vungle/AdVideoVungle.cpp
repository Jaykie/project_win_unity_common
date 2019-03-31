#include "pch.h"
#include "AdVideoVungle.h"
#include "Common.h"
#include "AdKit/Video/AdVideoCommon.h"
using namespace Common;
using namespace Windows::Foundation;
using namespace Windows::ApplicationModel::Core;

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
	source = SOURCE_Vungle;
	interstitialAd = ref new InterstitialAd();
	// Attach event handlers
	interstitialAd->ErrorOccurred += ref new EventHandler<AdErrorEventArgs ^>(this, &AdVideoVungle::OnErrorOccurred);
	interstitialAd->AdReady += ref new EventHandler<Object ^>(this, &AdVideoVungle::OnAdReady);
	interstitialAd->Cancelled += ref new EventHandler<Object ^>(this, &AdVideoVungle::OnAdCancelled);
	interstitialAd->Completed += ref new EventHandler<Object ^>(this, &AdVideoVungle::OnAdCompleted);
	isLoading = false;
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
	String ^ appId = AdConfig::Main()->GetAppId(SOURCE_VUNGLE);
	String ^ adId = AdConfig::Main()->GetAdId(SOURCE_VUNGLE, AD_TYPE_VIDEO);
	OutputDebugString(appId->Data());
	OutputDebugString(L"\n");
	OutputDebugString(adId->Data());
	OutputDebugString(L"\n");
	interstitialAd->RequestAd(AdType::Video, appId, adId);
}

//adinsert
// This is an event handler for the interstitial ad. It is triggered when the interstitial ad information has been downloaded and is ready to show.
void AdVideoVungle::OnAdReady(Object ^ sender, Object ^ e)
{
	isLoading = false;
	// The ad is ready to show; show it.
	interstitialAd->Show();
	//�ر�app���ڱ�����
	CoreApplication::GetCurrentView()->TitleBar->ExtendViewIntoTitleBar = true;
}

// This is an event handler for the interstitial ad. It is triggered when the interstitial ad is cancelled.
void AdVideoVungle::OnAdCancelled(Object ^ sender, Object ^ e)
{
	isLoading = false;

	AdVideoCallBack::Main()->AdDidClose();
	//rootPage->NotifyUser("Ad cancelled", NotifyType::StatusMessage);
}

// This is an event handler for the interstitial ad. It is triggered when the interstitial ad has completed playback.
void AdVideoVungle::OnAdCompleted(Object ^ sender, Object ^ e)
{
	isLoading = false;
	AdVideoCallBack::Main()->AdDidFinish();
	//rootPage->NotifyUser("Ad completed", NotifyType::StatusMessage);
}

// This is an error handler for the interstitial ad.
void AdVideoVungle::OnErrorOccurred(Object ^ sender, AdErrorEventArgs ^ e)
{
	isLoading = false;
	AdVideoCallBack::Main()->AdDidFail();
	//rootPage->NotifyUser("An error occurred. " + e->ErrorCode.ToString() + ": " + e->ErrorMessage, NotifyType::ErrorMessage);
}
