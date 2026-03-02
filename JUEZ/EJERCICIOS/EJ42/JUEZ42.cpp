/*@ <authors>
 *
 * Diego Rodriguez Cubeo DG30
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>
#include <climits>

#include <stack>
#include <queue>
#include <deque>

#include <list>
#include <forward_list>

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <tuple>

using namespace std;

/*@ <answer>

   Escribe aquí un comentario general sobre la solución, explicando cómo
   se resuelve el problema y cuál es el coste de la solución, en función
   del tamaño del problema.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso()
{

    // leer los datos de la entrada
    int cant, longitud;
    cin >> cant >> longitud;

    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones

    vector<int> longitudes(cant), costes(cant);
    for (int i = 0; i < cant; ++i)
    {
        cin >> longitudes[i] >> costes[i];
    }

    vector<int> maneras(longitud + 1, 0);
    maneras[0] = 1;
    vector<int> minCostes(longitud + 1, INT_MAX);
    minCostes[0] = 0;
    vector<int> minCantidades(longitud + 1, INT_MAX);
    minCantidades[0] = 0;

    for (int i = 0; i < cant; ++i)
    {
        for (int j = longitud; j >= longitudes[i]; --j)
        {
            if (maneras[j - longitudes[i]] > 0)
            {
                maneras[j] += maneras[j - longitudes[i]];
                minCostes[j] = min(minCostes[j], minCostes[j - longitudes[i]] + costes[i]);
                minCantidades[j] = min(minCantidades[j], minCantidades[j - longitudes[i]] + 1);
            }
        }
    }

    // escribir la solución

    if (maneras[longitud] == 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "SI " << maneras[longitud] << " " << minCantidades[longitud] << " " << minCostes[longitud] << "\n";
    }

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

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
