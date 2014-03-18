#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(VisibleRect::rightBottom(-20,20));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

	this->showSprite();
    
    return true;
}

void HelloWorld::showSprite()
{

	//ccnode* __pnode = ccnode::create();
	//ccsprite* __sp1 = ccsprite::create("helloworld.png");
	//ccsprite* __sp2 = ccsprite::create("grass.png");
	//__pnode->addchild(__sp1);
	//__pnode->addchild(__sp2);
	//__pnode->setposition(ccp($size->width / 2 + $origin->x, $size->height / 2 + $origin->y));
	//__pnode->setshaderprogram(this->getcolorramp());
	//this->addchild(__pnode, 0);

	//_pSprite = CCSprite::create("grass.png");


	//CCGrayFilter* __grayFilter = CCGrayFilter::create(ccc4f(0.2f, 0.3f, 0.4f, 0.0f));
	//CCSprite* __graySprite = CCFilteredSprite::create("helloworld.png", __grayFilter);
	//__graySprite->setAnchorPoint(ccp(0, 0));
	//__graySprite->setPosition(ccp($size->width / 2 + $origin->x, $origin->y));
	//this->addChild(__graySprite);

	//_pSprite = CCFilteredSprite::create("grass5.png", __grayFilter);
	////_pSprite->setShaderProgram(this->getGrass());
	//_pSprite->setPosition(ccp($size->width / 2 + $origin->x, $size->height / 2 + $origin->y));
	//this->addChild(_pSprite, 0);

	CCHBlurFilter* __hblurFilter = CCHBlurFilter::create(0.02f);
	CCBlurBaseFilter* __vblurFilter = CCVBlurFilter::create(0.02f);
	CCSprite* __blurSprite = CCFilteredSprite::create("helloworld.png", 
		CCArray::create(__hblurFilter, __vblurFilter, NULL));	
	__blurSprite->setPosition(VisibleRect::leftTop(240,-160));
	this->addChild(__blurSprite);

	CCMaskFilter* __maskFilter = CCMaskFilter::create(CCString::create("mask.png"));
	CCSprite* __maskSprite = CCFilteredSprite::create("helloworld.png", __maskFilter);
	__maskSprite->setPosition(VisibleRect::rightTop(-240, -160));
	this->addChild(__maskSprite);

	//CCGaussianHBlurFilter* __gaussianHblurFilter = CCGaussianHBlurFilter::create(2.0f);
	//CCSprite* __gaussianBlurSprite = CCFilteredSprite::create("helloworld.png", __gaussianHblurFilter);
	//__gaussianBlurSprite->setPosition(VisibleRect::leftBottom(240, 160));
	//this->addChild(__gaussianBlurSprite);

	//CCSharpenFilter* __sharpenFilter = CCSharpenFilter::create(0.1f, 0.00002f, 0.0002f);
	CCSharpenFilter* __sharpenFilter = CCSharpenFilter::create(0.1f, 1.0f/480.f, 1.0f/320.f);
	CCSprite* __sharpenSprite = CCFilteredSprite::create("helloworld.png", __sharpenFilter);
	__sharpenSprite->setPosition(VisibleRect::leftBottom(240, 160));
	this->addChild(__sharpenSprite, -10);

}

cocos2d::CCGLProgram* HelloWorld::getGrass()
{
	cocos2d::CCGLProgram* __pProg = new CCGLProgram();
	//__pProg->initWithVertexShaderByteArray(ccPositionTextureA8Color_vert, ccShader_grass);

	__pProg->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
	__pProg->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
	__pProg->link();
	__pProg->updateUniforms();

	_timeUniformLocation = glGetUniformLocation(__pProg->getProgram(), "u_time");
	this->scheduleUpdate();

	__pProg->use();

	return __pProg;
}

cocos2d::CCGLProgram* HelloWorld::getEmbossMov()
{
	cocos2d::CCGLProgram* __pProg = new CCGLProgram();
	//__pProg->initWithVertexShaderByteArray(ccPositionTextureA8Color_vert, ccShader_emboss );

	__pProg->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
	__pProg->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
	__pProg->link();
	__pProg->updateUniforms();

	_timeUniformLocation = glGetUniformLocation(__pProg->getProgram(), "u_time");
	this->scheduleUpdate();

	__pProg->use();

	return __pProg;
}

void HelloWorld::update(float $dt)
{
	_totalTime += $dt;
	//CCLOG("show %f, dt %f", _totalTime, $dt);
	_pSprite->getShaderProgram()->use();
	glUniform1f(_timeUniformLocation, _totalTime);

}

cocos2d::CCGLProgram* HelloWorld::getEmboss()
{
	cocos2d::CCGLProgram* __pProg = new CCGLProgram();
	//__pProg->initWithVertexShaderByteArray(ccPositionTextureA8Color_vert,ccShader_emboss);

	__pProg->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
	__pProg->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
	__pProg->link();
	__pProg->updateUniforms();
	return __pProg;
}

cocos2d::CCGLProgram* HelloWorld::getColorRamp()
{
	cocos2d::CCGLProgram* __pProg = new CCGLProgram();
	//__pProg->initWithVertexShaderByteArray(ccPositionTextureA8Color_vert,ccShader_colorramp);

	__pProg->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
	__pProg->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
	__pProg->link();
	__pProg->updateUniforms();

	glUniform1i(glGetUniformLocation(__pProg->getProgram(), "u_colorRampTexture"), 1);

	CCTexture2D* __texture = CCTextureCache::sharedTextureCache()->addImage("colorRamp.png");
	__texture->setAntiAliasTexParameters();
	
	__pProg->use();
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, __texture->getName());
	glActiveTexture(GL_TEXTURE0);

	return __pProg;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}