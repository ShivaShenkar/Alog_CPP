//fikhman2005@gmail.com
#include "edge-list.hpp"
#include <stdexcept>

EdgeList::EdgeList() {
    this->arrList = nullptr;
    this->edges = 0;
    v = -1;
}

EdgeList::~EdgeList() {
    delete[] arrList;
    arrList = nullptr;
}

// Copy constructor implementation
EdgeList::EdgeList(const EdgeList& other) {
    v = other.v;
    edges = other.edges;
    
    if (other.edges > 0 && other.arrList != nullptr) {
        arrList = new Edge[edges];
        for (int i = 0; i < edges; i++) {
            arrList[i] = other.arrList[i];
        }
    } else {
        arrList = nullptr;
    }
}

// Assignment operator implementation
EdgeList& EdgeList::operator=(const EdgeList& other) {
    if (this != &other) {
        delete[] arrList;
        
        v = other.v;
        edges = other.edges;
        
        if (other.edges > 0 && other.arrList != nullptr) {
            arrList = new Edge[edges];
            for (int i = 0; i < edges; i++) {
                arrList[i] = other.arrList[i];
            }
        } else {
            arrList = nullptr;
        }
    }
    return *this;
}

void EdgeList::push(int u, int weight) {
    if (u == v || u < 0 || this->getIndexByVertex(u) != -1)
        return;
        
    Edge* newarrList = new Edge[edges + 1];
    for (int i = 0; i < edges; i++) {
        newarrList[i] = arrList[i];
    }
    
    newarrList[edges] = Edge(v, u, weight);
    
    delete[] arrList;
    arrList = newarrList;
    edges++;
}

void EdgeList::push(const Edge& e) {
    Edge* newarrList = new Edge[edges + 1];
    for (int i = 0; i < edges; i++) {
        newarrList[i] = arrList[i];
    }
    
    newarrList[edges] = e;
    
    delete[] arrList;
    arrList = newarrList;
    edges++;
}

void EdgeList::pop(int u) {
    int index = this->getIndexByVertex(u);
    if (u == v || u < 0 || index == -1)
        throw std::invalid_argument("Vertex not found");
        
    if (edges <= 1) {
        delete[] arrList;
        arrList = nullptr;
        edges = 0;
        return;
    }
    
    Edge* newarrList = new Edge[edges - 1];
    
    // Copy elements before index
    for (int i = 0; i < index; i++) {
        newarrList[i] = arrList[i];
    }
    
    // Copy elements after index
    for (int i = index + 1; i < edges; i++) {
        newarrList[i - 1] = arrList[i];
    }
    
    delete[] arrList;
    arrList = newarrList;
    edges--;
}

Edge EdgeList::getEdgeByIndex(int index) const {
    if (index < 0 || index >= edges) {
        throw std::out_of_range("Index out of range");
    }
    return arrList[index];
}

int EdgeList::getIndexByVertex(int u) const {
    if (u == v || u < 0) 
        return -1;
        
    for (int i = 0; i < edges; i++) {
        int* verts = arrList[i].getVertieces();
        if (verts) {
            if (verts[0] == u || verts[1] == u)
                return i;
        }
    }
    return -1;
}

void EdgeList::sortEdges() {
    for (int i = 0; i < edges - 1; i++) {
        for (int j = 0; j < edges - i - 1; j++) {
            if (arrList[j].getWeight() > arrList[j + 1].getWeight()) {
                Edge temp = arrList[j];
                arrList[j] = arrList[j + 1];
                arrList[j + 1] = temp;
            }
        }
    }
}