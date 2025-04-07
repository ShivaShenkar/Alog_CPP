//fikhman2005@gmail.com
#include "graph.hpp"

namespace graph
{
    class GraphAlgorithms{
        public:
            GraphAlgorithms();
            static Graph dfs(Graph& graph, const int startVertex);
            static Graph bfs(Graph& graph, const int startVertex);
            static Graph dijkstra(Graph& graph, const int startVertex);
            static Graph kruskal(Graph& graph);
            static Graph prim(Graph& graph);
            
        private:
            static void dfsVisit(Graph& graph,Graph& result, const int u, int*& color,int*& d,int*& f,int& time);
            

    };
    
}