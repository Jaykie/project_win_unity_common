#include "pch.h"
#include "AdBannerCommon.h"
#include <stdio.h>
#include "Common.h"
#include "AdKit/Platform/Microsoft/AdBannerMicrosoft.h"
#include "AdKit/Platform/Microsoft/AdBannerVungle.h"
//#include <msclr\marshal.h>
/* @moon
Ҫ����Windows���reference��Ҫ�����̵�consume windows runtime extension ����Ϊyes
*/

//using namespace Common;

using namespace Platform;
using namespace Windows::UI::Core;
//using namespace msclr::interop;

/* @moon
Ҫ����Windows���reference��Ҫ�����̵�consume windows runtime extension ����Ϊyes
*/
void AdBanner_InitAd(char *source)
{
	AdBannerCommon::Main()->InitAd(source);
}
void AdBanner_ShowAd(bool isShow)
{
	AdBannerCommon::Main()->ShowAd(isShow);
}
void AdBanner_SetScreenSize(int w, int h)
{
	AdBannerCommon::Main()->SetScreenSize(w, h);
}
void AdBanner_SetScreenOffset(int x, int y)
{
	AdBannerCommon::Main()->SetScreenOffset(x, y);
}
void AdBanner_SetUIParent(Panel ^ parent)
{
	AdBannerCommon::Main()->SetUIParent(parent);
}
void AdBanner_SetCallbackUnity(AdBannerCallbackUnity callback)
{
	AdBannerCallBack::Main()->SetCallbackUnity(callback);
}

AdBannerCommon *s_AdBannerCommon = NULL;
AdBannerCommon::AdBannerCommon()
{
}

AdBannerCommon::~AdBannerCommon()
{
}

AdBannerCommon *AdBannerCommon::Main()
{
	if (s_AdBannerCommon != NULL)
	{
		return s_AdBannerCommon;
	}
	s_AdBannerCommon = new AdBannerCommon();
	return s_AdBannerCommon;
}

void AdBannerCommon::CreateAdBase(String ^ source)
{
	AdBannerCallBack::Main()->source = source;

	if (source == SOURCE_MICROSOFT)
	{
		Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this, source] {
																										 adBannerBase = AdBannerMicrosoft::Main();
																										 adBannerBase->source = source;
																										 adBannerBase->SetUIParent(uiParent);
																									 }));
	}

	if (source == SOURCE_VUNGLE)
	{
		Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this, source] {
																										 adBannerBase = AdBannerVungle::Main();
																										 adBannerBase->source = source;
																										 adBannerBase->SetUIParent(uiParent);
																									 }));
	}
 
}

void AdBannerCommon::SetUIParent(Panel ^ parent)
{
	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this, parent] {
																									 uiParent = parent;
																									 uiParent->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
																								 }));
}
void AdBannerCommon::InitAd(char *source)
{
	std::string str(source);
	String ^ strnew = string2PlatformString(str);
	CreateAdBase(strnew);
	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this] {
																									 adBannerBase->InitAd(L"", L"");
																								 }));
}

void AdBannerCommon::ShowAd(bool isShow)
{

	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this, isShow] {
																									 adBannerBase->ShowAd(isShow);
																								 }));
}
void AdBannerCommon::SetScreenSize(int w, int h)
{

	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this, w, h] {
																									 if (adBannerBase != nullptr)
																									 {
																										 adBannerBase->SetScreenSize(w, h);
																									 }
																								 }));
}
void AdBannerCommon::SetScreenOffset(int x, int y)
{

	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this, x, y] {
																									 if (adBannerBase != nullptr)
																									 {
																										 adBannerBase->SetScreenOffset(x, y);
																									 }
																								 }));
}
