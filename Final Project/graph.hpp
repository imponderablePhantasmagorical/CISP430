#include "adjacency_list_node.hpp"
#include <string>

using std::string;

//For readabilities sake
struct AdjacencyList {
    AdjacencyListNode *head;
};

class Graph {
    public:
        Graph(int size);
        void add_edge(int source, int destination, int weight);
        void print();
        void print_adjacent_airports(int id);
    private:
        int size;
        AdjacencyList vertex_list[100];
        string lookup_airport_name(int id);
};
