#ifndef __GS_CLOCK__
#define __GS_CLOCK__

// Subsistema respons�vel pelo registro da passagem do tempo durante a execu��o
class gsClock {
public:
	// Inicializa o rel�gio
	static void init();

	// Atualiza o rel�gio para o tempo atual
	static void update();

	// Retorna o tempo total de execu��o do jogo desde que o rel�gio foi inicializado (em segundos)
	static double getTotalTime();
	// Retorna o tempo decorrido entre as duas �ltimas atualiza��es do rel�gio (em segundos)
	static double getDeltaTime();
};

#endif