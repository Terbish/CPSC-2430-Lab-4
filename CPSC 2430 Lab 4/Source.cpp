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

    void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }

    void percolateUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heapArr[index] < heapArr[parent]) {
                swap(heapArr[index], heapArr[parent]);
            }
            else {
                break;
            }
            index = parent;
        }
    }

    void percolateDown(int index) {
        while (index < size - 1) {
            int left_child_index = (2 * index) + 1;
            int right_child_index = (2 * index) + 2;
            if (left_child_index > size - 1) {
                break;
            }
            else if (right_child_index > size - 1) {
                if (heapArr[index] > heapArr[left_child_index]) {
                    swap(heapArr[index], heapArr[left_child_index]);
                    index = left_child_index;
                }
                else {
                    break;
                }
            }
            else {
                if (heapArr[right_child_index] < heapArr[left_child_index]) {
                    if (heapArr[index] > heapArr[right_child_index]) {
                        swap(heapArr[index], heapArr[right_child_index]);
                        index = right_child_index;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (heapArr[index] > heapArr[left_child_index]) {
                        swap(heapArr[index], heapArr[left_child_index]);
                        index = left_child_index;
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }

public:
    MinHeap() {
        size = 0;
    }
    void insert(int element) {
        if (size >= HEAP_MAX_SIZE) {
            cout << "HEAP IS FULL BRO!" << endl;
            return;
        }
        size++;
        heapArr[size - 1] = element;
        percolateUp(size - 1);
    }
    void deleteMin() {
        if (size == 0) {
            cout << "HEAP IS EMPTY BRO!" << endl;
            return;
        }
        heapArr[0] = heapArr[size - 1];
        size--;
        percolateDown(0);
    }

    int extractMin() {
        if (size == 0) {
            return -1;
        }
        return heapArr[0];
    }

    int heapSize() {
        return size;
    }

    void heapDisplay() {
        for (int i = 0; i < size; i++) {
            cout << heapArr[i] << " ";
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
