#include "graph.hpp"

int main() {
    const int size = 5;
    Graph graph(size);

    //Populate the graph with test values
    graph.add_edge(0, 1, 25);
    graph.add_edge(0, 4, 30);
    graph.add_edge(1, 2, 50);
    graph.add_edge(1, 3, 75);
    graph.add_edge(1, 4, 1);
    graph.add_edge(2, 3, 100);
    graph.add_edge(3, 4, 50);
 
    graph.print();
 
    return 0;
}