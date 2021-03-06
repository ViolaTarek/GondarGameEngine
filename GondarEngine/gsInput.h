#ifndef __GS_INPUT__
#define __GS_INPUT__


#include "GLFW\glfw3.h"

enum gsKeyState {
	Released, 
	Pressed, 
	JustReleased, 
	JustPressed
};

class gsInput {
public:
	static void init();

	static void update();

	// queryKey(GLFW_KEY_SPACE) == gsKeyState::Pressed;
	static gsKeyState queryKey(int keyCode);
};

#endif