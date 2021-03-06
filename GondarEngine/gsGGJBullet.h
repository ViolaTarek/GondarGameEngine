#ifndef __GS_GGJ_BULLET__
#define __GS_GGJ_BULLET__


#include "gsSpriteSheet.h"
#include "gsGGJObject.h"
#include "gsGGJBulletType.h"

enum gsGGJPhase;

class gsGGJBullet : public gsGGJObject {
public:
	gsGGJBulletType bulletType;
	gsSpriteSheet *sprite;
	gsVector3 offset;
	float angle;
	gsGGJPhase phase;
	float damage;

	gsGGJBullet() {}
	gsGGJBullet(bool isPlayerBullet, gsGGJBulletType bulletType, gsTransform* shooterTransform, gsGGJGame *game, gsGGJPhase phase);
	virtual ~gsGGJBullet();

	void update();
	void draw();

	void doSpiral();
	void setUpSprite(bool isPlayerBullet);
	

	virtual void onCollision(gsGameObject *_other, const gsCollisionInfo& info);
};

#endif