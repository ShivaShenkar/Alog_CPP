//fikhman2005@gmail.com
#include "algos.hpp"
#include <string>
#include "queue.hpp"
#include "arraylist.hpp"
#include <climits>
#include "binaryheap.hpp"
#include <stdexcept>
#include "unionfind.hpp"

namespace graph
{


    GraphAlgorithms::GraphAlgorithms(){}


    //bfs algorithm on a graph and a start vertex
    //returns a graph with the edges of the bfs traversal
    Graph GraphAlgorithms::bfs(Graph& graph, const int startVertex) {
        if(startVertex < 0 || startVertex >= graph.getVertices()) {
            throw std::out_of_range("Start vertex out of range");
        }
        Graph result = Graph(graph.getVertices());
        int* color = new int[graph.getVertices()];
        for (int i = 0; i < graph.getVertices(); i++) {
            color[i] = 0; // 0: white, 1: gray, 2: black
        }
        color[startVertex] = 1;
        Queue q = Queue(graph.getVertices());
        q.enqueue(startVertex);
        while(!q.isEmpty()) {
            int u = q.dequeue();
            EdgeList adjList = graph.getAdjList(u); 
            for(int i = 0; i < adjList.getSize(); i++){
                int v = adjList.getEdgeByIndex(i).getv2();
                int weight = adjList.getEdgeByIndex(i).getWeight();
                if(color[v] == 0) {
                    color[v] = 1;
                    result.addEdge(u, v, weight);
                    q.enqueue(v);
                }
            }
            color[u] = 2;
        }
        delete[] color;
        return result;
    }
    //dfs algorithm on a graph and a start vertex
    Graph GraphAlgorithms::dfs(Graph& graph, const int startVertex) {
        if(startVertex < 0 || startVertex >= graph.getVertices()) {
            throw std::out_of_range("Start vertex out of range");
        }
        
        Graph result = Graph(graph.getVertices());
        int* color = new int[graph.getVertices()];
        int* discovery = new int[graph.getVertices()];
        int* finish = new int[graph.getVertices()];
        int time = 0;

        for (int i = 0; i < graph.getVertices(); i++) {
            color[i] = 0; // 0: white, 1: gray, 2: black
        }
        dfsVisit(graph, result, startVertex, color, discovery, finish, time);
        for (int i = 0; i < graph.getVertices(); i++) {
            if(color[i] == 0) {
                dfsVisit(graph, result, i, color, discovery, finish, time);
            }
        }
        delete[] discovery;
        delete[] finish;
        delete[] color;
        return result;
    }

    //dfsvisit algorithm
    void GraphAlgorithms::dfsVisit(Graph& graph, Graph& result, const int u, int*& color, int*& d, int*& f, int& time) {
        color[u] = 1;
        time++;
        d[u] = time;
        
        // The bug is here - you're using result's adjacency list but should use graph's
        EdgeList adjList = graph.getAdjList(u);
        for(int i = 0; i < adjList.getSize(); i++){
            int v = adjList.getEdgeByIndex(i).getv2();
            int weight = adjList.getEdgeByIndex(i).getWeight();
            if(color[v] == 0) {
                result.addEdge(u, v, weight);
                dfsVisit(graph, result, v, color, d, f, time);
            }
        }
        color[u] = 2;
        time++;
        f[u] = time;
    }

    Graph GraphAlgorithms::dijkstra(Graph& graph, const int startVertex) {
        if(startVertex < 0 || startVertex >= graph.getVertices()) {
            throw std::out_of_range("Start vertex out of range");
        }
        
        EdgeList edges = graph.getGraphEdgesSotred();
        if(edges.getSize() > 0 && edges.getEdgeByIndex(0).getWeight() < 0){
            throw std::invalid_argument("Graph contains negative weight edges");
        }
        
        Graph result = Graph(graph.getVertices());
        int* d = new int[graph.getVertices()];
        Edge* pi = new Edge[graph.getVertices()];
        
        for(int i = 0; i < graph.getVertices(); i++){
            d[i] = INT_MAX;
        }
        d[startVertex] = 0;
        
        BinaryHeap heap = BinaryHeap(graph.getVertices());
        for(int i = 0; i < graph.getVertices(); i++){
            heap.insert(d[i], i);
        }
        
        while(!heap.isEmpty()){
            int* min = heap.extractMin();
            int u = min[1];
            delete[] min;  // Add this to prevent memory leak
            
            EdgeList adjList = graph.getAdjList(u);
            for(int i = 0; i < adjList.getSize(); i++){
                Edge e = adjList.getEdgeByIndex(i);
                int v = e.getv2();
                int weight = e.getWeight();
                
                if(d[v] > d[u] + weight){
                    d[v] = d[u] + weight;
                    heap.decreaseKey(v, d[v]);
                    pi[v] = e;
                    result.addEdge(u, v, weight);
                }
            }
        }
        
        delete[] d;
        delete[] pi;
        return result;
    }

    Graph GraphAlgorithms::kruskal(Graph& graph) {
        Graph result = Graph(graph.getVertices());
        EdgeList edges = graph.getGraphEdgesSotred();

        UnionFind uf = UnionFind(graph.getVertices());
        
        for (int i = 0; i < edges.getSize(); i++) {
            Edge e = edges.getEdgeByIndex(i);
            int u = e.getv1();
            int v = e.getv2();
            int weight = e.getWeight();
            if (!uf.sameSet(u, v)) {
                result.addEdge(u, v, weight);
                uf.unionSets(u, v);
            }
        }
        
        return result;
    }

    Graph GraphAlgorithms::prim(Graph& graph) {
        Graph result = Graph(graph.getVertices());
        ArrayList visited = ArrayList();
        visited.add(0);
        ArrayList notVisited = ArrayList();
        
        for(int i = 1; i < graph.getVertices(); i++){
            notVisited.add(i);
        }
        
        EdgeList edges = graph.getGraphEdgesSotred();
        while(notVisited.size() > 0){
            bool edgeAdded = false;
            for(int i = 0; i < edges.getSize(); i++){
                Edge e = edges.getEdgeByIndex(i);
                int u = e.getv1();
                int v = e.getv2();
                bool uVisited = visited.contains(u);
                bool vVisited = visited.contains(v);
                
                if(uVisited && !vVisited){
                    result.addEdge(u, v, e.getWeight());
                    visited.add(v);
                    notVisited.remove(v);
                    edgeAdded = true;
                    break;
                } 
                else if(!uVisited && vVisited){
                    result.addEdge(u, v, e.getWeight());
                    visited.add(u);
                    notVisited.remove(u);
                    edgeAdded = true;
                    break;
                }
            }
            
            // Safety check to prevent infinite loop
            if(!edgeAdded && notVisited.size() > 0) {
                break;  // No edge could be added but vertices remain - graph is not connected
            }
        }
        
        return result;
    }
}