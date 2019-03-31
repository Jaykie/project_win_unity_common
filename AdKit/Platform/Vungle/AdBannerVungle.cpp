#include "pch.h"
#include "AdBannerVungle.h"
#include "AdKit/Banner/AdBannerCommon.h"
#include "Common.h"
using namespace Common;
using namespace Windows::Foundation;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::ViewManagement;
using namespace Windows::UI::Xaml::Interop;

using namespace Windows::UI::ViewManagement;
using namespace Windows::Graphics::Display;

AdBannerVungle::AdBannerVungle()
{
	adControl = ref new AdControl();
}

AdBannerVungle^ s_AdBannerVungle = nullptr;
AdBannerVungle^ AdBannerVungle::Main()
{
	if (s_AdBannerVungle != nullptr) {
		return s_AdBannerVungle;
	}
	s_AdBannerVungle = ref new AdBannerVungle();
	return s_AdBannerVungle;
}

 
void AdBannerVungle::InitAd(String^ appId, String^ appKey)
{

	// // Programatically create an ad control. This must be done from the UI thread.



	// // Set the application id and ad unit id
	// // The application id and ad unit id can be obtained from Dev Center.
	// // See "Monetize with Ads" at https ://msdn.Vungle.com/en-us/library/windows/apps/mt170658.aspx
	// adControl->ApplicationId = AdConfig::Main()->GetAppId(SOURCE_VUNGLE);//L"d25517cb-12d4-4699-8bdc-52040c712cab";
	// adControl->AdUnitId = AdConfig::Main()->GetAdId(SOURCE_Vungle, AD_TYPE_BANNER);// L"10043134";
	// OutputDebugString(adControl->ApplicationId->Data());
	// OutputDebugString(L"\n");
	// OutputDebugString(adControl->AdUnitId->Data());
	// OutputDebugString(L"\n");
	// OnWindowResize();

	// // Add event handlers if you want
	// adControl->ErrorOccurred += ref new EventHandler<AdErrorEventArgs^>(this, &AdBannerVungle::OnErrorOccurred);
	// adControl->AdRefreshed += ref new EventHandler<RoutedEventArgs^>(this, &AdBannerVungle::OnAdRefreshed);

	// // Add the ad control to the page
	// if (adControl->Parent == nullptr) {
	// 	uiParent->Children->Append(adControl);
	// }
	


	//auto parent = safe_cast<Panel^>(button->Parent);

	//auto rootFrame = dynamic_cast<Frame^>(Window::Current->Content);
	//auto rootFrame = safe_cast<Frame^>(Window::Current->Content);
	//Frame^ rootFrame = Window::Current->Content;
	//auto parent = Window::Current->Content;
	//parent->Add
}

void AdBannerVungle::ShowAd(bool isShow)
{

	if (isShow) {
		uiParent->Visibility = Windows::UI::Xaml::Visibility::Visible;
	}
	else {
		uiParent->Visibility = Windows::UI::Xaml::Visibility::Collapsed;

	}
}
 
void AdBannerVungle::OnWindowResize() 
{
	if ((adControl == nullptr)|| (uiParent == nullptr)) {
		return;
	}
	Rect bounds = ApplicationView::GetForCurrentView()->VisibleBounds;
	adHeight = (128.0 / 1536)*bounds.Height;
	adWidth = bounds.Width;
	// Set the dimensions
	adControl->Width = adWidth;
	//2048x1536
	adControl->Height = adHeight;
	//�߾����
	auto margin = uiParent->Margin;
	margin.Top = bounds.Height - adHeight;
	uiParent->Margin = margin;
}

// This is an error handler for the ad control.
void AdBannerVungle::OnErrorOccurred(Object^ sender, AdErrorEventArgs^ e)
{
	AdBannerCallBack::Main()->AdDidFail();
	//rootPage->NotifyUser("An error occurred. " + e->ErrorCode.ToString() + ": " + e->ErrorMessage, NotifyType::ErrorMessage);
}

// This is an event handler for the ad control. It's invoked when the ad is refreshed.
void AdBannerVungle::OnAdRefreshed(Object^ sender, RoutedEventArgs^ e)
{
	// We increment the ad count so that the message changes at every refresh.
	//adCount++;
	//rootPage->NotifyUser("Advertisement #" + adCount.ToString(), NotifyType::StatusMessage);
 
	AdBannerCallBack::Main()->AdDidFinish(GetScreenPixsel(adWidth), GetScreenPixsel(adHeight));
}

 