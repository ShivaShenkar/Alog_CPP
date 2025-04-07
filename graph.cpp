//fikhman2005@gmail.com
#include <stdexcept>
#include <iostream>
#include "graph.hpp"
using namespace std;

    
    namespace graph
    {
        // Constructor for Graph class
        Graph::Graph(int vertices) {
            if (vertices <= 0) {
                throw std::invalid_argument("Number of vertices must be positive");
            }
            this->vertices = vertices;
            adjList = new EdgeList[vertices];
            for (int i = 0; i < vertices; i++) {
                adjList[i] = EdgeList();
                adjList[i].setV(i);
            }
        }

        // Destructor for Graph class
        // Cleans up the adjacency list
        Graph::~Graph() {
            delete[] adjList;
        }
        
        // Adds an edge to the graph
        // Throws exceptions for invalid vertices or self-loops
        // Also adds the edge in both directions (u to v and v to u)
        void Graph::addEdge(int u, int v,int weight) {
            if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
                throw std::out_of_range("Vertex out of range");
            }
            if (u == v) {
                throw std::invalid_argument("Self-loops are not allowed");
            }
            
            adjList[u].push(v, weight);
            adjList[v].push(u, weight);
        }

        // Removes an edge from the graph
        // Throws exceptions for invalid vertices or self-loops
        void Graph::removeEdge(int u, int v) {
            if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
                throw std::out_of_range("Vertex out of range");
            }
            if (u == v) {
                throw std::invalid_argument("Self-loops are not allowed");
            }
            adjList[u].pop(v);
            adjList[v].pop(u); 
        }

        // Returns the adjacency list for a given vertex
        // Throws exceptions for invalid vertices
        EdgeList Graph::getAdjList(int u) {
            if(u < 0 || u >= vertices) {
                throw std::out_of_range("Vertex out of range");
            }
            return adjList[u];
        }

        //returns the edges of the graph in a sorted ascending order by weight
        EdgeList Graph::getGraphEdgesSotred() {
            EdgeList edges;
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < adjList[i].getSize(); j++) {    
                    Edge edge = adjList[i].getEdgeByIndex(j);
                    if (edge.getv2() > i) {
                        edges.push(edge);
                    }
                }
            }
            edges.sortEdges();
            return edges;
        }
        
        // Prints the graph in a readable format
        // Displays vertices and edges
        void Graph::printGraph() {
            cout<< "Printing Graph:" << endl;
            cout<<"Vertices: ";
            for(int i = 0; i < vertices; i++) {
                cout << "("<<i<<")" << " ";
            }
            cout << endl;
            cout << "Edges: " << endl;
            EdgeList edges = getGraphEdgesSotred();
            for (int i = 0; i < edges.getSize(); i++) {
                Edge e = edges.getEdgeByIndex(i);
                cout << "(v1: " << e.getv1() << ", v2: " << e.getv2() <<", weight: "<<e.getWeight()<< ") ";
            }
            cout << endl;
            cout << endl;
        }
  
        
    } 
    
   

    
    
    

    
    
