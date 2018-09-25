#pragma once
  
	 class AdBannerCallBack
	 {
	 public:
		 AdBannerCallBack();
		 ~AdBannerCallBack();
		 static AdBannerCallBack* Main(); 

		
		 void AdDidFail();
		 void AdDidFinish(int w,int h);

	 };
