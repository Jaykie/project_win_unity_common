#pragma once
#include "AdKit/Video/AdVideoBase.xaml.h"

using namespace Common;
using namespace Platform;
using namespace Windows::UI::Core;
namespace Common
{
	public ref class AdVideoVungle sealed ://sealed
		public AdVideoBase
	{
	internal:
		AdVideoVungle();
		//~AdVideoVungle();
		static	AdVideoVungle^ Main();

		 virtual void  InitAd(String^ appId, String^ appKey) override;
		 virtual void ShowAd() override;
		 virtual void LoadAd() override;
		 virtual void SetObjectInfo(String^ objName, String^ objMethod) override; 

	

		 VungleSDK::VungleAd^ sdkInstance;

	private:
	//	InterstitialAd^ interstitialAd;
		bool isLoading;

		void OnInitCompleted(Platform::Object ^ sender, VungleSDK::ConfigEventArgs ^ args);
		void OnOnAdPlayableChanged(Platform::Object ^sender, VungleSDK::AdPlayableEventArgs ^args);
		void OnAdStart(Platform::Object^ sender, VungleSDK::AdEventArgs^ e);
		void OnVideoView(Platform::Object^ sender, VungleSDK::AdViewEventArgs^ e);
		void OnAdEnd(Platform::Object^ sender, VungleSDK::AdEndEventArgs^ e);
		void Diagnostic(Platform::Object^ sender, VungleSDK::DiagnosticLogEvent^ e);

	};
}
