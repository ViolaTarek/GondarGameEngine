#include "gsGGJFractalis.h"

#include "gsGGJBullet.h"
#include "gsSystem.h"
#include "gsGGJPlayer.h"
#include "gsGGJHealth.h"

gsGGJFractalis::gsGGJFractalis(gsGGJGame *game) : gsGGJEnemy(game){

	tag = gsGGJTag::Enemy;

	setupSpritesheet();

	hp = ENEMY_FRACTALIS_HEALTH;
	maxHp = hp;
	burstWaitCooldown = ENEMY_FRACTALIS_BURSTWAITCOOLDOWN;
	burstWaitTime = ENEMY_FRACTALIS_BURSTWAITTIME;
	cooldown = ENEMY_FRACTALIS_COOLDOWN;
	cooldownTime = ENEMY_FRACTALIS_COOLDOWNTIME;
	waiting = ENEMY_FRACTALIS_WAITING;
	multishot = 0;
	//Alterar valores do transform
	gsVector3 size = gsVector3(61, 56, 0);
	gsVector3 speed = gsVector3(gsRandom::nextInt(-50, 50), gsRandom::nextInt(30, 50), 0);
	gsColor color = gsColor::white(1.f);

	transform = gsTransform(transform.position, size, gsVector3::zero(), speed, color);

	collisionMask = 0x01;

	if (gsGGJGlobal_PhasesAvaiable != 1) {
		gsGGJPhase playerPhase = game->player->phase;
		int phaseId = gsRandom::nextInt(1, gsGGJGlobal_PhasesAvaiable);
		switch (phaseId) {
			case 1: phase = gsGGJPhase::RedPhase; break;
			case 2: phase = gsGGJPhase::GreenPhase; break;
			case 3: phase = gsGGJPhase::BluePhase; break;
			case 4: phase = gsGGJPhase::YellowPhase; break;
			case 5: phase = gsGGJPhase::MagentaPhase; break;
		}
	} else {
		phase = gsGGJPhase::RedPhase;
	}

	if (phase == gsGGJPhase::RedPhase) transform.tint = PHASE_RED_COLOR;
	else if (phase == gsGGJPhase::GreenPhase) transform.tint = PHASE_GREEN_COLOR;
	else if (phase == gsGGJPhase::BluePhase) transform.tint = PHASE_BLUE_COLOR;
	else if (phase == gsGGJPhase::YellowPhase) transform.tint = PHASE_YELLOW_COLOR;
	else if (phase == gsGGJPhase::MagentaPhase) transform.tint = PHASE_MAGENTA_COLOR;

	solid = false;
	this->bulletType = gsGGJBulletType::Spiral;

	transform.size *= sizeFactor;
	transform.speed *= speedFactor;

	healthBar = new gsGGJHealth(game, this);
	game->addObjetToObjectsList(healthBar);
}

void gsGGJFractalis::update(){
	gsGGJEnemy::update();

	multishot += gsClock::getDeltaTime()*0.2f;
	if (multishot >= 0.8f)
	{
		int spd = 200;
		
		gsGGJBullet *bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
		bullet->transform.speed.x = -1 * spd / 2;
		bullet->transform.speed.y = -1 * spd / 2;
		bullet->bulletType = gsGGJBulletType::Normal;
		game->addObjetToObjectsList(bullet);

		bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
		bullet->transform.speed.x = -1 * spd / 2;
		bullet->transform.speed.y = 1 * spd / 2;
		bullet->bulletType = gsGGJBulletType::Normal;
		game->addObjetToObjectsList(bullet);

		bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
		bullet->transform.speed.x = 1 * spd / 2;
		bullet->transform.speed.y = -1 * spd / 2;
		bullet->bulletType = gsGGJBulletType::Normal;
		game->addObjetToObjectsList(bullet);

		bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
		bullet->transform.speed.x = 1 * spd / 2;
		bullet->transform.speed.y = 1 * spd / 2;
		bullet->bulletType = gsGGJBulletType::Normal;
		game->addObjetToObjectsList(bullet);

		multishot -= multishot;
	}

}

void gsGGJFractalis::setupSpritesheet()
{
	sprite = new gsSpriteSheet("GGJ/fractalis.png", "enemy", 1, 1);
	int keyCount = 1;
	int *keyframes = new int[keyCount];
	for (int i = 0; i < keyCount; i++)
	{
		keyframes[i] = i;
	}
	gsAnimationClip *clip = new gsAnimationClip("FractalisClip", keyframes, keyCount, 0.4f);
	sprite->addAnimation(clip);
	sprite->setAnimation("FractalisClip");
}

