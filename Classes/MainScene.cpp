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
