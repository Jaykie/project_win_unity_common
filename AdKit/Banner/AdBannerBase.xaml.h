//
// AdBannerBase.xaml.h
// Declaration of the AdBannerBase class
//

#pragma once

#include "AdKit\Banner\AdBannerBase.g.h"
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Core;
using namespace Windows::UI::ViewManagement;
using namespace Windows::Graphics::Display;
using namespace Windows::UI::Xaml::Controls;

namespace Common
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class AdBannerBase //sealed
	{
	internal:
		AdBannerBase();
 
	virtual void  InitAd(String^ appId, String^ appKey);
	virtual	void ShowAd(bool isShow);
	virtual	void OnWindowResize();

		void SetScreenSize(int w, int h);
		void SetScreenOffset(int x, int y);
		void SetUIParent(Panel^ parent);
		Size GetScreenSize();
		int GetScreenPixsel(float value);

		Panel^ uiParent;
		int screenOftX;//屏幕分辨率
		int screenOftY;//屏幕分辨率
		float adWidth;//bounds
		float adHeight;//bounds

		//windows size change
		Windows::Foundation::EventRegistrationToken m_OnResizeRegistrationToken; 
		 
	};
}
