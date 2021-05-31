//Paulina Gacek, May 2021
#include <iostream>
#include "Graph.h"

int main() {
    std::string file_name;
    std::cin >> file_name;
    Graph test_graph_from_cin, test_graph2_from_main;
    try{
        test_graph_from_cin.create_graph_from_file(file_name.c_str());
        test_graph_from_cin.return_max_flow();
        /*
         * IF SOMEHOW READING FILES FROM CIN DOESN'T WORK, REPLACE *** WITH THE FILE NAME AND UNCOMMENT THIS PART
         *
        test_graph2_from_main.create_graph_from_file("***");
        test_graph2_from_main.return_max_flow();
         */
    }
    catch(std::exception &error)
    {
        std::cout << error.what()<<std::endl;
    }
    return 0;
}
/***
 * FILE SYNTAX:
 * n - number of nodes
 * m - number of edges
 * s - source node
 * t - sink node
 *
 * ...
 * m lines: starting node - ending node - capacity
 * ...
*/