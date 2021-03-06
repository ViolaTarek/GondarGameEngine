#ifndef __GS_GGJ_PANORAMA__
#define __GS_GGJ_PANORAMA__

#include "gsGGJObject.h"

class gsSpriteSheet;

class gsGGJPanorama : public gsGGJObject {
public:
	float acelerateCounter;
	float speedFactor;
	gsSpriteSheet *sprite;
	gsSpriteSheet *colorSprite;
	gsTransform colorTransform;

	gsGGJPanorama(void) {}
	gsGGJPanorama(gsGGJGame *game);
	virtual ~gsGGJPanorama(void);

	virtual void update();
	virtual void draw();
	
	void onCollision(gsGameObject *other, const gsCollisionInfo& info) {};
	void acelerate(void);
};

#endif