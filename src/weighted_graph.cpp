#include "graph.h"
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>

weighted_graph::weighted_graph(const bool directed) : is_directed(directed) {}

void weighted_graph::add_edge(
    const char src,
    const char dest,
    const int weight
) {
    std::pair<char, int> edge(dest, weight);

    adjacency_list[src].push_back(edge);
    all_edges.push_back({src, edge});
    vert_count = adjacency_list.size();

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
        std::cout << "***" << dest << "***\n\n";
        // add it to the MST
        std::cout << src << " to " << dest << " weight: " << weight << '\n';
        // and push all its neighbours to the pq
        for (const auto& edge : adjacency_list[dest]) {
            pq.push({edge.second, {dest, edge.first}});
        }
    }
}

void weighted_graph::print_shortest_path(
    const char destination,
    const char start
) {
    std::cout << "Path to " << destination << ": ";

    std::stack<char> pathStack;
    char current = destination;

    while (previous.find(current) != previous.end()) {
        pathStack.push(current);
        current = previous[current];
    }

    // Print the start vertex
    std::cout << start;

    // Print the rest of the path
    while (!pathStack.empty()) {
        std::cout << " -> " << pathStack.top();
        pathStack.pop();
    }
}

void weighted_graph::dijkstra(const char start) {
    previous.clear();
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
        std::cout << "current_vert: " << current_vert << std::endl;
        std::cout << "current_distance: " << current_distance << std::endl;

        if (visited.find(current_vert) != visited.end()) {
            std::cout << current_vert << " already visited, skipping" << std::endl << std::endl;
            continue;
        }

        visited.insert(current_vert);
        std::cout << "Visited: " << current_vert << std::endl;

        for (const auto& edge : adjacency_list[current_vert]) {
            char neighbour = edge.first;
            int neighbour_distance = edge.second;
            int new_distance = current_distance + neighbour_distance;

            std::cout << "\tneighbour: " << neighbour << std::endl;
            std::cout << "\tneighbour_distance: " << neighbour_distance << std::endl;
            std::cout << "\tnew_distance: " << new_distance << std::endl;

            if (distance.find(neighbour) == distance.end() ||
                new_distance < distance[neighbour]) {
                
                distance[neighbour] = new_distance;
                std::cout<< "\t\tdistance[" << neighbour << "]: " << new_distance << std::endl;
                previous[neighbour] = current_vert;
                std::cout<< "\t\tprevious[" << neighbour << "]: " << current_vert << std::endl;
                pq.push({new_distance, neighbour});
                std::cout << "\t\tPQ pushed: " << "(" << new_distance << ", " << neighbour << ")"<< std::endl;
            }
        }
    }
    std::cout << std::endl; 
    for(const auto& edge : previous) {
        std::cout << edge.first << ": " << (char)edge.second << std::endl;
    }
    
    std::cout << "From: " << start << '\n';
    for (const auto& edge : distance) {
        print_shortest_path(edge.first, start);
        std::cout << " Sum: " << edge.second << '\n';
    }
}

/// TODO: Improve the Bellman-Ford implementation
void weighted_graph::bellman_ford(const char start) {
    previous.clear();
    std::unordered_map<char, int> distance;

    for (const auto& edge : adjacency_list) {
        distance[edge.first] = std::numeric_limits<int>::max();
    }
    distance[start] = 0;

    for (size_t i = 0; i < vert_count - 1; ++i) {
        for (const auto& adj_list : adjacency_list) {
            const char current = adj_list.first;

            for (const auto& edge : adj_list.second) {
                const char neighbor = edge.first;
                const int weight = edge.second;

                if (distance[current] != std::numeric_limits<int>::max() &&
                    distance[current] + weight < distance[neighbor]) {
                    distance[neighbor] = distance[current] + weight;
                    previous[neighbor] = current;
                }
            }
        }
    }

    std::unordered_set<char> negative_cycle_nodes;
    for (size_t i = 0; i < vert_count; ++i) {
        for (const auto& adj_list : adjacency_list) {
            const char current = adj_list.first;

            for (const auto& edge : adj_list.second) {
                const char neighbor = edge.first;
                const int weight = edge.second;

                if (distance[current] != std::numeric_limits<int>::max() &&
                        distance[current] + weight < distance[neighbor]) {
                    negative_cycle_nodes.insert(neighbor);
                }

                if (negative_cycle_nodes.count(current)) {
                    negative_cycle_nodes.insert(neighbor);
                }
            }
        }
    }

    std::cout << "From: " << start << '\n';
    for (const auto& edge : distance) {
        const char node = edge.first;
        if (negative_cycle_nodes.count(node)) {
            std::cout << node << ": No path (negative cycle)\n";
        } else if (edge.second == std::numeric_limits<int>::max()) {
            std::cout << node << ": No path\n";
        } else {
            print_shortest_path(node, start);
            std::cout << " Sum: " << edge.second << '\n';
        }
    }
}

void weighted_graph::floyd_warshall() {
    std::map<char, std::map<char, int>> matrix;
    init_all_vertices();
    fill_matrix(matrix);

    for (const auto& k : this->all_vertices) {
        for (const auto& i : this->all_vertices) {
            for (const auto& j : this->all_vertices) {
                matrix[i][j] = std::min(
                        matrix[i][j],
                        matrix[i][k] + matrix[k][j]
                );
            }
        }
    }

    print_matrix(matrix);
}

void weighted_graph::fill_matrix(std::map<char, std::map<char, int>>& matrix) {
    for (const auto& src : this->all_vertices) {
        for (const auto& dest : this->all_vertices) {
            if (src == dest) {
                matrix[src][dest] = 0;
            } else {
                matrix[src][dest] = 9999;
            }
        }
    }

    for (const auto& src : adjacency_list) {
        for (const auto& edge : src.second) {
            matrix[src.first][edge.first] = edge.second;
        }
    }
}

void weighted_graph::init_all_vertices() {
    for (const auto& src : adjacency_list) {
        all_vertices.insert(src.first);
        for (const auto& edge : src.second) {
            all_vertices.insert(edge.first);
        }
    }
}

void weighted_graph::print_matrix(std::map<char, std::map<char, int>>& matrix) {
    for(const auto& edge : matrix) {
        std::cout << edge.first << ": {\n";
        for(const auto& neighbours : edge.second) {
            std::cout << "\t" << neighbours.first << ": " << neighbours.second << '\n';
        }
        std::cout << "}\n";
    }
}

void weighted_graph::print_graph() {
    for (const auto& el : adjacency_list) {
        std::cout << el.first << ": ";
        for (const auto& pr : el.second) {
            printf("(%c, %d) ", pr.first, pr.second);
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
