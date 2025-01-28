#include "src/graph.h"
#include "example_graphs.h"

int main() {
    // unweighted_graph graph(true);
    // graph_5(graph);
    // 
    // std::cout << "Graph:" << std::endl;
    // graph.print_graph();
    //
    // std::cout << "\nStrongly Connected Components (Kosaraju's Algorithm):\n";
    // graph.Kosaraju_SCC();

    weighted_graph graph(true);
    graph_4(graph);

    std::cout << "Graph:" << std::endl;
    graph.print_graph();
    
    graph.bellman_ford('0');

    // std::map<char, std::map<char, int>> matrix;
    // g.fill_matrix(matrix);

    // graph.print_graph();
    // g.kruskal();
    // g.prim('a');
    // g.dijkstra('a');
    // g.bellman_ford('0');

    // for(int i = 48; i <= 57; i++) {
    //     const char point = (char)i;
    //     std::cout << point << '\n';
    //     g.bellman_ford(point);
    //     std::cout <<
    //     "------------------------------------------------------\n";
    // }
    // g.floyd_warshall();
    // g.print_all_edge();
    // g.print_graph();
}
