#include "src/graph.h"

int main() {
    weighted_graph g(true);

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
    // g.add_edge('a', 'b', 4);
    // g.add_edge('a', 'c', 4);
    // g.add_edge('b', 'c', 2);
    // g.add_edge('c', 'd', 3);
    // g.add_edge('c', 'f', 6);
    // g.add_edge('c', 'e', 2);
    // g.add_edge('d', 'f', 3);
    // g.add_edge('e', 'f', 3);
    //
    
    // g.add_edge('a', 'b', 4);
    // g.add_edge('a', 'c', 2);
    // g.add_edge('b', 'c', 3);
    // g.add_edge('c', 'b', 1);
    // g.add_edge('b', 'd', 2);
    // g.add_edge('b', 'e', 3);
    // g.add_edge('c', 'd', 4);
    // g.add_edge('c', 'e', 5);
    // g.add_edge('e', 'd', -5);
    //
    
    g.add_edge('0', '1', 5);
    g.add_edge('1', '2', 20);
    g.add_edge('2', '3', 10);
    g.add_edge('3', '2', -15);
    g.add_edge('2', '4', 75);
    g.add_edge('4', '9', 100);
    g.add_edge('1', '5', 30);
    g.add_edge('5', '4', 25);
    g.add_edge('5', '6', 5);
    g.add_edge('5', '8', 50);
    g.add_edge('1', '6', 60);
    g.add_edge('6', '7', -50);
    g.add_edge('7', '8', -10);

    // std::map<char, std::map<char, int>> matrix;
    // g.fill_matrix(matrix);
    

    g.print_graph();
    // g.kruskal();
    // g.prim('a');
    // g.dijkstra('a');
    // g.bellman_ford('0');

    // for(int i = 48; i <= 57; i++) {
    //     const char point = (char)i;
    //     std::cout << point << '\n';
    //     g.bellman_ford(point);
    //     std::cout << "------------------------------------------------------\n";
    // }
    // g.floyd_warshall();
    // g.print_all_edge();
    // g.print_graph();
}
