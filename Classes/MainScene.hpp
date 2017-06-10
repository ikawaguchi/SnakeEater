//
//  MainScene.hpp
//  SnakeEater
//
//  Created by kawaguchi on 2017/06/10.
//
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Snake.hpp"

#endif /* MainScene_hpp */

class MainScene :public cocos2d::Layer
{
protected:
    MainScene();
    virtual ~MainScene();
    bool init() override;
    void loop(float dt);
    
    
public:
    static cocos2d::Scene* createScene();
    void update(float dt) override;
    CREATE_FUNC(MainScene);
    
    Snake snake;
};
