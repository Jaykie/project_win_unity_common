#pragma once  

using namespace Platform;
using namespace Windows::UI::Core;
 
namespace Common
{
public ref class AdSDKInitVungle sealed //sealed 
{
internal:
	AdSDKInitVungle();
	//~AdSDKInitVungle();
	static AdSDKInitVungle^ Main();
	void Init(char* appId, char* appKey, char* adKey);

	void InitSDK(String ^ appId, String ^ appKey);
	bool isPlacementEmpty(std::string placement);
 
	 

private:
 
};
}


