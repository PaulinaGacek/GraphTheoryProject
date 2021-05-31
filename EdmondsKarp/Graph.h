#ifndef EDMONDSKARP_GRAPH_H
#define EDMONDSKARP_GRAPH_H
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>

class Graph {
    int number_of_vertices;
    int number_of_edges;
    int source_vertex = 0, sink_vertex = 0;
    std::vector<std::vector<int>> adj_tableaux{};
public:
    Graph(): number_of_vertices{0}, number_of_edges{0}{};
    void create_graph_from_file(const char* file_name);
    void display_adj_tableaux();
    int return_max_flow();
};


#endif //EDMONDSKARP_GRAPH_H
//Paulina Gacek, May 2021