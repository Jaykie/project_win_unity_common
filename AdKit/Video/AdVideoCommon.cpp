#include "pch.h"
#include "AdVideoCommon.h"
#include "Common.h"
#include "../Platform/Microsoft/AdVideoMicrosoft.h"
#include "../Platform/Microsoft/AdVideoVungle.h"

/* @moon
Ҫ����Windows���reference��Ҫ�����̵�consume windows runtime extension ����Ϊyes
*/

void AdVideo_InitAd(char *source)
{
	AdVideoCommon::Main()->InitAd(source);
}
void AdVideo_PreLoad(char *source)
{
	AdVideoCommon::Main()->PreLoad(source);
}

void AdVideo_SetType(int type)
{
	AdVideoCommon::Main()->SetType(type);
}
void AdVideo_ShowAd()
{
	AdVideoCommon::Main()->ShowAd();
}

void AdVideo_SetObjectInfo(char *objName, char *objMethod)
{
	AdVideoCommon::Main()->SetObjectInfo(objName, objMethod);
}
void AdVideo_OnClickAd()
{
	AdVideoCommon::Main()->OnClickAd();
}
void AdVideo_SetCallbackUnity(AdVideoCallbackUnity callback)
{
	AdVideoCallBack::Main()->SetCallbackUnity(callback);
}

AdVideoCommon *s_AdVideoCommon = NULL;
AdVideoCommon *AdVideoCommon::Main()
{
	if (s_AdVideoCommon != NULL)
	{
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

void AdVideoCommon::CreateAdBase(String ^ source)
{
	AdVideoCallBack::Main()->source = source;
	if (source == SOURCE_MICROSOFT)
	{
		Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this] {
																										 adVideoBase = AdVideoMicrosoft::Main();
																									 }));
	}
	if (source == SOURCE_VUNGLE)
	{
		Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this] {
																										 adVideoBase = AdVideoVungle::Main();
																									 }));
	}
}

void AdVideoCommon::InitAd(char *source)
{
	std::string str(source);
	String ^ strnew = string2PlatformString(str);

	CreateAdBase(strnew);

	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this] {
																									 if (adVideoBase != nullptr)
																									 {
																										 adVideoBase->InitAd(L" ", L" ");
																									 }
																								 }));
}

void AdVideoCommon::PreLoad(char *source)
{
	InitAd(source);
	LoadAd();
}

void AdVideoCommon::SetType(int type)
{
}

void AdVideoCommon::LoadAd()
{

	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this] {
																									 if (adVideoBase != nullptr)
																									 {
																										 adVideoBase->LoadAd();
																									 }
																								 }));
}

void AdVideoCommon::ShowAd()
{

	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this] {
																									 if (adVideoBase != nullptr)
																									 {
																										 adVideoBase->ShowAd();
																									 }
																								 }));
}

void AdVideoCommon::SetObjectInfo(char *objName, char *objMethod)
{
	std::string str1(objName);
	std::string str2(objMethod);
	String ^ strnew1 = string2PlatformString(str1);
	String ^ strnew2 = string2PlatformString(str2);
	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this, strnew1, strnew2] {
																									 if (adVideoBase != nullptr)
																									 {
																										 adVideoBase->SetObjectInfo(strnew1, strnew2);
																									 }
																								 }));
}
void AdVideoCommon::OnClickAd()
{
	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this] {
																									 if (adVideoBase != nullptr)
																									 {
																										 //adVideoBase->OnClickAd();
																									 }
																								 }));
}
