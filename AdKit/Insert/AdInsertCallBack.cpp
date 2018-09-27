#include "pch.h"
#include "AdInsertCallBack.h"


AdInsertCallBack *s_AdInsertCallBack = NULL;
AdInsertCallBack::AdInsertCallBack()
{
}


AdInsertCallBack::~AdInsertCallBack()
{
}


AdInsertCallBack* AdInsertCallBack::Main()
{
	if (s_AdInsertCallBack != NULL) {
		return s_AdInsertCallBack;
	}
	s_AdInsertCallBack = new AdInsertCallBack();
	return s_AdInsertCallBack;
}

void AdInsertCallBack::SetCallbackUnity(AdInsertCallbackUnity callback)
{
	adInsertCallbackUnity = callback;
}

void AdInsertCallBack::AdDidFinish()
{
	if (adInsertCallbackUnity != nullptr) {
		std::string str = PlatformString2string(source);
		adInsertCallbackUnity((char *)str.c_str(), "AdDidFinish");
	}
}

void AdInsertCallBack::AdDidFail()
{
	if (adInsertCallbackUnity != nullptr) {
		std::string str = PlatformString2string(source);
		adInsertCallbackUnity((char *)str.c_str(), "AdDidFail");
	}
} 
void AdInsertCallBack::AdDidClose()
{
	if (adInsertCallbackUnity != nullptr) {
		std::string str = PlatformString2string(source);
		adInsertCallbackUnity((char *)str.c_str(), "AdDidClose");
	}
}