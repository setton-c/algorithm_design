#include "src/graph.h"

inline void graph_1(weighted_graph& g) {
    g.add_edge('a', 'b', 14);
    g.add_edge('a', 'd', 10);
    g.add_edge('b', 'c', 13);
    g.add_edge('b', 'e', 4);
    g.add_edge('d', 'c', 8);
}

inline void graph_2(weighted_graph& g) {
    g.add_edge('a', 'b', 4);
    g.add_edge('a', 'c', 4);
    g.add_edge('b', 'c', 2);
    g.add_edge('c', 'd', 3);
    g.add_edge('c', 'f', 6);
    g.add_edge('c', 'e', 2);
    g.add_edge('d', 'f', 3);
    g.add_edge('e', 'f', 3);
}

inline void graph_3(weighted_graph& g) {
    g.add_edge('a', 'b', 4);
    g.add_edge('a', 'c', 2);
    g.add_edge('b', 'c', 3);
    g.add_edge('c', 'b', 1);
    g.add_edge('b', 'd', 2);
    g.add_edge('b', 'e', 3);
    g.add_edge('c', 'd', 4);
    g.add_edge('c', 'e', 5);
    // g.add_edge('e', 'd', -5);
}

inline void graph_4(weighted_graph& g) {
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
}

inline void graph_5(unweighted_graph& g) {
    g.add_edge('0', '1');
    g.add_edge('1', '2');
    g.add_edge('2', '3');
    g.add_edge('3', '0');
    g.add_edge('2', '4');
    g.add_edge('4', '5');
    g.add_edge('5', '6');
    g.add_edge('6', '4');
    g.add_edge('6', '7');
}
