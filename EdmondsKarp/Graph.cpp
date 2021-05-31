#include "Graph.h"

void Graph::create_graph_from_file(const char *file_name) {
    std::fstream graph_file;
    graph_file.open(file_name);
    if(graph_file.is_open())
    {
        graph_file >> number_of_vertices >> number_of_edges;
        graph_file >> source_vertex >> sink_vertex;
        if(source_vertex > number_of_vertices)
            throw std::invalid_argument("Source vertex doesn't belong to the number_of_vertices of given graph");
        if(sink_vertex > number_of_vertices)
            throw std::invalid_argument("Sink vertex doesn't belong to the number_of_vertices of given graph");
        for(int i = 0; i < number_of_vertices; ++i)
        {
            std::vector<int> temp_vector;
            temp_vector.reserve(number_of_vertices);
            for(int j =0; j < number_of_vertices; ++j)
            {
                temp_vector.push_back(0);
            }
            adj_tableaux.push_back(temp_vector);
        }
        for(int i= 0; i < number_of_edges; ++i )
        {
            size_t start_node_, end_node_;
            unsigned int capacity;
            graph_file >> start_node_ >> end_node_ >> capacity;
            if(source_vertex > number_of_vertices)
            {
                std::cout << "Incorrect starting node: " << start_node_ << ", given in line: \"" <<
                          start_node_ << " " << end_node_ << " " << capacity << " \"\n";
                throw std::invalid_argument("Starting node doesn't belong to the number_of_vertices of given graph");
            }
            if(sink_vertex > number_of_vertices)
            {
                std::cout << "Incorrect ending node: " << start_node_ << ", given in line: \"" <<
                          start_node_ << " " << end_node_ << " " << capacity << " \"\n";
                throw std::invalid_argument("Ending node doesn't belong to the number_of_vertices of given graph");
            }
            adj_tableaux[start_node_-1][end_node_-1] = capacity;
        }
        std::cout<< "Graph from file "<< file_name<< ":\n";
        std::cout << "Graph is consisted of: " << number_of_vertices << " vertices and " << number_of_edges << " edges\n";
        std::cout << "Starting node: " << source_vertex << " and ending node: " << sink_vertex << std::endl;
    }
    graph_file.close();
}

void Graph::display_adj_tableaux() {
    for(unsigned int i= 0; i < number_of_vertices; ++i)
    {
        std::cout << i+1 << ": ";
        for(unsigned int j= 0; j < number_of_vertices; ++j)
        {
            std:: cout << adj_tableaux[i][j] << " ";
        }
        std:: cout<< std::endl;
    }
}

int Graph::return_max_flow() {
    int max_flow = 0;
    std::queue<int> nodes_queue;
    std::vector<std::vector<int>> flow_matrix; //przeplywy na krawedziach
    std::vector<int> bfs_predecessors; // tablica poprzednikow
    std::vector<int> paths_traffic; // tablica przepustowosci

    // 1. zerowanie przeplywow
    for(int i = 0; i < number_of_vertices; ++i)
    {
        std::vector<int> temp_vector;
        temp_vector.reserve(number_of_vertices);
        for(int j =0; j < number_of_vertices; ++j)
        {
            temp_vector.push_back(0);
        }
        flow_matrix.push_back(temp_vector);
        paths_traffic.push_back(0);
    }
    bfs_predecessors.reserve(number_of_vertices);
    for(int i = 0; i < number_of_vertices; ++i)
    {
        bfs_predecessors.push_back(-1);
    }
    while(true)
    {
        //2. zerowanie tablicy poprzednikow
        for(int i = 0; i < number_of_vertices; ++i)
        {
            bfs_predecessors[i]= -1;
        }
        // zrodlo nie ma poprzednika
        bfs_predecessors[source_vertex - 1] = INT_MIN;

        // do tablicy przepustowosci wpisuje max liczbe INT
        paths_traffic[source_vertex - 1] = INT_MAX;

        //zeruje kolejke i umieszczam w niej zrodlo
        while(!nodes_queue.empty())
            nodes_queue.pop();
        nodes_queue.push(source_vertex - 1);

        bool escape_double_loop = false;
        while(!nodes_queue.empty())
        {
            //zdejmuje pierwszy element z kolejki
            int element = nodes_queue.front();
            nodes_queue.pop();

            // sprawdzam wszystkie sasiadujace nody z elementem - odczytuje z macierzy adj
            for(int i = 0; i < number_of_vertices; ++i)
            {
                int check_value = adj_tableaux[element][i] - flow_matrix[element][i] ;
                if( check_value && (bfs_predecessors[i] == -1))
                {
                    bfs_predecessors[i] = element;

                    //obliczam przepustowosc dla wierzcholka i
                    paths_traffic[i]= paths_traffic[element] > check_value ? check_value: paths_traffic[element];

                    if(i == sink_vertex - 1)
                    {
                        //wierzcholek i jest ujsciem
                        max_flow += paths_traffic[sink_vertex - 1];
                        int local = i;
                        while(source_vertex - 1 != local)
                        {
                            element = bfs_predecessors[local];
                            flow_matrix[element][local] += paths_traffic[sink_vertex - 1];
                            flow_matrix[local][element] -= paths_traffic[sink_vertex - 1];
                            local = element;
                        }
                        escape_double_loop = true;
                        break;
                    }
                    //wierzcholek i nie jest ujściem - dopisuje go na końcu kolejki i kontynuuje BFS
                    nodes_queue.push(i);
                }
            }
            //zostala znaleziona sciezka do ujscia
            if(escape_double_loop)
                break;
        }
        // nie znaleziono sciezki
        if(!escape_double_loop)
            break;
    }
    std:: cout << "\nMax flow: "<< max_flow << std::endl<< std::endl;
    std:: cout << "PATH      : USED CAPACITY"<<std::endl;
    for(int i = 0; i < number_of_vertices; ++i)
    {
        for(int j = 0; j < number_of_vertices; ++j)
        {
            if(adj_tableaux[i][j]!= 0 && flow_matrix[i][j]>0)
            {
                std::cout << i+1 << " -> "<< j+1;
                if(i <10 && j < 10)
                    std::cout << "   ";
                else if((i <10 || j < 10) && i <100 && j < 100)
                    std::cout << "  ";
                else if(i <100 && j < 100)
                    std:: cout << " ";
                std::cout << " : "<< adj_tableaux[i][j]<< std::endl;
            }
        }
    }
    std::cout << std::endl;
    return max_flow;
}
//Paulina Gacek, May 2021