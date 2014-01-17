#ifndef __GS_GLMAIN__
#define __GS_GLMAIN__

#include <stdlib.h>
#include <stdio.h>

#include "gsIncludeOpenGL.h"
#include "gsCamera.h"
#include "gsGeometric.h"
#include "gsInput.h"

bool rotation = false;
float ratio;
int width, height;
int windowPosX, windowPosY;

GLFWwindow* window;
gsCamera* camera;

Point3D* position;
Point3D* lookAt;
Point3D* up;

//Macros de inicializa��o
//Largura da tela, Altura da Tela, Posi��o X da Tela, Posi��o Y da Tela, Posi��o da C�mera, Dire��o da C�mera, Rota��o da C�mera, Instancia��o da C�mera, Chamada ao m�todo de inicializa��o da C�mera

//Macro de janela tamanho 640x480
#define INIT_640x480 width = 640; \
	height = 480; \
	windowPosX = 800; \
	windowPosY = 100; \
	position = new Point3D(1.0f, 3.0f, 12.0f);\
	lookAt = new Point3D(0.0f, 0.0f, 0.0f);\
	up = new Point3D(0.0f, 1.0f, 0.0f);\
	camera = new gsCamera(position, lookAt, up);\
	camera->initCamera(0.0f, 50.0f, 45.0f);

//Macro de janela tamanho 800x600
#define INIT_800x600 width = 800; \
	height = 600; \
	windowPosX = 800; \
	windowPosY = 100; \
	position = new Point3D(1.0f, 3.0f, 12.0f);\
	lookAt = new Point3D(0.0f, 0.0f, 0.0f);\
	up = new Point3D(0.0f, 1.0f, 0.0f);\
	camera = new Camera(position, lookAt, up);\
	camera->initCamera(0.0f, 50.0f, 45.0f);

//M�todo draw gen�rico da engine
static void draw(void)
{

}

//M�todo de update gen�rico da engine
static void update(void)
{

}

//Defini��o do modelo de ilumina��o da aplica��o
void setLightModel()
{
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20.0f);
}

//M�todo de inicializa��o do openGL
void glInitiate()
{

	//Setando o modelo de ilumina��o da janela
	setLightModel();
}

//Game Loop
void glLoop()
{
}
    
//M�todo de finaliza��o da engine
int glTerminate()
{
	return 0;
}

#endif