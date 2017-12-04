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
    //Create edges to and from our source and destination (non-directional)
    AdjacencyListNode* dest_to_src_node = new AdjacencyListNode(destination, weight);
    AdjacencyListNode* src_to_dest_node = new AdjacencyListNode(source, weight);

    //Set our nodes' next to the adjacency list's current head
    dest_to_src_node->next = vertex_list[source].head;
    src_to_dest_node->next = vertex_list[destination].head;

    //Make our new nodes the head of our lists, thus "pushing" it into their respective adjacency list 
    vertex_list[source].head = dest_to_src_node;
    vertex_list[destination].head = src_to_dest_node;
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

void Graph::print_adjacent_nodes(int node_id) {
    AdjacencyList list = vertex_list[node_id];
    AdjacencyListNode* head = list.head;
    while(head) {
        cout << head->get_destination() << ":" << head->get_weight() << endl;
        head = head->next;
    }
}
