// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
private:
    int* arr;
    int numelements;
    int size = 0;
    int frontindex = 0;
    int backindex = 0;

public:
    MyCircularQueue(int k) {
        arr = new int[k];
        numelements = k;
    }
    bool enQueue(int value) {
        if (size == numelements) {
            return false;
        }
        else if (backindex == numelements - 1 or size == 0) {
            backindex = 0;
            arr[backindex] = value;
            ++size;
            return true;
        } else {
            ++backindex;
            arr[backindex] = value;
            ++size;
            return true;
        }
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        } else if (frontindex == numelements - 1) {
            arr[frontindex] = 0;
            frontindex = 0;
            --size;
            return true;
        } else {
            arr[frontindex] = 0;
            ++frontindex;
            --size;
            return true;
        }

    }

    int Front() {
        if (isEmpty()) {
            return -1;
        } else {
            return arr[frontindex];
        }
  
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        } else {
            return arr[backindex];
        }
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        } else {
            return false;
        }

    }

    bool isFull() {
        if (size == numelements) {
            return true;
        } else {
            return false;
        }


    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */