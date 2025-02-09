#include "GameScene.h"
//#include"go2.h"
#include"GameOverScene.h"
#include"go2.h"
#include "ui/CocosGUI.h"
#include"definitions.h"
#include"gamerules.h"
#include <sstream>
#include <algorithm>
#include"rules.h"
#include<iostream>
#include"MainMenuScene.h"




using namespace std;


USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;

}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto background = Sprite::create("res/Board1.png");
	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background, -1);

	float rX = visibleSize.width / background->getContentSize().width;
	float rY = visibleSize.height / background->getContentSize().height;
	background->setScaleX(rX);
	background->setScaleY(rY);

	auto CPUvPlayerButton = cocos2d::ui::Button::create("res/Back.png", "res/Back_p.png");
	CPUvPlayerButton->setPosition(Point(visibleSize.width / 1.06 + origin.x, visibleSize.height / 1.08 + origin.y));
	CPUvPlayerButton->addTouchEventListener([&](Ref * sender, cocos2d::ui::Widget::TouchEventType type) {
		switch (type)
		{

		case ui::Widget::TouchEventType::ENDED:
			auto scene = MainMenuScene::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		}
		});

	CPUvPlayerButton->setScale(rY*0.9);
	this->addChild(CPUvPlayerButton);
	
	
	for (int i = 0; i < 24; i++)
	{
		tokens[i] = Sprite::create("res/sp.png");
	}

	//ligne 1
	tokens[0]->setPosition(Point(visibleSize.width / 3.8 + origin.x, visibleSize.height / 10 + origin.y));//done 0
	this->addChild(tokens[0], -1);

	tokens[1]->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 10 + origin.y));//done 1
	this->addChild(tokens[1], -1);

	tokens[2]->setPosition(Point(visibleSize.width / 1.355 + origin.x, visibleSize.height / 10 + origin.y));//done 2
	this->addChild(tokens[2], -1);

	//ligne2
	tokens[3]->setPosition(Point(visibleSize.width / 2.85 + origin.x, visibleSize.height / 4 + origin.y));//done 3
	this->addChild(tokens[3], -1);

	tokens[4]->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 4 + origin.y));//done 4
	this->addChild(tokens[4], -1);

	tokens[5]->setPosition(Point(visibleSize.width / 1.539 + origin.x, visibleSize.height / 4 + origin.y));//done 5
	this->addChild(tokens[5], -1);

	//ligne3
	tokens[6]->setPosition(Point(visibleSize.width / 2.33 + origin.x, visibleSize.height / 2.55 + origin.y));//done 6
	this->addChild(tokens[6], -1);

	tokens[7]->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.55 + origin.y));//done 7
	this->addChild(tokens[7], -1);

	tokens[8]->setPosition(Point(visibleSize.width / 1.734 + origin.x, visibleSize.height / 2.55 + origin.y));//done 8
	this->addChild(tokens[8], -1);


	//ligne 4
	tokens[9]->setPosition(Point(visibleSize.width / 3.8 + origin.x, visibleSize.height / 1.92 + origin.y));//done 9
	this->addChild(tokens[9], -1);

	tokens[10]->setPosition(Point(visibleSize.width / 2.85 + origin.x, visibleSize.height / 1.92 + origin.y));//done 10
	this->addChild(tokens[10], -1);

	tokens[11]->setPosition(Point(visibleSize.width / 2.33 + origin.x, visibleSize.height / 1.92 + origin.y));//done 11
	this->addChild(tokens[11], -1);

	tokens[12]->setPosition(Point(visibleSize.width / 1.734 + origin.x, visibleSize.height / 1.92 + origin.y));//done 12
	this->addChild(tokens[12], -1);

	tokens[13]->setPosition(Point(visibleSize.width / 1.53 + origin.x, visibleSize.height / 1.92 + origin.y));//done 13
	this->addChild(tokens[13], -1);

	tokens[14]->setPosition(Point(visibleSize.width / 1.355 + origin.x, visibleSize.height / 1.92 + origin.y));//done 14
	this->addChild(tokens[14], -1);

	//ligne5
	tokens[15]->setPosition(Point(visibleSize.width / 2.33 + origin.x, visibleSize.height / 1.55 + origin.y));//done 15
	this->addChild(tokens[15], -1);

	tokens[16]->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 1.55 + origin.y));//done 16
	this->addChild(tokens[16], -1);

	tokens[17]->setPosition(Point(visibleSize.width / 1.734 + origin.x, visibleSize.height / 1.55 + origin.y));//done 17
	this->addChild(tokens[17], -1);

	//ligne6
	tokens[18]->setPosition(Point(visibleSize.width / 2.85 + origin.x, visibleSize.height / 1.255 + origin.y));//done 18
	this->addChild(tokens[18], -1);

	tokens[19]->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 1.255 + origin.y));//done 19
	this->addChild(tokens[19], -1);

	tokens[20]->setPosition(Point(visibleSize.width / 1.539 + origin.x, visibleSize.height / 1.255 + origin.y));//done 20
	this->addChild(tokens[20], -1);

	//ligne 7
	tokens[21]->setPosition(Point(visibleSize.width / 3.8 + origin.x, visibleSize.height / 1.078 + origin.y));//done 21
	this->addChild(tokens[21], -1);

	tokens[22]->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 1.078 + origin.y));//done 22
	this->addChild(tokens[22], -1);

	tokens[23]->setPosition(Point(visibleSize.width / 1.355 + origin.x, visibleSize.height / 1.078 + origin.y));//done 23
	this->addChild(tokens[23], -1);

	///////////////////////////////////////////////////////////////////////////////////black

	black[0] = Sprite::create("res/b.png");
	black[0]->setPosition(Point(visibleSize.width / 5.55+ origin.x, visibleSize.height / 2 + origin.y));//done 23
	this->addChild(black[0], -1);

	black[1] = Sprite::create("res/b.png");
	black[1]->setPosition(Point(visibleSize.width / 5.55+ origin.x- black[1]-> getContentSize().width, visibleSize.height / 2 + origin.y));//done 23
	this->addChild(black[1], -1);

	black[2] = Sprite::create("res/b.png");
	black[2]->setPosition(Point(visibleSize.width / 5.55 + origin.x - black[1]->getContentSize().width*2, visibleSize.height / 2 + origin.y));//done 23
	this->addChild(black[2], -1);
	///////
	black[3] = Sprite::create("res/b.png");
	black[3]->setPosition(Point(visibleSize.width / 5.55 + origin.x, visibleSize.height / 2 + origin.y - black[1]->getContentSize().width));//done 23
	this->addChild(black[3], -1);

	black[4] = Sprite::create("res/b.png");
	black[4]->setPosition(Point(visibleSize.width / 5.55 + origin.x - black[1]->getContentSize().width, visibleSize.height / 2 + origin.y - black[1]->getContentSize().width));//done 23
	this->addChild(black[4], -1);

	black[5] = Sprite::create("res/b.png");
	black[5]->setPosition(Point(visibleSize.width / 5.55 + origin.x - black[1]->getContentSize().width * 2, visibleSize.height / 2 + origin.y - black[1]->getContentSize().width));//done 23
	this->addChild(black[5], -1);
	///////////
	black[6] = Sprite::create("res/b.png");
	black[6]->setPosition(Point(visibleSize.width / 5.55 + origin.x, visibleSize.height / 2 + origin.y - black[1]->getContentSize().width*2));//done 23
	this->addChild(black[6], -1);

	black[7] = Sprite::create("res/b.png");
	black[7]->setPosition(Point(visibleSize.width / 5.55 + origin.x - black[1]->getContentSize().width, visibleSize.height / 2 + origin.y - black[1]->getContentSize().width*2));//done 23
	this->addChild(black[7], -1);

	black[8] = Sprite::create("res/b.png");
	black[8]->setPosition(Point(visibleSize.width / 5.55 + origin.x - black[1]->getContentSize().width * 2, visibleSize.height / 2 + origin.y - black[1]->getContentSize().width*2));//done 23
	this->addChild(black[8], -1);

	///////////////////////////////////////////////////////////////////////////////////white


	white[0] = Sprite::create("res/w.png");
	white[0]->setPosition(Point(visibleSize.width / 1.08 + origin.x, visibleSize.height / 2 + origin.y));//done 23
	this->addChild(white[0], -1);

	white[1] = Sprite::create("res/w.png");
	white[1]->setPosition(Point(visibleSize.width / 1.08 + origin.x - white[1]->getContentSize().width, visibleSize.height / 2 + origin.y));//done 23
	this->addChild(white[1], -1);

	white[2] = Sprite::create("res/w.png");
	white[2]->setPosition(Point(visibleSize.width / 1.08 + origin.x - white[1]->getContentSize().width * 2, visibleSize.height / 2 + origin.y));//done 23
	this->addChild(white[2], -1);
	///////
	white[3] = Sprite::create("res/w.png");
	white[3]->setPosition(Point(visibleSize.width / 1.08 + origin.x, visibleSize.height / 2 + origin.y - white[1]->getContentSize().width));//done 23
	this->addChild(white[3], -1);

	white[4] = Sprite::create("res/w.png");
	white[4]->setPosition(Point(visibleSize.width / 1.08 + origin.x - white[1]->getContentSize().width, visibleSize.height / 2 + origin.y - white[1]->getContentSize().width));//done 23
	this->addChild(white[4], -1);

	white[5] = Sprite::create("res/w.png");
	white[5]->setPosition(Point(visibleSize.width / 1.08 + origin.x - white[1]->getContentSize().width * 2, visibleSize.height / 2 + origin.y - white[1]->getContentSize().width));//done 23
	this->addChild(white[5], -1);
	///////////
	white[6] = Sprite::create("res/w.png");
	white[6]->setPosition(Point(visibleSize.width / 1.08 + origin.x, visibleSize.height / 2 + origin.y - white[1]->getContentSize().width * 2));//done 23
	this->addChild(white[6], -1);

	white[7] = Sprite::create("res/w.png");
	white[7]->setPosition(Point(visibleSize.width / 1.08 + origin.x - white[1]->getContentSize().width, visibleSize.height / 2 + origin.y - white[1]->getContentSize().width * 2));//done 23
	this->addChild(white[7], -1);

	white[8] = Sprite::create("res/w.png");
	white[8]->setPosition(Point(visibleSize.width / 1.08 + origin.x - white[1]->getContentSize().width * 2, visibleSize.height / 2 + origin.y - white[1]->getContentSize().width * 2));//done 23
	this->addChild(white[8], -1);



	/*//graphics
	tokens[0] = Sprite::create("res/sp.png");
	tokens[0]->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2+ origin.y));//done 2
	this->addChild(tokens[0]);*/




	/**/

	// Touch Events Handling
	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(GameScene::onTouchCancelled, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	return true;


}	
int hold = 0;
void GameScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	Point touchPoint = touch->getLocation();



	if (capture)
	{
		for (int j = 0; j < 24; j++) //rassembler ceux qu'on ne peut plus capturer
		{
			if (database[j] != 0 && (moulinformation(j, database[j]) ))
				nocapture[j] = 1;
		}

		for (int i = 0; i < 24; i++)
		{
			if (tokens[i]->getBoundingBox().containsPoint(touchPoint) && database[i]==player && nocapture[i]==0)
			{
				if (player == -1)
				{
					for (int k = 0; k < 9; k++)
					{
						if ( black[k]->getBoundingBox().containsPoint(touchPoint))
						{
							auto moveTo = MoveTo::create(0.5, Point(0, 0));
							black[k]->runAction(moveTo);
							database[i] = 0;
							capture = 0;
						}
					}
				}
				if (player == 1)
				{
					for (int k = 0; k < 9; k++)
					{
						if (white[k]->getBoundingBox().containsPoint(touchPoint))
						{
							auto moveTo = MoveTo::create(0.5, Point(0, 0));
							white[k]->runAction(moveTo);
							database[i] = 0;
							capture = 0;
						}
					}
				}
			}
		}
		endgame();
	}
	else {
			if (times < 18)
		{


			for (int i = 0; i < 24; i++)
			{
				if (database[i] == 0 && tokens[i]->getBoundingBox().containsPoint(touchPoint))
				{

					if (player == 1)
					{
						database[i] = 1;
						auto moveTo = MoveTo::create(0.5, Vec2(tokens[i]->getPositionX(), tokens[i]->getPositionY()));
						white[times / 2]->runAction(moveTo);
						capture = moulinformation(i, player);
						log("mooooooooolin : %d", moulinformation(i, 1));
					}
					if (player == -1)
					{

						database[i] = -1;
						auto moveTo = MoveTo::create(0.5, Vec2(tokens[i]->getPositionX(), tokens[i]->getPositionY()));
						black[times / 2]->runAction(moveTo);
						capture = moulinformation(i, player);
						log("mooooooooolin : %d", moulinformation(i, -1));
					}
					times++;
					player *= -1;
				}
			}
		}



		if (times == 18) 
		{
			

			if (hold)
			{
				for (int i = 0; i < 24; i++)
				{
					if (database[i] == 0 && tokens[i]->getBoundingBox().containsPoint(touchPoint))
					{
						destination = i;
					}
				}
				for (int i = 0; i < 24; i++)
				{
					if (database[i] == 0 && (validmove(source, destination) ||(noir==3&&player==-1)||(blanc==3&&player==1)) && tokens[i]->getBoundingBox().containsPoint(touchPoint))
					{

						auto moveTo = MoveTo::create(0.5, Vec2(tokens[i]->getPositionX(), tokens[i]->getPositionY()));
						if (player == -1)
						{
							black[selected]->runAction(moveTo);
							black[selected]->setTexture("res/b.png");
						}
						if (player == 1)
						{
							white[selected]->runAction(moveTo);
							white[selected]->setTexture("res/w.png");
						}
						database[source] = 0;
						database[destination] = player;
						hold = 0;
						player *= -1;
						log("mooooooooolin : %d", moulinformation(destination, database[destination]));
						log("avec : %d player : %d", destination, database[destination]);
						capture = moulinformation(destination, database[destination]);
					}
				}
			}


			for (int i = 0; i < 9; i++)
			{
				if (player == -1)
					if (black[i] != 0 && black[i]->getBoundingBox().containsPoint(touchPoint))
					{
						for (int k = 0; k < 9; k++)
						{
							black[k]->setTexture("res/b.png");
						}
						selected = i;
						black[selected]->setTexture("res/big_b.png");
						hold = 1;
					}
				if (player == 1)
					if (white[i] != 0 && white[i]->getBoundingBox().containsPoint(touchPoint))
					{
						for (int k = 0; k < 9; k++)
						{
							white[k]->setTexture("res/w.png");
						}
						selected = i;
						white[selected]->setTexture("res/big_w.png");
						hold = 1;
					}
			}
			if(hold)
			for (int k = 0; k < 24; k++)
			{
				if (tokens[k]->getBoundingBox().containsPoint(touchPoint) && database[k] == player)
				{
					source = k;
				}
			}


			
		}
	}

	
	log("source : %d destination %d capture %d", source,destination,capture);
	log("%d %d %d",nocapture[21], nocapture[22], nocapture[23]);
	log("%d %d %d", nocapture[18], nocapture[19], nocapture[20]);
	log("%d %d %d", nocapture[15], nocapture[16], nocapture[17]);
	log("%d %d %d %d %d %d", nocapture[9], nocapture[10], nocapture[11], nocapture[12], nocapture[13], nocapture[14]);
	log("%d %d %d", nocapture[6], nocapture[7], nocapture[8]);
	log("%d %d %d", nocapture[3], nocapture[4], nocapture[5]);
	log("%d %d %d", nocapture[0], nocapture[1], nocapture[2]);

	for (int j = 0; j < 24; j++)
	{
		nocapture[j] = 0;
	}
	return;

}


bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
	return true;
}

void GameScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {     }
void GameScene::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event) {     }

bool GameScene::validmove(int in, int out)
{
	if (in == out)
		return false;
	if (in == 0)
		return( out == 1 || out == 9);
	if (in == 1)
		return(out == 0 || out == 2 || out==4);
	if (in == 2)
		return(out == 1 || out == 14);
	if (in == 3)
		return(out == 4 || out == 10);
	if (in == 4)
		return (out == 3 || out == 5 || out == 1 || out == 7);
	if (in == 5)
		return (out == 4 || out == 13);
	if (in == 6)
		return (out == 7 || out == 11);
	if (in == 7)
		return(out == 4 || out == 6 || out == 8);
	if (in == 8)
		return(out == 12 || out == 7);
	if (in == 9)
		return(out == 0 || out == 10 || out == 21);
	if (in == 10)
		return(out == 9 || out == 11 || out == 3 || out == 18);
	if (in == 11)
		return(out == 6 || out == 10 || out == 15);
	if (in == 12)
		return(out == 8 || out == 13 || out == 17);
	if (in == 13)
		return(out == 12 || out == 14 || out == 5 || out == 20);
	if (in == 14)
		return(out == 2 || out == 23 || out == 13);
	if (in == 15)
		return(out == 11 || out == 16);
	if (in == 16)
		return(out == 15 | out == 17 || out == 19);
	if(in == 17)
		return(out == 16 || out == 12);
	if (in == 18)
		return(out == 10 || out == 19);
	if (in == 19)
		return(out == 18 || out == 20 || out == 16 || out == 22);
	if (in == 20)
		return(out == 19 || out == 13);
	if (in == 21)
		return(out == 9 || out == 22);
	if (in == 22)
		return(out == 21 || out == 19 || out == 23);
	if (in == 23)
		return(out == 22 || out == 14);

	return false;


}

