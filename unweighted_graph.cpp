#include "graph.h"

#include <iostream>
#include <queue>
#include <stack>

unweighted_graph::unweighted_graph(const bool directed)
    : vert_count(0), is_directed(directed) {}

void unweighted_graph::add_edge(const char src, const char dest) {
    if (!is_directed) {
        adjacency_list[dest].push_back(src);
    }

    adjacency_list[src].push_back(dest);
    vert_count++;
}

void unweighted_graph::DFS(const char start) {
    visited.clear();

    std::stack<char> neighbours;
    neighbours.push(start);

    while (!neighbours.empty()) {
        const char current = neighbours.top();
        neighbours.pop();

        if (visited.find(current) != visited.end()) {
            continue;
        }

        visited.insert(current);
        std::cout << current << " ";

        for (const char& neighbour : adjacency_list[current]) {
            if (visited.find(neighbour) == visited.end()) {
                neighbours.push(neighbour);
            }
        }
    }
    std::cout << '\n';
}

void unweighted_graph::BFS(const char start) {
    visited.clear();

    std::queue<char> neighbours;
    neighbours.push(start);

    while (!neighbours.empty()) {
        const char current = neighbours.front();
        neighbours.pop();

        if (visited.find(current) != visited.end()) {
            continue;
        }

        visited.insert(current);
        std::cout << current << " ";

        for (const char& neighbour : adjacency_list[current]) {
            if (visited.find(neighbour) == visited.end()) {
                neighbours.push(neighbour);
            }
        }
    }
    std::cout << '\n';
}

void unweighted_graph::print_graph() {
    std::cout << "Vertex count: " << vert_count << '\n';
    // Type: const std::pair<const char, const std::list<char>> el
    for (const auto& el : adjacency_list) {
        std::cout << el.first << ": ";

        for (const char& lst_el : el.second) {
            std::cout << lst_el << " ";
        }
        std::cout << '\n';
    }
}
