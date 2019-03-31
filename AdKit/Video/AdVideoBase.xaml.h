//
// AdVideoBase.xaml.h
// Declaration of the AdVideoBase class
//

#pragma once

#include "AdKit\Video\AdVideoBase.g.h"
using namespace Platform;
using namespace Windows::UI::Core;

namespace Common
{
/// <summary>
/// An empty page that can be used on its own or navigated to within a Frame.
/// </summary>
[Windows::Foundation::Metadata::WebHostHidden] public ref class AdVideoBase //sealed
{
	internal : AdVideoBase();

	virtual void InitAd(String ^ appId, String ^ appKey);
	virtual void ShowAd();
	virtual void SetObjectInfo(String ^ objName, String ^ objMethod);
	virtual void LoadAd();
	internal : String ^ source;
	String ^ strAppId;
	String ^ strAppKey;
};
} // namespace Common
