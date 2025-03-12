#include "dijkstras.h"

int main(int argc, char *argv[]) {
    string file_name = "small.txt";
    string file_name_src = "src/"+file_name;
    cout << "dijkstras " << file_name << endl;
    string filename = get_arg(argc, argv, file_name_src);
    Graph G;
    file_to_graph(filename, G);

    vector<int> previous(G.numVertices);
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    for (int vertex = 0; vertex < G.numVertices; ++vertex) {
        vector<int> path = extract_shortest_path(distances, previous, vertex);
        print_path(path, distances[vertex]);
    }
    return 0;
} 