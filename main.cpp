#include "src/graph.h"

int main() {
    weighted_graph g(false); 
    
    g.add_edge('a', 'b', 14);
    g.add_edge('a', 'd', 10);
    g.add_edge('b', 'c', 13);
    g.add_edge('b', 'e', 4);
    g.add_edge('d', 'c', 8);

    // g.print_graph();
    // std::cout << "\nDepth-First search: ";
    // g.DFS('a');
    // std::cout << "\nBreadth-First search: ";
    // g.BFS('a');
    // 
    g.kruskal();
    // g.print_all_edge();
    // g.print_graph();
}
