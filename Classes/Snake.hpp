//
//  Snake.hpp
//  SnakeEater
//
//  Created by kawaguchi on 2017/06/10.
//
//

#ifndef Snake_hpp
#define Snake_hpp

#include <stdio.h>
#include "cocos2d.h"

class Snake
{
public:
    Snake();
    int direction;
    int length;
    cocos2d::Sprite* snakeImage;
    cocos2d::Size size;
};


#endif /* Snake_hpp */
