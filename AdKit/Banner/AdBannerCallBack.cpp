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

void AdBannerCallBack::AdDidFinish(int w, int h)
{
}

void AdBannerCallBack::AdDidFail()
{

} 