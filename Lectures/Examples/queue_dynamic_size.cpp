#include <iostream>

using namespace std;

const int MAX_SIZE = 5;
void enqueue(int item);
int dequeue();
int peek();
void print_queue();
bool is_full();
bool is_empty();
int queue[MAX_SIZE];
int head = 0;
int tail = 0;

int main() {
    enqueue(5);
    enqueue(3);
    enqueue(4);
    enqueue(2);
    enqueue(1);
    dequeue();
    enqueue(6);

    print_queue();
    return 0;
}

void enqueue(int item) {
    //Check for queue full-ness
    if(is_full()) {
        cout << "Cannot enqueue " << item << ". Queue full." << endl;
        return;
    }
    queue[tail] = item; //Insert item into the queue
    tail++;             //Increment the Tail index
}
int dequeue() {
    //Check for queue emptiness
    if(is_empty()) {
        cout << "Cannot dequeue. Queue is empty" << endl;
        return -1;
    }
    int value = queue[head];
    //Shift the queue elements over by 1 to fill in the dequeue'd space
    for(int i = head; i < tail; i++) {
        queue[i] = queue[i+1];
    }
    tail--;
    return value;
}

int peek() {
    if(is_empty()) {
        cout << "Cannot peek. Queue is empty" << endl;
        return -1;
    }
    return queue[head];
}

void print_queue() {
    cout << "Current queue: ";
    for(int i = head; i < tail; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

bool is_full() {
    if(tail == MAX_SIZE) {
        return true;
    } else {
        return false;
    }
}

bool is_empty() {
    if(head == tail) {
        return true;
    } else {
        return false;
    }
}
