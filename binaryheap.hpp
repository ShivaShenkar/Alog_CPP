//fikhman2005@gmail.com
class BinaryHeap{
    public:
        BinaryHeap(int capacity){
            this->heapKeys = new int[capacity];
            this->heapVertices = new int[capacity];
            this->capacity = capacity;
            this->currentSize = 0;
        }
        ~BinaryHeap(){
            delete[] heapKeys;
            delete[] heapVertices;
        }
        void insert(int key,int vertex){
            heapKeys[currentSize] = key;
            heapVertices[currentSize] = vertex;
            heapifyUp(currentSize);
            currentSize++;
        }
        int* extractMin();
        int getMin() const{
            return heapVertices[0];
        }
        bool isEmpty() const{
            return currentSize == 0;
        }
        int size() const{
            return currentSize;
        };
        void decreaseKey(int vertex,int newKey);
    private:
        void heapifyUp(int index);
        void heapifyDown(int index);
        void swap(int index1,int index2);
        int* heapVertices;
        int* heapKeys;
        int capacity;
        int currentSize;

        
};