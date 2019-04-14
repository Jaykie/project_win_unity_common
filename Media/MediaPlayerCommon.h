#pragma once
 //Windows.Media.Playback
#include "Common.h"

using namespace Platform;
using namespace Windows::Media::Playback;
//using namespace Common;

#define MEDIA_EVENT_OPEN "media_open
#define MEDIA_EVENT_COMPLETE "media_complete" 

class MediaPlayerCommon
{
public:
	MediaPlayerCommon();
	~MediaPlayerCommon();

	static  MediaPlayerCommon* Main();
	void Init();

	void Open(String ^ url);
	void Close();
	void Play();
	void Pause();

	void OnMediaEnded(MediaPlayer^ p, Platform::Object^ obj);

protected:
	MediaPlayer^ mp;
	MediaPlayerEventCallbackUnity mpCallbackUnity;

};

