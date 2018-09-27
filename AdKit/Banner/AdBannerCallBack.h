#pragma once
  #include "Common.h"
	 class AdBannerCallBack
	 {
	 public:
		 AdBannerCallBack();
		 ~AdBannerCallBack();
		 static AdBannerCallBack* Main(); 

		 void SetCallbackUnity(AdBannerCallbackUnity callback);
		 void AdDidFail();
		 void AdDidFinish(int w,int h);

		 String^ source;
		 AdBannerCallbackUnity adBannerCallbackUnity;//c#»Øµ÷
	 };
