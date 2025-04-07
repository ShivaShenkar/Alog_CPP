//fikhman2005@gmail.com
class ArrayList{
    public:
        ArrayList();
        ~ArrayList();
        void add(int value);
        void remove(int index);
        int get(int index);
        int size();
        bool contains(int value);
    private:
        int* arr;
        int length;
};