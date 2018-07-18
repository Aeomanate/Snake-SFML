//
// Created by Lyosha12 on 18.05.2018.
//

#ifndef LAB_3_WINDOWFORTESTS_HPP
#define LAB_3_WINDOWFORTESTS_HPP

#include <SFML/Graphics.hpp>

class WindowForTests {
  public:
    WindowForTests(sf::VideoMode screen, sf::Drawable const& drawable);
    void run();
    
  private:
    void handling_events();
    void draw();
  
  private:
    sf::RenderWindow window;
    sf::Drawable const& drawable;
    
};


#endif //LAB_3_WINDOWFORTESTS_HPP
