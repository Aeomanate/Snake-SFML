#include <exception>
#include <string>
#include <windows.h>

#include <SFML/Graphics.hpp>

#include "Utility/ErrorPrinter/ErrorPrinter.hpp"
#include "CellsPool/DefaultRectangle/DefaultRectangle.hpp"
#include "CellsPool/CellsPool.hpp"
#include "Snake/Snake.hpp"
#include "BonusManager/BonusManager.hpp"
#include "Utility/ThreadGuard/ThreadGuard.hpp"
#include "AudioPlayer/AudioPlayer.hpp"

class Game {
    // Главный класс. Управляет игровым циклом и отрисовкой.
    
  public:
    Game(
        unsigned long width, unsigned long height,
        size_t count_cells_x, size_t count_cells_y
    )
    : default_rectangle(width/count_cells_x, height/count_cells_y)
    , window(
        {
            static_cast<unsigned>(default_rectangle.getSize().x*count_cells_x),
            static_cast<unsigned>(default_rectangle.getSize().y*count_cells_y)
        },
        "Snake"
      )
    , cells_pool(count_cells_x, count_cells_y, window, default_rectangle)
    , snake(cells_pool)
    , bonus_manager(cells_pool)
    { window.setFramerateLimit(30); }
    
    void mainLoop() {
        try {
            while(window.isOpen()) {
                window.draw(cells_pool); // Отрисовываем все клетки поля.
                window.display();
                handle_events();
                snake.move(); // Двигаем змейку в соответствии с её направлением.
            }
            
        } catch(std::exception const& e) {
            ErrorPrinter(e.what()).print();
        }
    }
    void handle_events() {
        sf::Event event;
        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    return;
                    
                case sf::Event::KeyPressed:
                    // Изменим направление змейки
                    // в соответствии с нажатой клавишей.
                    switch(event.key.code) {
                        case sf::Keyboard::Up    :
                            snake.changeDirection(Snake::Direction::Up);
                            return;
                        case sf::Keyboard::Down  :
                            snake.changeDirection(Snake::Direction::Down);
                            return;
                        case sf::Keyboard::Left  :
                            snake.changeDirection(Snake::Direction::Left);
                            return;
                        case sf::Keyboard::Right :
                            snake.changeDirection(Snake::Direction::Right);
                            return;
                        default:
                            return;
                    }
                    
                default: ;
            }
        }
    }
    
  private:
    DefaultRectangle default_rectangle;
    sf::RenderWindow window;
    CellsPool cells_pool;
    Snake snake;
    BonusManager bonus_manager;
    AudioPlayer audio_player;
};

int main() {
    // Настройка "окружения".
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    srand(static_cast<unsigned int>(time(0)));
    
    Game(800, 800, 20, 20).mainLoop();
    
    return 0;
}
