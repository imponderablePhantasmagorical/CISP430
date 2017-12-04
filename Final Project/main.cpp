#include "graph.hpp"

int main() {
    //Number of cities to list
    const int size = 5;
    //Initialize the graph
    Graph graph(size);

    //Populate the graph with test values
    graph.add_edge( 0, 2, 500);
    graph.add_edge( 0, 7, 400);
    graph.add_edge( 0, 1,650);
    graph.add_edge( 1, 6, 510);
    graph.add_edge( 1, 4, 600);
    graph.add_edge( 1, 5, 330);
    graph.add_edge( 1, 7, 260);
    graph.add_edge( 2, 8, 150);
    graph.add_edge( 2, 3, 340);
    graph.add_edge( 2, 7, 760);
    graph.add_edge( 3, 8, 400);
    graph.add_edge( 3, 7, 520);
    graph.add_edge( 3, 6, 290);
    graph.add_edge( 4, 6, 390);
    graph.add_edge( 4, 5, 350);
    graph.add_edge( 6, 7, 370);
    graph.add_edge( 6, 5, 490);
    
    //Print nodes adjacent to Sacramento
    graph.print_adjacent_airports(0);

    //Print nodes adjacent to Las Vegas
    graph.print_adjacent_airports(1);
    
 
    return 0;
}
