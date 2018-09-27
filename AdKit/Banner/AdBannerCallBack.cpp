#include "pch.h"
#include "AdBannerCallBack.h"


AdBannerCallBack *s_AdBannerCallBack = NULL;
AdBannerCallBack::AdBannerCallBack()
{
}


AdBannerCallBack::~AdBannerCallBack()
{
}


AdBannerCallBack* AdBannerCallBack::Main()
{
	if (s_AdBannerCallBack != NULL) {
		return s_AdBannerCallBack;
	}
	s_AdBannerCallBack = new AdBannerCallBack();
	return s_AdBannerCallBack;
}

void AdBannerCallBack::SetCallbackUnity(AdBannerCallbackUnity callback)
{
	adBannerCallbackUnity = callback;
}
void AdBannerCallBack::AdDidFinish(int w, int h)
{
	
	if (adBannerCallbackUnity != nullptr) {
		std::string str = PlatformString2string(source);
		adBannerCallbackUnity((char *)str.c_str(), "AdDidFinish", w, h);
	}
	
}

void AdBannerCallBack::AdDidFail()
{ 
	if (adBannerCallbackUnity != nullptr) {
		std::string str = PlatformString2string(source);
		adBannerCallbackUnity((char *)str.c_str(), "AdDidFail", 0, 0);
	}
} 