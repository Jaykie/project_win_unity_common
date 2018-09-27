#include "pch.h"
#include "AdVideoCallBack.h"
using namespace Platform;
using namespace Windows::UI::Core;

AdVideoCallBack *s_AdVideoCallBack = NULL;
AdVideoCallBack::AdVideoCallBack()
{
}


AdVideoCallBack::~AdVideoCallBack()
{
}


AdVideoCallBack* AdVideoCallBack::Main()
{
	if (s_AdVideoCallBack != NULL) {
		return s_AdVideoCallBack;
	}
	s_AdVideoCallBack = new AdVideoCallBack();
	return s_AdVideoCallBack;
}

void AdVideoCallBack::SetCallbackUnity(AdVideoCallbackUnity callback)
{
	adVideoCallbackUnity = callback;
}

void AdVideoCallBack::AdDidFinish()
{
		if (adVideoCallbackUnity != nullptr) {
			std::string str = PlatformString2string(source);
			adVideoCallbackUnity((char *)str.c_str(), "AdDidFinish"); 
		}
		 
}

void AdVideoCallBack::AdDidFail()
{
	if (adVideoCallbackUnity != nullptr) {
		std::string str = PlatformString2string(source);
		adVideoCallbackUnity((char *)str.c_str(), "AdDidFail");
	}
} 
void AdVideoCallBack::AdDidClose()
{
	if (adVideoCallbackUnity != nullptr) {
		std::string str = PlatformString2string(source);
		adVideoCallbackUnity((char *)str.c_str(), "AdDidClose");
	}
}