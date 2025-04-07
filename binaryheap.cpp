//fikhman2005@gmail.com
#include "binaryheap.hpp"
void BinaryHeap::heapifyUp(int index){
    while(index>0){
        int parentIndex = (index-1)/2;
        if(heapKeys[index]<heapKeys[parentIndex]){
            swap(index, parentIndex);
            index = parentIndex;
        }
        else
            break;
    }
}


void BinaryHeap::heapifyDown(int index){
    int left,right,smallest;
    while(index<currentSize){
        left = 2*index+1;
        right = 2 * index + 2;
        smallest = index;
        if (left < currentSize && heapKeys[left] < heapKeys[smallest])
            smallest = left;
        if (right < currentSize && heapKeys[right] < heapKeys[smallest])
            smallest = right;
        if(smallest!=index)
            swap(index,smallest);
        else
            break;
    }
}
void BinaryHeap::swap(int index1,int index2){
    int tempVertex = heapVertices[index1];
    int tempKey = heapKeys[index1];
    heapKeys[index1] = heapKeys[index2];
    heapVertices[index1] = heapVertices[index2];
    heapVertices[index2] = tempVertex;
    heapKeys[index2] = tempKey;
   
}
int* BinaryHeap::extractMin(){
    if(currentSize==0)
        return nullptr;
    int* result = new int[2];
    result[0] = heapKeys[0];
    result[1] = heapVertices[0];
    heapKeys[0] = heapKeys[currentSize-1];
    heapVertices[0] = heapVertices[currentSize-1];
    currentSize--;
    heapifyDown(0);
    return result;
}

void BinaryHeap::decreaseKey(int vertex,int newKey){
    for(int i=0;i<currentSize;i++){
        if(heapVertices[i]==vertex){
            heapKeys[i] = newKey;
            heapifyUp(i);
            break;
        }
    }
}