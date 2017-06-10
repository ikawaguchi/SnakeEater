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
    auto snake = Sprite::create("snake.png");
    auto physicsBody = PhysicsBody::createBox(snake->getContentSize());
    snake->setPhysicsBody(physicsBody);
    snake->setPosition(Vec2(winSize.width / 2.0,winSize.height / 2.0));
    this->addChild(snake);
    
    this->scheduleUpdate();
    
    
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
