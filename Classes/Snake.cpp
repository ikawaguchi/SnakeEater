//
//  Snake.cpp
//  SnakeEater
//
//  Created by kawaguchi on 2017/06/10.
//
//

#include "Snake.hpp"

USING_NS_CC;

Snake::Snake()
{
    snakeImage = Sprite::create("snake.png");
    size = snakeImage->getContentSize();
    direction = 0;
    length = 1;
}
