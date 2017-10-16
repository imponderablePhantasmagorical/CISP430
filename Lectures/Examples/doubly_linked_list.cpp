#include <iostream>

using namespace std;

void insert(int index, int data);

struct Node {
    struct Node* prev;
    struct Node* next;
    int data;
};

int main() {
    Node* dbl_linked_list;
    //Generate our starting list.
    insert(0, 50);
    insert(1, 55);
    return 0;
}

void insert(Node* head, int index, int data) {
    //Create our new node for insertion
    Node* new_node = new Node;
    new_node->data = data;

    Node* current_node;
    //If the element is going at the front:
    if(index == 0) {
        new_node->next = NULL;
        current_node = new_node;
    }

    //If the element is going somewhere in the middle
    int counter = 0;
    do {
        current_node = current_node->next;
        counter++;
    } while(counter < index && current_node->next != NULL);

    //The 'next' element because our new node
    current_node->next = new_node;
    //The 'next' element of our new node becomes the old 'next' element
    new_node->next = current_node->next;
}
