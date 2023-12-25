#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class disjoint_set {
public:
    disjoint_set() {}

    void print_set() {
        for (size_t i = 0; i < sets.size(); i++) {
            std::cout << i << ": ";
            for (const char el : sets[i]) {
                std::cout << el << " ";
            }
            std::cout << '\n';
        }
    }

    void
    make_set(const std::unordered_map<char, std::list<std::pair<char, int>>>&
                 adjacency_list) {
        for (const auto& el : adjacency_list) {
            sets.push_back({el.first});
        }
    }

    int find_set(const char vertex) {
        for (size_t i = 0; i < sets.size(); i++) {
            if (sets[i].find(vertex) != sets[i].end()) {
                return i;
            }
        }

        return -1;
    }

    void merge_set(const int set1, const int set2) {
        sets[set1].merge(sets[set2]);
        // for (char el : sets[set2]) {
        //     sets[set1].insert(el);
        // }
        print_set();
        std::cout << '\n';
        sets.erase(sets.begin() + set2);
    }

private:
    std::vector<std::unordered_set<char>> sets;
};

class unweighted_graph {
public:
    unweighted_graph(const bool directed);
    void add_edge(const char src, const char dest);
    void DFS(const char start);
    void BFS(const char start);
    void print_graph();

private:
    std::unordered_map<char, std::list<char>> adjacency_list;
    std::unordered_set<char> visited;
    int vert_count;
    bool is_directed;
};

class weighted_graph {
public:
    weighted_graph(const bool directed);
    void add_edge(const char src, const char dest, const int weight);
    void kruskal();
    void prim(const char start);
    void bellman_ford(const char start);
    void print_graph();
    void print_all_edge();

private:
    std::unordered_map<char, std::list<std::pair<char, int>>> adjacency_list;
    std::vector<std::pair<char, std::pair<char, int>>> all_edges;
    // std::unordered_set<char> visited;
    int vert_count;
    bool is_directed;
};

#endif
