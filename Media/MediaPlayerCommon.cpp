#include "pch.h"
#include "MediaPlayerCommon.h"
#include "Common.h" 
using namespace Windows::Foundation;


void MediaPlayer_Open(char *url)
{
	std::string str(url);
	String ^ strnew = string2PlatformString(str);

	MediaPlayerCommon::Main()->Open(strnew);
}
void MediaPlayer_Close()
{
	MediaPlayerCommon::Main()->Close();
}
void MediaPlayer_Play()
{
	MediaPlayerCommon::Main()->Play();
}

void MediaPlayer_Pause()
{
	MediaPlayerCommon::Main()->Pause();
} 
void MediaPlayer_SetCallbackUnity(MediaPlayerEventCallbackUnity callback)
{
//	AdVideoCallBack::Main()->SetCallbackUnity(callback);
}

MediaPlayerCommon *s_MediaPlayerCommon = NULL;
MediaPlayerCommon *MediaPlayerCommon::Main()
{
	if (s_MediaPlayerCommon != NULL)
	{
		return s_MediaPlayerCommon;
	}
	s_MediaPlayerCommon = new MediaPlayerCommon();
	s_MediaPlayerCommon->Init();

	return s_MediaPlayerCommon;
}

MediaPlayerCommon::MediaPlayerCommon()
{
}

MediaPlayerCommon::~MediaPlayerCommon()
{
}
 
void MediaPlayerCommon::Init()
{
	mp = ref new MediaPlayer();
}

void MediaPlayerCommon::Open(String ^ url)
{
	if (mp != nullptr) { 
		mp->SetUriSource(ref new Uri(url));
		mp->Play();
	//	mp->MediaEnded = OnMediaEnded;

		//mp->MediaEnded = ref new EventHandler<MediaPlayer ^>(this, &MediaPlayerCommon::OnMediaEnded);
		//mp->MediaEnded = ref new EventHandler<MediaPlayer ^，Platform::Object^ >(&MediaPlayerCommon::OnMediaEnded);
		//mp->MediaEnded += ref new EventHandler<MediaPlayer ^>(this, &MediaPlayerCommon::OnMediaEnded);
	}
} 
void MediaPlayerCommon::Close()
{

	if (mp != nullptr) {
		//mp->Close();
	}
}
void MediaPlayerCommon::Play()
{
	if (mp != nullptr) { 
		mp->Play();
	}
}
void MediaPlayerCommon::Pause()
{

	if (mp != nullptr) {
		mp->Pause();
	}
}

void MediaPlayerCommon::OnMediaEnded(MediaPlayer^ p,Platform::Object^ obj)
{
	if (mpCallbackUnity != nullptr) {
		mpCallbackUnity(MEDIA_EVENT_COMPLETE);
	  }
}
