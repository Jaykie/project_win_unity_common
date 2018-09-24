#include "pch.h"
#include "AdVideoCommon.h"
#include "Common.h"
#include "../Platform/Microsoft/AdVideoMicrosoft.h"
/* @moon
要引用Windows相关reference需要将工程的consume windows runtime extension 设置为yes
*/

	 void AdVideo_InitAd(char* source)
	{
		 AdVideoCommon::Main()->InitAd(source);
	}
	 void AdVideo_SetType(int type)
	{
		 AdVideoCommon::Main()->SetType(type);
	}
	 void AdVideo_ShowAd()
	{
		 AdVideoCommon::Main()->ShowAd();
	}
	
	 void AdVideo_SetObjectInfo(char* objName,char*objMethod)
	{
		 AdVideoCommon::Main()->SetObjectInfo(objName, objMethod);
	}
	 void AdVideo_OnClickAd()
	 {
		 AdVideoCommon::Main()->OnClickAd();
	 }
	
		 AdVideoCommon* s_AdVideoCommon = NULL;
	 AdVideoCommon* AdVideoCommon::Main()
	 {
		 if (s_AdVideoCommon != NULL) {
			 return s_AdVideoCommon;
		 }
		 s_AdVideoCommon = new AdVideoCommon();
		 return s_AdVideoCommon;
	 }

AdVideoCommon::AdVideoCommon()
{
	
}


AdVideoCommon::~AdVideoCommon()
{
}

void AdVideoCommon::CreateAdBase(String^ source)
{

	if (source == SOURCE_MICROSOFT) 
	{
	

		Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this]
		{
			 
			adVideoBase = AdVideoMicrosoft::Main();
			
		}));
	}
}

void AdVideoCommon::InitAd(char* source)
{
	std::string str(source);
	String^ strnew = string2PlatformString(str);

		CreateAdBase(strnew); 

	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this]
	{
		if (adVideoBase != nullptr)
		{
			adVideoBase->InitAd(L" ", L" ");
		}

	}));
}
void AdVideoCommon::SetType(int type)
{

}
void AdVideoCommon::ShowAd()
{
	
	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this]
	{
		if (adVideoBase != nullptr)
		{
			adVideoBase->ShowAd();
		}
	}));
}

void AdVideoCommon::SetObjectInfo(char* objName, char*objMethod)
{
	std::string str1(objName);
	std::string str2(objMethod); 
	String^ strnew1 = string2PlatformString(str1);
	String^ strnew2 = string2PlatformString(str2);
	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this, strnew1, strnew2]
	{
		if (adVideoBase != nullptr)
		{
			adVideoBase->SetObjectInfo(strnew1, strnew2);
		}
	}));
}
void AdVideoCommon::OnClickAd()
{
	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this]
	{
		if (adVideoBase != nullptr)
		{
			//adVideoBase->OnClickAd();
		}
	}));
}
