#include "graph.h"
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

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
    // Clear the vector from potential
    // remainders from previous operations
    visited.clear();

    // Initialize the priority_queue in a way where
    // it Prioritizes edges with smallest weights
    std::priority_queue<
        std::pair<int, std::pair<char, char>>,
        std::vector<std::pair<int, std::pair<char, char>>>,
        std::greater<std::pair<int, std::pair<char, char>>>>
        pq;
    // Mark the starting node as visited
    visited.insert(start);
    // store all the neighbours of our starting node in the pq
    for (const auto& edge : adjacency_list[start]) {
        pq.push({edge.second, {start, edge.first}});
    };

    // Repeat for all edges
    while (!pq.empty() && visited.size() < vert_count) {
        std::pair<int, std::pair<char, char>> min_edge = pq.top();
        pq.pop();

        char src = min_edge.second.first;
        char dest = min_edge.second.second;
        int weight = min_edge.first;

        // if the node is already visited we skip it
        if (visited.find(dest) != visited.end()) {
            continue;
        }
        // if not we mark it as visited
        visited.insert(dest);
        // add it to the MST
        std::cout << src << " to " << dest << " weight: " << weight << '\n';
        // and push all its neighbours to the pq
        for (const auto& edge : adjacency_list[dest]) {
            pq.push({edge.second, {dest, edge.first}});
        }
    }
}

void weighted_graph::dijkstra(const char start) {
    visited.clear();
    std::unordered_map<char, int> distance;
    distance[start] = 0;

    std::priority_queue<
        std::pair<int, char>,
        std::vector<std::pair<int, char>>,
        std::greater<std::pair<int, char>>>
        pq;
    pq.push({0, start});

    while (!pq.empty() && visited.size() < vert_count) {
        std::pair<int, char> current = pq.top();
        pq.pop();

        char current_vert = current.second;
        int current_distance = current.first;

        if (visited.find(current_vert) != visited.end()) {
            continue;
        }

        visited.insert(current_vert);

        for (const auto& edge : adjacency_list[current_vert]) {
            char neighbour = edge.first;
            int neighbour_distance = edge.second;
            int new_distance = current_distance + neighbour_distance;

            if (distance.find(neighbour) == distance.end() ||
                new_distance < distance[neighbour]) {
                distance[neighbour] = new_distance;
                pq.push({new_distance, neighbour});
            }
        }
    }
    std::cout << "From: " << start << '\n';
    for(const auto& edge : distance) {
        std::cout << edge.first << ": " << edge.second << '\n';
    }
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
