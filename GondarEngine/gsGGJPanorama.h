#ifndef __GS_GGJ_PANORAMA__
#define __GS_GGJ_PANORAMA__

#include "gsGGJObject.h"

class gsSpriteSheet;

class gsGGJPanorama : public gsGGJObject {
public:
	float speedFactor;
	gsSpriteSheet *sprite;

	gsGGJPanorama() {}
	gsGGJPanorama(gsGGJGame *game);
	virtual ~gsGGJPanorama() {}

	virtual void update();
	virtual void draw();
	
	void onCollision(gsGameObject *other, const gsCollisionInfo& info);
};

#endif