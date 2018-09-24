//
// AdInsertBase.xaml.h
// Declaration of the AdInsertBase class
//

#pragma once

#include "AdKit\Insert\AdInsertBase.g.h"
using namespace Platform;
namespace Common
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class AdInsertBase 
	{
	internal:
		AdInsertBase();

		virtual void  InitAd(String^ appId, String^ appKey);
		virtual void ShowAd();
		virtual void SetObjectInfo(String^ objName, String^ objMethod);

	internal:
		String ^source;
		String ^strAppId;
		String ^strAppKey;
	};
}
