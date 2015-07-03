/* 
 * File:   AudioProvider.hpp
 * Author: ankithbti
 *
 * Created on 3 July, 2015, 8:11 PM
 */

#ifndef AUDIOPROVIDER_HPP
#define	AUDIOPROVIDER_HPP

#include <string>

class AudioProvider {
public:

    virtual ~AudioProvider() {
    }
    virtual void PlaySound(std::string filename) = 0;
    virtual void PlaySong(std::string filename, bool looping) = 0;
    virtual void StopAllSounds() = 0;

    virtual bool IsSoundPlaying() = 0;
    virtual bool IsSongPlaying() = 0;


};

#endif	/* AUDIOPROVIDER_HPP */

