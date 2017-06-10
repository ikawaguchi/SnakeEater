//
//  MainScene.cpp
//  SnakeEater
//
//  Created by kawaguchi on 2017/06/10.
//
//

#include "MainScene.hpp"

USING_NS_CC;

Scene* MainScene::createScene()
{
    
    auto scene = Scene::createWithPhysics();
    auto world = scene->getPhysicsWorld();
    
    world->setGravity(Vec2::ZERO);
    world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    auto layer = MainScene::create();
    scene->addChild(layer);
    
    return scene;
}


bool MainScene::init()
{
    if(!Layer::init()) {
        return false;
    }
    
    auto winSize = Director::getInstance()->getWinSize();
    
    
    snake = Snake::Snake();
    auto physicsBody = PhysicsBody::createBox(snake.size);
    snake.snakeImage->setPhysicsBody(physicsBody);
    snake.snakeImage->setPosition(Vec2(winSize.width / 2.0,winSize.height / 1.5));
    this->addChild(snake.snakeImage);
    
    this->scheduleUpdate();
    this->schedule(schedule_selector(MainScene::loop), 0.3f);
    
    //ボタン生成
    auto topButton = ui::Button::create("DirectionButton.png");
    topButton->setPosition(Vec2(winSize.width / 2.0, 300));
    topButton->setScale(2.0);
    topButton->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED) {
            this->snake.direction = 0;
        }
    });
    this->addChild(topButton);

    auto rightButton = ui::Button::create("DirectionButton.png");
    rightButton->setPosition(Vec2(winSize.width / 4 * 3, 200));
    rightButton->setScale(2.0);
    rightButton->setRotation(90);
    rightButton->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED) {
            this->snake.direction = 1;
        }
    });
    this->addChild(rightButton);

    auto bottomButton = ui::Button::create("DirectionButton.png");
    bottomButton->setPosition(Vec2(winSize.width / 2.0, 100));
    bottomButton->setScale(2.0);
    bottomButton->setRotation(180);
    bottomButton->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED) {
            this->snake.direction = 2;
        }
    });
    this->addChild(bottomButton);

    auto leftButton = ui::Button::create("DirectionButton.png");
    leftButton->setPosition(Vec2(winSize.width / 4 , 200));
    leftButton->setScale(2.0);
    leftButton->setRotation(270);
    leftButton->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::ENDED) {
            this->snake.direction = 3;
        }
    });
    this->addChild(leftButton);

    return true;
}




MainScene::MainScene()
{
    
}


MainScene::~MainScene()
{
    
}

void MainScene::update(float dt)
{
    
}


void MainScene::loop(float dt) {
    switch (snake.direction) {
        case 0:
        //上
            snake.snakeImage->setPosition(Vec2(snake.snakeImage->getPositionX(), snake.snakeImage->getPositionY() + snake.size.height));
            break;
        case 1:
        //右
            snake.snakeImage->setPosition(Vec2(snake.snakeImage->getPositionX() + snake.size.width, snake.snakeImage->getPositionY()));
            break;
        case 2:
        //下
            snake.snakeImage->setPosition(Vec2(snake.snakeImage->getPositionX(), snake.snakeImage->getPositionY() - snake.size.height));
            break;
        case 3:
        //左
            snake.snakeImage->setPosition(Vec2(snake.snakeImage->getPositionX() - snake.size.width, snake.snakeImage->getPositionY()));
            break;
            
        default:
            break;
    }
    
    if (snake.direction == 0) {
    }
}