bool GameScene::moulinformation(int in, int player)
{


	if (in == 0)
		return((database[1]==player && database[2]==player) || (database[9] == player && database[21] == player));
	if (in == 1)
		return((database[0] == player && database[2] == player) || (database[4] == player && database[7] == player));
	if (in == 2)
		return((database[1] == player && database[0] == player) || (database[14] == player && database[23] == player));
	if (in == 3)
		return((database[4] == player && database[5] == player) || (database[10] == player && database[18] == player));
	if (in == 4)
		return ((database[3] == player && database[5] == player) || (database[1] == player && database[7] == player));
	if (in == 5)
		return ((database[4] == player && database[3] == player) || (database[13] == player && database[20] == player));
	if (in == 6)
		return ((database[7] == player && database[8] == player) || (database[11] == player && database[15] == player));
	if (in == 7)
		return((database[4] == player && database[1] == player) || (database[6] == player && database[8] == player));
	if (in == 8)
		return((database[12] == player && database[17] == player) || (database[7] == player && database[6] == player));
	if (in == 9)
		return((database[0] == player && database[21] == player) || (database[10] == player && database[11] == player));
	if (in == 10)
		return((database[9] == player && database[11] == player) || (database[3] == player && database[18] == player));
	if (in == 11)
		return((database[6] == player && database[15] == player) || (database[10] == player && database[9] == player));
	if (in == 12)
		return((database[8] == player && database[17] == player) || (database[13] == player && database[14] == player) );
	if (in == 13)
		return((database[12] == player && database[14] == player) || (database[5] == player && database[20] == player));
	if (in == 14)
		return((database[2] == player && database[23] == player) || (database[13] == player && database[12] == player));
	if (in == 15)
		return((database[11] == player && database[6] == player) || (database[16] == player && database[17] == player));
	if (in == 16)
		return((database[15] == player && database[17] == player) || (database[19] == player && database[22] == player));
	if (in == 17)
		return((database[16] == player && database[15] == player) || (database[12] == player && database[8] == player));
	if (in == 18)
		return((database[10] == player && database[3] == player) || (database[19] == player && database[20] == player));
	if (in == 19)
		return((database[18] == player && database[20] == player) || (database[16] == player && database[22] == player ));
	if (in == 20)
		return((database[19] == player && database[18] == player) || (database[13] == player && database[5] == player));
	if (in == 21)
		return((database[9] == player && database[0] == player) || (database[22] == player && database[23] == player));
	if (in == 22)
		return((database[21] == player && database[23] == player) || (database[16] == player && database[19] == player));
	if (in == 23)
		return((database[22] == player && database[21] == player) || (database[14] == player && database[2] == player));

	return false;

	
}

void GameScene::endgame()
{
	if (times == 18)
	{

		noir = 0;
		blanc = 0;
		//game over test
		for (int i = 0; i < 24; i++)
		{

			if (database[i] == -1)
				noir++;
			if (database[i] == 1)
				blanc++;
		}
		if (noir == 2)
		{
			auto scene = GameOverScene::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		}
		if (blanc == 2)
		{
			auto scene = go2::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		}
		//end of game over test

	}
}