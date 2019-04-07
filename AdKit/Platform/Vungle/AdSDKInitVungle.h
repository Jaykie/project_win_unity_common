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

	VungleSDK::VungleAd^ GetSDKInstance();

	VungleSDK::VungleAd^ sdkInstance;

private:


	void OnInitCompleted(Platform::Object ^ sender, VungleSDK::ConfigEventArgs ^ args);
	void OnOnAdPlayableChanged(Platform::Object ^sender, VungleSDK::AdPlayableEventArgs ^args);
	void OnAdStart(Platform::Object^ sender, VungleSDK::AdEventArgs^ e);
	void OnVideoView(Platform::Object^ sender, VungleSDK::AdViewEventArgs^ e);
	void OnAdEnd(Platform::Object^ sender, VungleSDK::AdEndEventArgs^ e);
	void Diagnostic(Platform::Object^ sender, VungleSDK::DiagnosticLogEvent^ e);


};
}


