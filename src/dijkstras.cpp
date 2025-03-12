// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <queue>
// #include <limits>
// #include <stack>
#include "dijkstras.h"

using namespace std;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int num = G.numVertices;
    vector<int> distances(num, INF);
    
    distances[source] = 0;
    previous.assign(num, -1);

    // vector<bool> visited(num, false);
    // distances[source] = 0;
    // previous[source] = -1;

    // initialize as minHeap
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap; 
    // minHeap.push({source, 0});
    minHeap.push({0, source});
    while (!minHeap.empty()) {
        auto[dst, src] = minHeap.top();
        minHeap.pop();
        if (dst > distances[src]) continue;
        for (const Edge & edge : G[src]) {
            int dst = edge.dst;
            int weight = edge.weight;
            if (distances[src] + weight < distances[dst]) {
                distances[dst] = distances[src] + weight;
                previous[dst] = src;
                minHeap.push({distances[dst], dst});
            }
        }
    }
    // while (!minHeap.empty()) {
    //     int src = minHeap.top().first;
    //     minHeap.pop();
    //     if (visited[src]) continue;
    //     visited[src] = true;
    //     for (const Edge & edge : G[src]) {
    //         // int this_src = edge.src;
    //         int dst = edge.dst;
    //         int weight = edge.weight;
    //         if (!visited[dst] && distances[src] + weight < distances[dst]) {
    //             distances[dst] = distances[src] + weight;
    //             previous[dst] = src;
    //             minHeap.push({dst, distances[dst]});
    //         }
    //     }
    // }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) { //go backwardsd from previous from destination
    vector<int> path;
    if (distances[destination] == INF) return path;
    for (int i = destination; i != -1; i = previous[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total) {
    for (const int & each : v) {
        cout << each << " ";
    }
    cout << endl;
    cout << "Total cost is " << total << endl;
}

string get_arg(int argc, char *argv[], string def) {
    if (argc > 1)
        return argv[1];
    else
        return def;
}

void file_to_graph(string filename, Graph & G) {
    ifstream in(filename);
    in >> G;
    in.close(); 
}