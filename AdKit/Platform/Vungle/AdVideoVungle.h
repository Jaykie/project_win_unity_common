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
 
	private:
	//	InterstitialAd^ interstitialAd;
		bool isLoading;
 
	};
}
