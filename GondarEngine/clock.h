#ifndef __CLOCK__
#define __CLOCK__

class Clock {
public:
	// Inicializa o rel�gio
	static void init();

	// Atualiza o rel�gio para o tempo atual
	static void update();

	// Retorna o tempo total de execu��o do jogo desde que o rel�gio foi inicializado
	static double getTotalTime();
	// Retorna o tempo decorrido entre as duas �ltimas atualiza��es do rel�gio
	static double getDeltaTime();
}

#endif