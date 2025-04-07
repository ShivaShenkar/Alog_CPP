//fikhman2005@gmail.com
class Edge {
    public:
        Edge(int v, int u, int weight) : weight(weight) {
            vertices = new int[2];
            vertices[0] = v;
            vertices[1] = u;
        }
        
        // Copy constructor
        Edge(const Edge& other) : weight(other.weight) {
            if (other.vertices) {
                vertices = new int[2];
                vertices[0] = other.vertices[0];
                vertices[1] = other.vertices[1];
            } else {
                vertices = nullptr;
            }
        }
        
        // Assignment operator
        Edge& operator=(const Edge& other) {
            if (this != &other) {
                delete[] vertices;
                
                weight = other.weight;
                if (other.vertices) {
                    vertices = new int[2];
                    vertices[0] = other.vertices[0];
                    vertices[1] = other.vertices[1];
                } else {
                    vertices = nullptr;
                }
            }
            return *this;
        }
        
        Edge() : vertices(nullptr), weight(0) {}
        
        ~Edge() {
            delete[] vertices;
        }
        
        int getWeight() const { return weight; }
        void setWeight(int weight) { this->weight = weight; }
        int* getVertieces() const { return vertices; }
        int getv1() const { return vertices ? vertices[0] : -1; }
        int getv2() const { return vertices ? vertices[1] : -1; }
    
    private:
        int* vertices;
        int weight;
    };