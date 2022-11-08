/*
** Min-Heap construction and basic operations
** Lab 4, CPSC 2430, Xin Zhao
*/

// define the max size for the heap array 
#include <iostream>
using namespace std;

const int HEAP_MAX_SIZE = 1000;

class MinHeap {
private:
    int heapArr[HEAP_MAX_SIZE];
    int size;

    void swap(int &x, int &y) {
        // add your code here
        int temp = x;
        x = y;
        y = temp;
    }

    void percolateUp(int index) {
        // add your code here
        while (index>0)
        {
            int parent = (index - 1) / 2;
            if (heapArr[index] < heapArr[parent])
            {
                swap(heapArr[index], heapArr[parent]);
            }
            index = parent;
        }

    }

    void percolateDown(int index) {
        // add your code here
        int leftChild = (index * 2) + 1;
        int rightChild = (index * 2) + 2;
        if (rightChild < size)
        {
            int rightVal = heapArr[rightChild];
            int leftVal = heapArr[leftChild];
            if (heapArr[index] > rightVal && rightVal < leftVal)
            {
                swap(heapArr[index], heapArr[rightChild]);
                index = rightChild;
            }
            else if (heapArr[index] > leftVal && leftVal < rightVal)
            {
                swap(heapArr[index], heapArr[leftChild]);
                index = leftChild;
            }
        }
        else if (rightChild > size - 1 && heapArr[leftChild] < heapArr[index])
        {
            swap(heapArr[index], heapArr[leftChild]);
            percolateDown(leftChild);
        }
    }

public:
    MinHeap() { size = -1; }
    void insert(int element) {
        // add your code here
        if (size >= HEAP_MAX_SIZE)
        {
            cout << "Heap is full" << endl;
            return;
        }
        if (size < 0)
        {
            size++;
        }
        size++;
        heapArr[size - 1] = element;
        percolateUp(size - 1);
    }
    void deleteMin() {
        // add your code here
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        heapArr[0] = heapArr[size - 1];
        size--;
        percolateDown(0);
    }

    int extractMin() {
        // add your code here
        if (size == 0)
        {
            return -1;
        }
        return heapArr[0];
    }

    int heapSize() {
        // add your code here

        return size;
    }

    void heapDisplay() {
        // add your code here
        for (int i = 0; i < size; i++)
        {
            cout << heapArr[i]<< " ";
        }
        cout << endl;
    }

};

// in your main function, test your implementations. For example,  
int main() {

    MinHeap mh;
    mh.insert(4);
    mh.insert(8);
    mh.insert(1);
    mh.insert(7);
    mh.insert(3);

    // display heap
    mh.heapDisplay();  // the output should be: 1, 3, 4, 8, 7

    // deleteMin
    mh.deleteMin();
    mh.heapDisplay();  // the output should be: 3, 7, 4, 8

    // extractMin
    cout << mh.extractMin() << endl;   // the output should be: 3

    // heapSize
    cout << mh.heapSize() << endl;   // the output should be: 4
    return 0;
}