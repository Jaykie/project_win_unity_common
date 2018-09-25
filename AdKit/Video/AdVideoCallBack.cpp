#include "pch.h"
#include "AdVideoCallBack.h"


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

void AdVideoCallBack::AdDidFinish()
{
}

void AdVideoCallBack::AdDidFail()
{

} 
void AdVideoCallBack::AdDidClose()
{

}