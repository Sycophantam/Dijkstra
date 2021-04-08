#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int main() {

    Graph g;

    cout << "Dijkstra's algorithm" << endl;
    g.Dijkstra();
    cout << endl;

    cout << "Prim's algorithm" << endl;
    g.Prim(0);
    cout << endl;

    cout << "Kruskal's algorithm" << endl;
    g.Kruskal();
    return 0;
}
