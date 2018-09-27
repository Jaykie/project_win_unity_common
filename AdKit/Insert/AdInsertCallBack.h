#pragma once
#include "Common.h"
	 class AdInsertCallBack
	 {
	 public:
		 AdInsertCallBack();
		 ~AdInsertCallBack();
		 static AdInsertCallBack* Main();

		 void SetCallbackUnity(AdInsertCallbackUnity callback);

		 void AdDidFail();
		 void AdDidFinish();
		 void AdDidClose();

		 String^ source;
		 AdInsertCallbackUnity adInsertCallbackUnity;//c#»Øµ÷
	 };
