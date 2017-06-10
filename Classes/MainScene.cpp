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
    
    //snake.snakeImage;
    
    snake = Snake::Snake();
//    snake.snakeImage = Sprite::create("snake.png");
    auto physicsBody = PhysicsBody::createBox(snake.size);
    snake.snakeImage->setPhysicsBody(physicsBody);
    snake.snakeImage->setPosition(Vec2(winSize.width / 2.0,winSize.height / 1.5));
    this->addChild(snake.snakeImage);
    
    this->scheduleUpdate();
    
    //秒毎にHelloWorld::roopを呼び出したい時
    this->schedule(schedule_selector(MainScene::loop), 0.5f);
    
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
            snake.snakeImage->setPosition(Vec2(snake.snakeImage->getPositionX(), snake.snakeImage->getPositionY() - snake.size.height));
            break;
        case 1:
        //右
            snake.snakeImage->setPosition(Vec2(snake.snakeImage->getPositionX() + snake.size.width, snake.snakeImage->getPositionY()));
            break;
        case 2:
        //下
            snake.snakeImage->setPosition(Vec2(snake.snakeImage->getPositionX(), snake.snakeImage->getPositionY() + snake.size.height));
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
