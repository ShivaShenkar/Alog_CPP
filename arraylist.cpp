//fikhman2005@gmail.com
#include <iostream>
#include "arraylist.hpp"

ArrayList::ArrayList() {
    arr = nullptr;
    length = 0;
}
ArrayList::~ArrayList() {
    delete[] arr;
}

void ArrayList::add(int value) {
    if(this->contains(value))
        return;
    int* newArr = new int[length + 1];
    for (int i = 0; i < length; i++) {
        newArr[i] = arr[i];
    }
    newArr[length] = value;
    delete[] arr;
    arr = newArr;
    length++;
}
void ArrayList::remove(int value) {
    for(int i = 0; i < length; i++) {
        if (arr[i] == value) {
            int* newArr = new int[length - 1];
            for (int j = 0; j < i; j++) {
                newArr[j] = arr[j];
            }
            for (int j = i + 1; j < length; j++) {
                newArr[j - 1] = arr[j];
            }
            delete[] arr;
            arr = newArr;
            length--;
            return;
        }
    }
}
int ArrayList::get(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}
int ArrayList::size() {
    return length;
}
bool ArrayList::contains(int value) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}