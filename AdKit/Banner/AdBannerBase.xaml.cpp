//
// AdBannerBase.xaml.cpp
// Implementation of the AdBannerBase class
//

#include "pch.h"
#include "AdBannerBase.xaml.h"

using namespace Common;

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

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

AdBannerBase::AdBannerBase()
{
	//InitializeComponent();
	SetScreenOffset(0, 0);
}



void AdBannerBase::InitAd(String^ appId, String^ appKey)
{
	 
}

void AdBannerBase::ShowAd(bool isShow)
{

	if (isShow) {
		uiParent->Visibility = Windows::UI::Xaml::Visibility::Visible;
	}
	else {
		uiParent->Visibility = Windows::UI::Xaml::Visibility::Collapsed;

	}
}
void AdBannerBase::SetScreenSize(int w, int h)
{

}
void AdBannerBase::SetScreenOffset(int x, int y)
{
	screenOftX = x;
	screenOftY = y;
}
void AdBannerBase::SetUIParent(Panel^ parent)
{
	uiParent = parent;
  
}

//获取屏幕分辨率
Size AdBannerBase::GetScreenSize()
{
	Rect bounds = ApplicationView::GetForCurrentView()->VisibleBounds;
	double scaleFactor = DisplayInformation::GetForCurrentView()->RawPixelsPerViewPixel;
	Size size = Size(bounds.Width*scaleFactor, bounds.Height*scaleFactor);
	return size;
}

int AdBannerBase::GetScreenPixsel(float value)
{
	 
	double scaleFactor = DisplayInformation::GetForCurrentView()->RawPixelsPerViewPixel;
	int ret = value*scaleFactor;
	return ret;
}
 
