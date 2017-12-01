#include "adjacency_list_node.hpp"

//Ctor
AdjacencyListNode::AdjacencyListNode(int destination, int weight) {
    this->destination = destination;
    this->weight = weight;
    this->next = nullptr;
}

int AdjacencyListNode::get_destination() {
    return destination;
}

int AdjacencyListNode::get_weight() {
    return weight;
}

