#ifndef __GS_WINDOW__
#define __GS_WINDOW__

// Foward Declaration: classe Janela do GLFW
struct GLFWwindow;

// Subsitema respons�vel pela cria��o e dealoca��o da janela
class gsWindow {
public:
	// Inicializa a janela com a resolu��o indicada
	static void init(int resX, int resY);
	// Libera os recursos utilizados pela janela
	static void dispose();

	// Retorna uma refer�ncia para a janela da aplica��o
	static GLFWwindow* getWindow();
};

#endif