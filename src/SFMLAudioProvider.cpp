#include <SFMLAudioProvider.hpp>

SFMLAudioProvider::SFMLAudioProvider()
{
    _sound.setVolume(100.0f); // Full Volume
    _song.setVolume(100.0f);
}

SFMLAudioProvider::~SFMLAudioProvider()
{

}

void SFMLAudioProvider::StopAllSounds()
{
    if(_sound.getStatus() == sf::Sound::Playing){
        _sound.stop();
    }
    if(_song.getStatus() == sf::Music::Playing){
        _song.stop();
    }
}


void SFMLAudioProvider::PlaySound(std::string filename)
{

    if (_soundBuffer.getDuration() == sf::Time::Zero)
    {
        _soundBuffer.loadFromFile(filename);
    }
    if (_sound.getStatus() == sf::Sound::Playing)
    {
        _sound.stop();
    }
    _sound.setBuffer(_soundBuffer);
    _sound.play();
}

void SFMLAudioProvider::PlaySong(std::string filename, bool looping)
{
    _song.openFromFile(filename);
    _song.setLoop(looping);
    _song.play();
}

bool SFMLAudioProvider::IsSongPlaying()
{
    return _song.getStatus() == sf::Music::Playing;
}

bool SFMLAudioProvider::IsSoundPlaying()
{
    return _sound.getStatus() == sf::Music::Playing;
}





