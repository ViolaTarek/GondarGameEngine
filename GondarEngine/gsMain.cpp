#include "glMain.h"

//M�todo principal do jogo
int main()
{
	//Macro de inicializa��o de vari�veis. Esse macro inicializa os valores das vari�veis principais do tamanho de janela e posicionamento inicial da c�mera do OpenGL
	INIT_640x480

	//M�todo de inicializa��o do openGL
	glInitiate();

	//In�cio do game loop
	glLoop();

	//Finaliza a aplica��o
	return glTerminate();
}