/* 
 * File:   AudioServiceLocator.hpp
 * Author: ankithbti
 *
 * Created on 3 July, 2015, 8:23 PM
 */

#ifndef AUDIOSERVICELOCATOR_HPP
#define	AUDIOSERVICELOCATOR_HPP

#include <AudioProvider.hpp>

class AudioServiceLocator {
private:

    static AudioProvider * _allocator;
public:

    static AudioProvider* GetAudio() {
        return _allocator;
    }

    static void RegisterServiceLocator(AudioProvider *provider) {
        _allocator = provider;
    }

};

#endif	/* AUDIOSERVICELOCATOR_HPP */

