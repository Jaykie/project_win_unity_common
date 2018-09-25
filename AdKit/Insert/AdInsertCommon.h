#pragma once

#include "AdKit/Insert/AdInsertBase.xaml.h"
#include "AdInsertCallBack.h"
#include "AdKit/AdConfig/AdConfig.h"
using namespace Common;


	class AdInsertCommon //: public ::Platform::Object
{
public:
	AdInsertCommon();
	~AdInsertCommon();

	static AdInsertCommon* Main();
	void CreateAdBase(String^ source);
	void InitAd(char* source);
	void ShowAd();
	void SetObjectInfo(char* objName);
 
		void SetObjectInfoInMainThread(String^ objName);

private:

	AdInsertBase^ adInsertBase;
	
};

