/*@ <authors>
 *
 * Diego Rodriguez Cubeo DG30
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*@ <answer>

	Para llegar de la esquina noroeste a la sureste sin caminar mas de lo
	imprescindible, en cada paso solo se puede avanzar hacia el sur o hacia
	el este.

	Definimos dp[i][j] como el numero de caminos minimos que llegan a la
	interseccion (i, j) evitando obras.

	Si (i, j) tiene obras, dp[i][j] = 0.
	En otro caso, los caminos que llegan son los que vienen de arriba y de la
	izquierda:
		dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

	Caso base: dp[0][0] = 1 (la esquina inicial nunca tiene obras).

	El resultado es dp[N - 1][M - 1].

	Coste temporal: O(N * M).
	Coste espacial: O(N * M).

 @ </answer> */

// ================================================================
// Escribe el codigo completo de tu solucion aqui debajo
// ================================================================
//@ <answer>

bool resuelveCaso()
{
	int n, m;
	cin >> n >> m;

	if (!cin)
	{
		return false;
	}

	vector<string> ciudad(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> ciudad[i];
	}

	vector<vector<long long>> dp(n, vector<long long>(m, 0));
	dp[0][0] = 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (ciudad[i][j] == 'X')
			{
				dp[i][j] = 0;
				continue;
			}

			if (i == 0 && j == 0)
			{
				continue;
			}

			if (i > 0)
			{
				dp[i][j] += dp[i - 1][j];
			}
			if (j > 0)
			{
				dp[i][j] += dp[i][j - 1];
			}
		}
	}

	cout << dp[n - 1][m - 1] << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta linea ya no forma parte de la solucion.

int main()
{
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso())
		;

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
