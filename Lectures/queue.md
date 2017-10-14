# Queue

The queue is a **First In First Out** (FIFO) data structure
Contains a list, and two index variables "head" and "tail"

In  Queue      Out
--> ========== -->

### Operations
- Enqueue: Inserts an element to the "rear" of the queue
- Dequeue: Removes and returns the element at the start of the list


#### Implementation:
Can be implemented using either Array or Linked List structures

Array Implementation:
```
Create an array with a MAX number of items (the queues limit)
Create two position variables, _head_ and _tail_

When inserting elements, put the new element at the current tail position, then increment the tail position

When dequeueing elements, there are two options: Shifting or Change Head Position
Shifting: Remove the first element in the array and shift all remaining elements over by 1. This is SLOW.
Change Head Pos: Remove the first element in the array and increment 'head' by 1. This will cause the queue to fill up and possibly overflow.
```

Linked List:
Linked list implementation is more robust when dequeueing due to it's lack of need for a shifting and it's ability to expand or contract depending on what is being inserted and removed.
```
```
