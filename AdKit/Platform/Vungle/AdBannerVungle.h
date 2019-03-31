#pragma once
#include "AdKit/Banner/AdBannerBase.xaml.h"
using namespace Common;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::UI::Core;
using namespace Windows::UI::ViewManagement;
using namespace Windows::Graphics::Display;
using namespace Windows::UI::Xaml::Controls; 

namespace Common
{
	public ref class AdBannerVungle sealed :
		public ::AdBannerBase
	{
	internal:
		AdBannerVungle();

		static AdBannerVungle^ Main();

		virtual void InitAd(String^ appId, String^ appKey) override;
		virtual void ShowAd(bool isShow) override;
		virtual	void OnWindowResize() override;

		//void OnErrorOccurred(Platform::Object^ sender, Microsoft::Advertising::WinRT::UI::AdErrorEventArgs^ e);
		void OnAdRefreshed(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

	private:
		AdControl^ adControl;
		

	};
}

