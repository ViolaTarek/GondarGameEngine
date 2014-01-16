#ifndef __RANDOM__
#define __RANDOM__

class Random {
public:
	// Inicializa o gerador de n�meros aleat�rios
	static void init();

	// retorna um valor booleano aleat�rio
	static bool nextBool();
	// retorna um valor inteiro aleat�rio no intervalo [min, max]
	static int nextInt(int min, int max);
	// retorna um valor decimal aleat�rio entre 0 e 1
	static double nextDouble();

	// gera um valor de 0 a 100 e se esse valor for maior que "chance" retorna true
	static bool chance(int chance);
}

#endif