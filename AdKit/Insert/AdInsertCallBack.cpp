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

void AdInsertCallBack::AdDidFinish()
{
}

void AdInsertCallBack::AdDidFail()
{

} 
void AdInsertCallBack::AdDidClose()
{

}