#pragma once
 //Windows.Media.Playback
using namespace Platform;
using namespace Windows::Media::Playback;
//using namespace Common;
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
};

