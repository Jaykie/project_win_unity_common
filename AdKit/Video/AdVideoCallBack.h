#pragma once
  
	 class AdVideoCallBack
	 {
	 public:
		 AdVideoCallBack();
		 ~AdVideoCallBack();
		 static AdVideoCallBack* Main(); 

		
		 void AdDidFail();
		 void AdDidFinish();
		 void AdDidClose();
	 };
