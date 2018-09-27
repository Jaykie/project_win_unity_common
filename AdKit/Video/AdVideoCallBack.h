#pragma once
#include "Common.h"
	 class AdVideoCallBack
	 {
	 public:
		 AdVideoCallBack();
		 ~AdVideoCallBack();
		 static AdVideoCallBack* Main(); 

		 void SetCallbackUnity(AdVideoCallbackUnity callback);
		 void AdDidFail();
		 void AdDidFinish();
		 void AdDidClose();

		 AdVideoCallbackUnity adVideoCallbackUnity;
		 String^ source;
	 };
