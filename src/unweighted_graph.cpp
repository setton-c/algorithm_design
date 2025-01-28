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
    vert_count = adjacency_list.size();
}

void unweighted_graph::DFS(const char start, bool scc, bool keep_visited) {
    if (!keep_visited){
        visited.clear();
    }
    
    std::unordered_map<char, std::list<char>>* Graph = 
        scc ? &(this->adjacency_list_transposed) : &(this->adjacency_list);

    std::stack<char> neighbours;
    neighbours.push(start);

    while (!neighbours.empty()) {
        const char current = neighbours.top();
        neighbours.pop();

        if (visited.find(current) != visited.end()) {
            continue;
        }

        visited.insert(current);
        if (scc) {
            std::cout << current << " ";
        }

        for (const char& neighbour : (*Graph)[current]) {
            if (visited.find(neighbour) == visited.end()) {
                neighbours.push(neighbour);
            }
        }
        
        if (!scc) {
            this->scc_order.push(current);
        }
    }
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

void unweighted_graph::Kosaraju_SCC() {
    visited.clear();

    for (auto& vertex : adjacency_list) {
        if (visited.find(vertex.first) == visited.end()) {
            this->DFS(vertex.first, false, true);
        }
    }

    this->transpose_graph();

    visited.clear();
    while(!this->scc_order.empty()) {
        const char current = scc_order.top();
        scc_order.pop();

        if(visited.find(current) == visited.end()) {
            std::cout << "SCC: ";
            DFS(current, true, true);
            std::cout << "\n";
        }
    }
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

void unweighted_graph::transpose_graph() {
    this->adjacency_list_transposed.clear();

    for(auto& vertex : this->adjacency_list) {
        for(const char& neighbour : vertex.second) {
            adjacency_list_transposed[neighbour].push_back(vertex.first);
        }
    }
}

