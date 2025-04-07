//fikhman2005@gmail.com
class Queue{
    public:
        Queue(int maxSize);
        ~Queue();
        void enqueue(int value);
        int dequeue();
        bool isEmpty();
    private:
        int* qArr;
        int front;
        int back;
        int CurrSize;
        int maxSize;
    
};
