#ifndef __GS_GGJ_ENEMY_SPAWNER__
#define __GS_GGJ_ENEMY_SPAWNER__


#include "gsGGJObject.h"


// Objeto invis�vel que deve de tempos em tempos criar um novo inimigo no topo da tela
class gsGGJEnemySpawner : public gsGGJObject 
{
private:
	float spawnCooldown;
	float spawnTimer;
public:
	gsGGJEnemySpawner() {}
	gsGGJEnemySpawner(gsGGJGame *game);
	virtual ~gsGGJEnemySpawner(){}

	void update();
	void draw();

	void onCollision(gsGameObject *_other, const gsCollisionInfo& info);
};

#endif