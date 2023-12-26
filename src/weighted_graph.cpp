#include "graph.h"
#include <algorithm>
#include <queue>
#include <cstdio>
#include <iostream>

weighted_graph::weighted_graph(const bool directed) : is_directed(directed) {}

void weighted_graph::add_edge(
    const char src,
    const char dest,
    const int weight
) {
    std::pair<char, int> edge(dest, weight);

    adjacency_list[src].push_back(edge);
    all_edges.push_back({src, edge});
    vert_count++;

    if (!is_directed) {
        adjacency_list[dest].push_back(std::make_pair(src, weight));
    }
}

void weighted_graph::kruskal() {
    std::sort(
        all_edges.begin(),
        all_edges.end(),
        [](const std::pair<char, std::pair<char, int>>& a,
           const std::pair<char, std::pair<char, int>>& b) {
            return a.second.second < b.second.second;
        }
    );

    this->print_all_edge();

    disjoint_set forest;

    forest.make_set(adjacency_list);

    for (const auto& edge : all_edges) {
        const char src = edge.first;
        const char dest = edge.second.first;

        int set1 = forest.find_set(src);
        int set2 = forest.find_set(dest);

        if (set1 != set2) {
            forest.merge_set(set1, set2);
            std::cout << src << " to " << dest << " : " << edge.second.second
                      << '\n';
        }
    }
}

void weighted_graph::prim(const char start) {
    
}

void weighted_graph::print_graph() {
    for (const auto& el : adjacency_list) {
        std::cout << el.first << ": ";
        for (const auto& pr : el.second) {
            printf("(%c, %d), ", pr.first, pr.second);
        }
        std::cout << '\n';
    }
}

void weighted_graph::print_all_edge() {
    for (const auto& edge : all_edges) {
        printf(
            "(%c, (%c, %d))\n",
            edge.first,
            edge.second.first,
            edge.second.second
        );
    }
}
