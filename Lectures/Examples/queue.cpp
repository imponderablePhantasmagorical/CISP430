#include <iostream>

using namespace std;

const int MAX_SIZE = 25;
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
    cout << "Negative numbers quit the program" << endl;
    do {
        int input = 0;
        cout << "Number to enqueue: ";
        cin >> input;
        //Check for the exit condition
        if(input == -1) {
            break;
        }
        //Enqueue the input
        enqueue(input);
    } while(!is_full());

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
    head++;
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
