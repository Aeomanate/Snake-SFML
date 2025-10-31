//
// Created by Lyosha12 on 18.05.2018.
//

#ifndef LAB_3_WINDOWFORTESTS_HPP
#define LAB_3_WINDOWFORTESTS_HPP

#include <SFML/Graphics.hpp>

class WindowForTests
{
public:
    WindowForTests(sf::VideoMode screen, sf::Drawable const& drawable);
    void run();

public: // SFML callbacks
    void operator()(sf::Event::Closed const&);

    // All-catch operator for other events
    template <class T>
    void operator()(T const&) {}

private:
    void handling_events();
    void draw();

private:
    float               scale_input = 1.15;
    sf::VideoMode       mode_for_test;
    sf::RenderWindow    window;
    sf::Drawable const& drawable;
};


#endif //LAB_3_WINDOWFORTESTS_HPP
