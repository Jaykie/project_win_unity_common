#pragma once 
#include "AdKit/Insert/AdInsertBase.xaml.h"
using namespace Platform;
using namespace Windows::UI::Core; 
namespace Common
{
	public ref class AdInsertVungle sealed ://
		public AdInsertBase
	{
	internal:
		AdInsertVungle();
 
		static	AdInsertVungle^ Main();

		virtual void  InitAd(String^ appId, String^ appKey) override;
		virtual void ShowAd() override;
		virtual void SetObjectInfo(String^ objName, String^ objMethod) override;

	private: 
		bool isLoading;

	 
	};
}

