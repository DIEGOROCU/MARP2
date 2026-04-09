/*@ <authors>
 *
 * Diego Rodriguez Cubeo DG30
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*@ <answer>

	Se plantea un cambio de moneda sin limite de usos de cada puntuacion:
	queremos sumar exactamente V minimizando el numero de dardos.

	Definimos dp[x] = minimo numero de dardos para conseguir x.
	Transicion (para cada x de 1..V y cada puntuacion p):
		si x >= p y dp[x - p] es alcanzable,
		dp[x] = min(dp[x], dp[x - p] + 1).

	Para reconstruir una solucion optima guardamos en usado[x] la puntuacion
	con la que se alcanza el mejor valor de dp[x]. Luego retrocedemos desde V
	restando usado[actual] hasta llegar a 0.

	Coste temporal: O(S * V), siendo S el numero de sectores y V el objetivo.
	Coste espacial: O(V).

 @ </answer> */

// ================================================================
// Escribe el codigo completo de tu solucion aqui debajo
// ================================================================
//@ <answer>

bool resuelveCaso()
{
	int valor, s;
	cin >> valor >> s;

	// fin de la entrada
	if (!cin)
	{
		return false;
	}

	vector<int> puntuaciones(s);
	for (int i = 0; i < s; ++i)
	{
		cin >> puntuaciones[i];
	}

	const int INF = INT_MAX / 4;
	vector<int> dp(valor + 1, INF);
	vector<int> usado(valor + 1, -1);
	dp[0] = 0;

	for (int x = 1; x <= valor; ++x)
	{
		for (int p : puntuaciones)
		{
			if (p > x)
			{
				break;
			}
			if (dp[x - p] + 1 < dp[x])
			{
				dp[x] = dp[x - p] + 1;
				usado[x] = p;
			}
		}
	}

	if (dp[valor] >= INF)
	{
		cout << "Imposible\n";
		return true;
	}

	vector<int> sol;
	int actual = valor;
	while (actual > 0)
	{
		int p = usado[actual];
		sol.push_back(p);
		actual -= p;
	}

	cout << dp[valor] << ":";
	for (int p : sol)
	{
		cout << " " << p;
	}
	cout << "\n";

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
