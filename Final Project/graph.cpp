#include <iostream>
#include "graph.hpp"

using std::cout;
using std::endl;

//Ctor
Graph::Graph(int size) {
    //Initialize size
    this->size = size;
 
     // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < size; ++i) {
        vertex_list[i].head = nullptr;
    }
}

void Graph::add_edge(int source, int destination, int weight) {
    //Create the new node
    AdjacencyListNode* new_node = new AdjacencyListNode(destination, weight);

    //Set our new node's next to the list's current head
    new_node->next = vertex_list[source].head;

    //Make our new node the head of our list, thus "pushing" it into the array
    vertex_list[source].head = new_node;
}

void Graph::print() {
    for (int i = 0; i < this->size; ++i) {
        //Get the head node of current vertex's adjacency list
        AdjacencyListNode* curr_vertex = vertex_list[i].head;
        cout << "Vertex: " << i << endl;
        //Iterate until we find a null 'next' indicating the end of our Adjacency List
        while (curr_vertex) {
            //Print the destination
            cout << curr_vertex->get_destination() << ":" << curr_vertex->get_weight() << ",";
            curr_vertex = curr_vertex->next;
        }
        cout << endl;
    }
}
