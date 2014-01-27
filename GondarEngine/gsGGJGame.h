#ifndef __GS_GGJ_GAME__
#define __GS_GGJ_GAME__


#include "gsGame.h"
#include "gsGameObject.h"
#include "gsArrayList.h"

class gsGGJPlayer;
class gsGGJScore;

class gsGGJGame : public gsGame {
private:
	gsArrayList<gsGameObject*> objects;
	gsArrayList<gsGameObject*> objectsToBeRemoved;
	
public:
	gsGGJPlayer *player;
	gsGGJScore *scoreDisplay;

	virtual void start();
	virtual void end();

	virtual bool isRunning();

	virtual void update();
	virtual void draw();

	void addObjetToObjectsList(gsGameObject* object);
	void removeObjectFromObjectsList(gsGameObject *object);
};

#endif