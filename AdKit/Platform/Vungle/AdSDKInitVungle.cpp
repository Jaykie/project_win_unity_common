#include "pch.h"
#include "AdSDKInitVungle.h"
#include "Common.h" 
#include "AdKit/AdConfig/AdConfig.h"
 
using namespace Common;
using namespace Windows::Foundation;
using namespace Windows::ApplicationModel::Core;

AdSDKInitVungle^ s_AdSDKInitVungle = nullptr;
AdSDKInitVungle^ AdSDKInitVungle::Main()
 {
	 if (s_AdSDKInitVungle != nullptr) {
		 return s_AdSDKInitVungle;
	 }
	 s_AdSDKInitVungle = ref new AdSDKInitVungle();
	 return s_AdSDKInitVungle;
 }


 AdSDKInitVungle::AdSDKInitVungle()
 {
 }
  

 void AdSDKInitVungle::Init(char* appId, char* appKey, char* adKey)
 {
	 
 } 
  
