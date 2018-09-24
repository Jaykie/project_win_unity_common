#pragma once
#include "AdKit/Video/AdVideoBase.xaml.h"

using namespace Common;
using namespace Platform;
using namespace Windows::UI::Core;
using namespace Microsoft::Advertising::WinRT::UI;
namespace Common
{
	public ref class AdVideoMicrosoft sealed ://sealed
		public AdVideoBase
	{
	internal:
		AdVideoMicrosoft();
		//~AdVideoMicrosoft();
		static	AdVideoMicrosoft^ Main();

		 virtual void  InitAd(String^ appId, String^ appKey) override;
		 virtual void ShowAd() override;
		 virtual void SetObjectInfo(String^ objName, String^ objMethod) override;

	private:
		InterstitialAd^ interstitialAd;
		bool isLoading;

		void OnAdReady(Platform::Object^ sender, Platform::Object^ args);
		void OnAdCancelled(Platform::Object^ sender, Platform::Object^ args);
		void OnAdCompleted(Platform::Object^ sender, Platform::Object^ args);
		void OnErrorOccurred(Platform::Object^ sender, Microsoft::Advertising::WinRT::UI::AdErrorEventArgs^ args);

	};
}
