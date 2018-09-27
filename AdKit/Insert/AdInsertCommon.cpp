#include "pch.h"
#include "AdInsertCommon.h"

#include "Common.h"
#include "AdKit/Platform/Microsoft/AdInsertMicrosoft.h"
//#include <msclr\marshal_cppstd.h>  
/* @moon
要引用Windows相关reference需要将工程的consume windows runtime extension 设置为yes
*/
//using namespace Concurrency;
using namespace Platform; 
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
//using namespace Windows::Storage;
using namespace Windows::System::Threading;
using namespace Windows::UI;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
//using namespace Windows::UI::Xaml::Media;
//using namespace Windows::UI::Xaml::Navigation;
using namespace Microsoft::Advertising::WinRT::UI; 
//using namespace System;
//using namespace msclr::interop;

//using namespace Common;
	 void AdInsert_InitAd(char* source)
	{
		 AdInsertCommon::Main()->InitAd(source);
	}
	 void AdInsert_ShowAd()
	{
		 AdInsertCommon::Main()->ShowAd();
	}
	 void AdInsert_SetObjectInfo(char* objName)
	{
		 AdInsertCommon::Main()->SetObjectInfo(objName);
	} 

	 void AdInsert_SetCallbackUnity(AdInsertCallbackUnity callback)
	 {
		 AdInsertCallBack::Main()->SetCallbackUnity(callback);
	 }

AdInsertCommon *s_AdInsertCommon = NULL;


AdInsertCommon::AdInsertCommon()
{

	 
}


AdInsertCommon::~AdInsertCommon()
{
}

 AdInsertCommon* AdInsertCommon::Main()
{
	 if (s_AdInsertCommon != NULL) {
		 return s_AdInsertCommon;
	 }
	 s_AdInsertCommon = new AdInsertCommon();
	 return s_AdInsertCommon;
}

 void AdInsertCommon::CreateAdBase(String^ source)
 {
	 AdInsertCallBack::Main()->source = source;
	 if (source == SOURCE_MICROSOFT)
	 {


		 Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this]
		 {

			 adInsertBase = AdInsertMicrosoft::Main();

		 }));
	 }
 }

 void AdInsertCommon::InitAd(char* source)
 { 
	std::string str(source);
	String^ strnew = string2PlatformString(str);
	CreateAdBase(strnew);
	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this, strnew]
	{
		adInsertBase->InitAd(strnew,L" ");

	}));
 }

 void AdInsertCommon::ShowAd()
 {
	 Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this]
	 {
		 adInsertBase->ShowAd();

	 }));
 }
  
 void AdInsertCommon::SetObjectInfo(char* objName)
 {
	 std::string str(objName);
	 String^ strnew = string2PlatformString(str);
	 SetObjectInfoInMainThread(strnew);
 }
  
	void AdInsertCommon::SetObjectInfoInMainThread(String^ objName)
	{
		Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this, objName]
		{
			//develop: CurrentAppSimulator
			//release: CurrentApp 
			if (adInsertBase != nullptr) {
				adInsertBase->SetObjectInfo(objName, L" ");
			}
			

		}));
	}


    
