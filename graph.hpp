//fikhman2005@gmail.com
#include "edge-list.hpp"
namespace graph
{
    //class for Graph instance
    //contains adjacency list and number of vertices
    class Graph {
        public:
            Graph(int vertices);
            ~Graph();
            void addEdge(int u, int v,int weight);
            void removeEdge(int u, int v);
            void printGraph();
            int getVertices() const { return vertices; }
            EdgeList getAdjList(int v);
            EdgeList getGraphEdgesSotred();
        private:
            int vertices;
            EdgeList* adjList;
    };
} 
