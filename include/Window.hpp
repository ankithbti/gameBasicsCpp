/* 
 * File:   Window.hpp
 * Author: ankithbti
 *
 * Created on 21 June, 2015, 2:57 PM
 */

#ifndef WINDOW_HPP
#define	WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <Constants.hpp>
#include <string>
#include <iostream>
#include <boost/bind.hpp>



namespace gameEngine {
    
    void myCloseCallback(GLFWwindow* w);
    void myKeyCallback(GLFWwindow* w, int key, int keyCode, int action, int mods);
    void myWindowResizeCallback(GLFWwindow* w, int wd, int hg);
    void myCursorCallback(GLFWwindow* w, double mx, double my);
//    void 
    class Window : private boost::noncopyable {
    public:
        typedef boost::shared_ptr<Window> SmartPtr;
        typedef GLFWwindow * const GLFW_WindowPtr;
    private:
        int _width;
        int _height;
        std::string _title;
        GLFW_WindowPtr _windowPtr;
        static bool _keys[MAX_KEYS];
        static bool _mouseButtons[MAX_BUTTONS];
        static double mx, my;
    public:

        Window(const int& w = DEFAULT_WINDOW_WIDTH, const int& h = DEFAULT_WINDOW_HEIGHT, const std::string& title = DEFAULT_WINDOW_TITLE);

        void addCallback();

        inline void makeVisible() {
            // No Monitor and Sharing
            glfwMakeContextCurrent(_windowPtr);
        }

        inline bool isClosed() {
            return glfwWindowShouldClose(_windowPtr) == 1;
        }

        inline std::pair<int, int> getFrameBufferSize() const {
            return std::pair<int, int>(_width, _height);
        }

        inline const std::string& getTitle() const {
            return _title;
        }

        GLFW_WindowPtr getGlfwWindowPtr() const {
            return _windowPtr;
        }

        ~Window() {
            glfwDestroyWindow(_windowPtr);
        }
        
        static bool isKeyPressed(unsigned int keyCode);
        
        void update();
        void clear();
        
    private:
        friend void myKeyCallback(GLFWwindow* w, int key, int keyCode, int action, int mods);
        friend void myCloseCallback(GLFWwindow* w);
        friend void myWindowResizeCallback(GLFWwindow* w, int wd, int hg);
        friend void myCursorCallback(GLFWwindow* w, double mx, double my);
    };

}

#endif	/* WINDOW_HPP */

