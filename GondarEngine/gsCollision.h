#ifndef __GS_COLLISION__
#define __GS_COLLISION__


#include "gsCollisionInfo.h"
#include "gsCollisionProxy.h"
#include "gsGameObject.h"
#include "gsArrayList.h"


// Classe que representa a posi��o, o tamanho e a orienta��o de um objeto do jogo.
class gsCollision  {
private:
	static void dispatchPair(const gsCollisionProxy& p1, const gsCollisionProxy& p2);

public:
	static void detectCollisions(gsArrayList<gsGameObject*>* objects);
};

#endif