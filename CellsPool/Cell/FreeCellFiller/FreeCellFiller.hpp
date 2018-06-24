//
// Created by Lyosha12 on 24.06.2018.
//

#ifndef SNAKE_FREECELLFILLER_HPP
#define SNAKE_FREECELLFILLER_HPP

#include "../../../Snake/Snake.hpp"
#include "../Filler/Filler.hpp"

class FreeCellFiller: public Filler {
    // * Заполнитель по-умолчанию. Это клетка,
    //   доступная к перемещению на неё.
    // * Текстуру поля в одну клетку не засунешь, тут она отсутствует.
    //   Текстура свободного поля определяется бассейном клеток.
    
  public:
    FreeCellFiller(DefaultRectangle const& default_rectangle, Coord const& coord);
    void modify(Snake& snake) const override;
    
  private:

};


#endif //SNAKE_FREECELLFILLER_HPP
