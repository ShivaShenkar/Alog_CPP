//fikhman2005@gmail.com
#include "edge.hpp"
class EdgeList {
public:
    EdgeList();
    void setV(int v) {
        this->v = v;
    }
    int getV() const {
        return v;
    }
    ~EdgeList();
    
    // Copy constructor
    EdgeList(const EdgeList& other);
    // Assignment operator
    EdgeList& operator=(const EdgeList& other);
    
    void push(int u, int weight);
    void push(const Edge& e);
    void pop(int u);
    Edge getEdgeByIndex(int index) const;
    int getIndexByVertex(int u) const;
    int getSize() const {
        return edges;
    }
    void sortEdges();
    Edge* arrList;
private:
    int v;
    int edges;
};