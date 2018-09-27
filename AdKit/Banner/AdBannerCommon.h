#pragma once 
#include "AdKit/Banner/AdBannerBase.xaml.h"
#include "AdBannerCallBack.h"
#include "AdKit/AdConfig/AdConfig.h"

using namespace Microsoft::Advertising::WinRT::UI;
using namespace Common;
using namespace Windows::UI::Xaml::Controls;

class AdBannerCommon
{
public:
	AdBannerCommon();
	~AdBannerCommon();
	static AdBannerCommon* Main();
	void CreateAdBase(String^ source);
	void InitAd(char* source);
	void SetUIParent(Panel^ parent);
	void ShowAd(bool isShow);
	void SetScreenSize(int w, int h);
	void SetScreenOffset(int x, int y); 
private:
	Panel^ uiParent;
	AdBannerBase^ adBannerBase;
};
 

