#include <iostream>

using namespace std;

//Priority Queue specific functions
struct Item {
    int item;
    int priority;
};
void insert(int item, int priority); //Insert an item into the queue
Item get_highest_priority();         //Returns the highest priority item
void delete_highest_priority();     //Removes the highest priority item

//Regular queue functions
const int MAX_SIZE = 25;
void print_queue();
bool is_full();
bool is_empty();
Item queue[MAX_SIZE];
int head = 0;
int tail = 0;


int main() {
    int choice;
    do {
        cout << "1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch(choice) {
            case(1):
                int item,
                    priority;
                cout << "Enter a value: ";
                cin >> item;
                cout << "Enter a priority: ";
                cin >> priority;
                insert(item,priority);
                break;
            case(2):
                delete_highest_priority();
                break;
            case(3):
                print_queue();
                break;
            case(5):
                cout << get_highest_priority().item << endl;
                break;
            case(4):
                break;
        }
    } while(choice != 4);

    print_queue();
    return 0;
}

/*void enqueue(int item) {
    //Check for queue full-ness
    if(is_full()) {
        cout << "Cannot enqueue " << item << ". Queue full." << endl;
        return;
    }
    queue[tail] = item; //Insert item into the queue
    tail++;             //Increment the Tail index
}*/

/*int dequeue() {
    //Check for queue emptiness
    if(is_empty()) {
        cout << "Cannot dequeue. Queue is empty" << endl;
        return -1;
    }
    int value = queue[head].item;
    head++;
    return value;
}*/

int peek() {
    if(is_empty()) {
        cout << "Cannot peek. Queue is empty" << endl;
        return -1;
    }
    return queue[head].item;
}

void print_queue() {
    cout << "Current queue: ";
    for(int i = head; i < tail; i++) {
        cout << queue[i].item << " ";
    }
    cout << endl << endl;
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

void insert(int item, int priority) {
    //Check for queue full-ness
    if(is_full()) {
        cout << "Cannot enqueue " << item << ". Queue full." << endl;
        return;
    }
    Item item_structure;
    item_structure.item = item;
    item_structure.priority = priority;
    queue[tail] = item_structure; //Insert item into the queue
    tail++;             //Increment the Tail index
}

Item get_highest_priority() {
    Item highest_priority_item = queue[head];

    //Iterate through our queue
    for(int i = head; i < tail; i++) {
        //If a higher priority exists, set it as our variables
        if(queue[i].priority > highest_priority_item.priority) {
            highest_priority_item = queue[i];
        }
    }
    return highest_priority_item;
}

void delete_highest_priority() {
    int highest_index = 0;

    //Iterate through our queue
    for(int i = head; i < tail; i++) {
        //If a higher priority exists, set it as our variables
        if(queue[i].priority > queue[highest_index].priority) {
            highest_index = i;
        }
    }

    //If a priority item is found, delete and reshift the array
    for(int j = highest_index; j < tail; j++) {
        queue[j] = queue[j+1];
    }
    tail--;
}
