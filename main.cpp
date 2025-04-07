//fikhman2005@gmail.com
#include "algos.hpp"
using namespace graph;
using namespace std;
#include <iostream>

int main(){

    Graph g = Graph(5);
    g.addEdge(0,1,1);
    g.addEdge(0,2,2);
    g.addEdge(1,2,3);
    g.addEdge(4,3,2);
    g.addEdge(4,2,1);
    g.addEdge(1,3,2);
    g.addEdge(0,4,2);

    cout<<"Graph1"<<endl;
    g.printGraph();


    GraphAlgorithms ga = GraphAlgorithms();


 

    cout<<"Graph2"<<endl;
    Graph g2 = ga.dfs(g,0);
    g2.printGraph();


    cout<<"Graph3"<<endl;
    Graph g3 = ga.bfs(g,0);
    g3.printGraph();
    

    cout<<"Graph4"<<endl;
    Graph g4 = ga.dijkstra(g,0);
    g4.printGraph();

    cout<<"Graph5"<<endl;
    Graph g5 = ga.prim(g);
    g5.printGraph();

    cout<<"Graph6"<<endl;
    Graph g6 = ga.kruskal(g);
    g6.printGraph();
    return 0;
}