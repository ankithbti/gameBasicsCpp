/* 
 * File:   GraphicsWorld.hpp
 * Author: ankithbti
 *
 * Created on 21 June, 2015, 4:09 PM
 */

#ifndef GRAPHICSWORLD_HPP
#define	GRAPHICSWORLD_HPP

#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <Window.hpp>

#include <vector>

namespace gameEngine {

    extern "C"
    bool initGraphicsWorld() {
        if (!glfwInit()) {
            return false;
        }
        return true;
    }

    class GraphicsWorld : private boost::noncopyable {
    public:
        typedef boost::shared_ptr<GraphicsWorld> SmartPtr;

    private:

        std::vector<Window::SmartPtr> _windows;

        void init();

    public:

        GraphicsWorld() {
            init();
        }

        Window::SmartPtr createWindow(const int& w, const int& h, const std::string& title);

        ~GraphicsWorld() {
            glfwTerminate();
        }


    };

}

#endif	/* GRAPHICSWORLD_HPP */

