#pragma once
  
	 class AdInsertCallBack
	 {
	 public:
		 AdInsertCallBack();
		 ~AdInsertCallBack();
		 static AdInsertCallBack* Main();

		
		 void AdDidFail();
		 void AdDidFinish();
		 void AdDidClose();
	 };
