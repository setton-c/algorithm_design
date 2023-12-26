#include "src/graph.h"

int main() {
    weighted_graph g(false);

    /* graph number 1
    g.add_edge('a', 'b', 14);
    g.add_edge('a', 'd', 10);
    g.add_edge('b', 'c', 13);
    g.add_edge('b', 'e', 4);
    g.add_edge('d', 'c', 8);
    */

    // std::cout << "\nDepth-First search: ";
    // g.DFS('a');
    // std::cout << "\nBreadth-First search: ";
    // g.BFS('a');

    /* graph number 2 */
    g.add_edge('a', 'b', 4);
    g.add_edge('a', 'c', 4);
    g.add_edge('b', 'c', 2);
    g.add_edge('c', 'd', 3);
    g.add_edge('c', 'f', 4);
    g.add_edge('c', 'e', 2);
    g.add_edge('d', 'f', 3);
    g.add_edge('e', 'f', 3);

    g.print_graph();
    // g.kruskal();
    g.prim('a');
    // g.print_all_edge();
    // g.print_graph();
}
