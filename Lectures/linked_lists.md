#  Linked List

A node of items which contain a "tail" memory address refering to the head of the next item in the list
The first element is the "head" of the list, and is how the list is referenced in code (via a pointer to the head).
The final element in the list will contain a NULL tail element.

Insert: Adding an element
1. Obtain a new node from the system
2. Change the address in the tail of the item where you want to insert after to the memory address of the new node.

Delete: Removing an element
1. Change the tail to reference the element of the tail from the item to be removed.
2. Delete the node to free memory

# Doubly Linked List

A linked list which contains two memory addresses, one tail ('next') and one 'prev' which points to the previous element.
The final element will have an NULL tail element, and the first element in the list will have a NULL prev element

This list can be traversed backwards and forwards.

Insertion and deletion becomes slightly more complicated and each node will require twice as much memory as a singly linked list

Inserting at the Start:
Change the head to our new element. Change the 'prev' element of the old head  element to our new element's address. Set our new elements' 'prev' element to null

Inserting in the Middle:


Inserting at the End:


## Circular Linked List

A list where the final element in the list contains a 'next' pointer to the first element in the list
