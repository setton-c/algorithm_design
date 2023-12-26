#include "graph.h"

void disjoint_set::print_set() {
    for (size_t i = 0; i < sets.size(); i++) {
        std::cout << i << ": ";
        for (const char el : sets[i]) {
            std::cout << el << " ";
        }
        std::cout << '\n';
    }
}

void disjoint_set::make_set(
    const std::unordered_map<char, std::list<std::pair<char, int>>>&
        adjacency_list
) {
    for (const auto& el : adjacency_list) {
        sets.push_back({el.first});
    }
}

int disjoint_set::find_set(const char vertex) {
    for (size_t i = 0; i < sets.size(); i++) {
        if (sets[i].find(vertex) != sets[i].end()) {
            return i;
        }
    }

    return -1;
}

void disjoint_set::merge_set(const int set1, const int set2) {
    sets[set1].merge(sets[set2]);
    // print_set();
    std::cout << '\n';
    sets.erase(sets.begin() + set2);
}
