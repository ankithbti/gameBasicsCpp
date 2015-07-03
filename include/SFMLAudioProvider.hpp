/* 
 * File:   SFMLAudioProvider.hpp
 * Author: ankithbti
 *
 * Created on 3 July, 2015, 8:12 PM
 */

#ifndef SFMLAUDIOPROVIDER_HPP
#define	SFMLAUDIOPROVIDER_HPP

#include <SFML/Audio.hpp>
#include <AudioProvider.hpp>

class SFMLAudioProvider : public AudioProvider {
    
    public:
        
        SFMLAudioProvider();
        virtual ~SFMLAudioProvider();
        

    virtual void PlaySound(std::string filename);

    virtual void PlaySong(std::string filename, bool looping);
    

    virtual bool IsSongPlaying();


    virtual bool IsSoundPlaying();
    

    virtual void StopAllSounds();

    private:
        
        sf::SoundBuffer _soundBuffer;
        sf::Sound _sound;
        sf::Music _song;


    
};

#endif	/* SFMLAUDIOPROVIDER_HPP */

