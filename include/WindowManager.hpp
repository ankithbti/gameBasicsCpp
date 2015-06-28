/* 
 * File:   WindowManager.hpp
 * Author: ankithbti
 *
 * Created on 21 June, 2015, 5:03 PM
 */

#ifndef WINDOWMANAGER_HPP
#define	WINDOWMANAGER_HPP

#include <Window.hpp>
#include <map>

namespace gameEngine {

    class WindowManager : private boost::noncopyable {
    public:
        typedef boost::shared_ptr<WindowManager> SmartPtr;
        typedef std::map<std::string, Window::SmartPtr> WindowsContainer;
        typedef WindowsContainer::iterator WindowsContainerItr;
        typedef WindowsContainer::const_iterator WindowsContainerConstItr;
        typedef std::pair< WindowsContainerItr, bool> WindowsContainerInsertRetType;

    private:

        WindowsContainer _windows;

    public:

        Window::SmartPtr getWindow(const int& w, const int& h, const std::string& t) {
            WindowsContainerConstItr it = _windows.find(t);
            if (it == _windows.end()) {
                Window::SmartPtr win(new Window(w, h, t));
                _windows.insert(std::pair<std::string, Window::SmartPtr>(t, win));
                return win;
            }
            return it->second ;
        }

        void makeVisible(const std::string& title) {
            WindowsContainerConstItr it = _windows.find(title);
            if (it == _windows.end()) {
                throw std::runtime_error(" WindowManager::getWindow() - No window with title: " + title);
            }
            it->second->makeVisible();
        }

    };

}

#endif	/* WINDOWMANAGER_HPP */

