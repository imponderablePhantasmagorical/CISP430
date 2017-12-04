//Implimentation of a graph used to track and store airport connections and distances

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

//Add an edge between our source and destination. The weight of the edge is equal to the distance between the nodes
void Graph::add_edge(int source, int destination, int weight) {
    //Create edges to and from our source and destination (non-directional)
    AdjacencyListNode* dest_to_src_node = new AdjacencyListNode(destination, weight);
    AdjacencyListNode* src_to_dest_node = new AdjacencyListNode(source, weight);

    //Set our nodes' next to their adjacency list's current head
    dest_to_src_node->next = vertex_list[source].head;
    src_to_dest_node->next = vertex_list[destination].head;

    //Make our new nodes the head of our lists, thus "pushing" it into their respective adjacency list 
    vertex_list[source].head = dest_to_src_node;
    vertex_list[destination].head = src_to_dest_node;
}

//Print the adjacency list
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

//Print all airports adjacent to our current node
void Graph::print_adjacent_airports(int node_id) {
    AdjacencyList list = vertex_list[node_id];
    AdjacencyListNode* head = list.head;

    //Print a header
    cout << "Airports adjacent to " << lookup_airport_name(node_id) << " (ID:" << node_id << ")" << endl;
    cout << "-------------------------------" << endl;
    //walk through our list
    while(head) {
        //Grab the ID of our destination
        int dest_id = head->get_destination();
        //Print the airport and it's distance from our source
        cout << "Airport: " << lookup_airport_name(dest_id) << " Distance: " << head->get_weight() << "mi" << endl;
        //Move the head up one
        head = head->next;
    }
    cout << "-------------------------------" << endl;
}

//Lookup and return an airport code as a string given a node ID
string Graph::lookup_airport_name(int node_id) {
    switch(node_id) {
        case 0:
            return "SAC"; //Sacramento
        case 1:
            return "LAS"; //Las Vegas
        case 2:
            return "LAX"; //Los Angeles
        case 3:
            return "DFW"; //Dallas Fort Worth
        case 4:
            return "ATL"; //Atlanta
        case 5:
            return "ORD"; //Chicago
        default:
            return "Unkwn"; //If not found, print unknown
    }
}

