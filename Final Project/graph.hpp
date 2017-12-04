#include "adjacency_list_node.hpp"

struct AdjacencyList {
    AdjacencyListNode *head;
};

class Graph {
    public:
        Graph(int size);
        void add_edge(int source, int destination, int weight);
        void print();
        void print_adjacent_nodes(int id);
    private:
        int size;
        AdjacencyList vertex_list[100];
};
