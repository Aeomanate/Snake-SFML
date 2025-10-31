// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by Lyosha12 on 18.05.2018.
//

#include <thread>
#include <optional>

#include "WindowForTests.hpp"
#include "Utility/FixesSFML.h"

WindowForTests::
WindowForTests(sf::VideoMode screen, sf::Drawable const& drawable)
: mode_for_test(screen.size * scale_input)
, window(mode_for_test, "Test Window")
, drawable(drawable)
{
    window.setFramerateLimit(30);
}

void WindowForTests::
run()
{
    while (window.isOpen())
    {
        handling_events();
        draw();
    }
}


void WindowForTests::operator()(const sf::Event::Closed&)
{
    window.close();
};

void WindowForTests::
handling_events()
{
    while (const std::optional event = window.pollEvent())
    {
        event->visit(*this);
    }
}

void WindowForTests::
draw()
{
    window.clear({ 128, 128, 128 });
    window.draw(drawable, sf::Transform().translate(window.getSize() / 15.f));
    window.display();
}
