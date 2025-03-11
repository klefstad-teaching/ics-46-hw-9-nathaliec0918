// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <queue>
// #include <limits>
// #include <stack>
#include "dijkstras.h"

using namespace std;

// vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
//     int num = G.numVertices;
//     vector<int> distances(num, INF);
//     vector<bool> visited(num, false);
//     distances[source] = 0;
//     previous[source] = -1;
//     // initialize as minHeap
//     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap; 
//     minHeap.push({source, 0});

//     while (!minHeap.empty()) {
//         int src = minHeap.top().first;
//         minHeap.pop();
//         if (visited[src]) continue;
//         visited[src] = true;
//         for (const Edge & edge : graph[src]) {
//             int this_src = edge.src;
//             int dst = edge.dst;
//             int weight = edge.weight;
//             if (!visited[this_src] && distances[src] + weight < distances[this_src]) {
//                 distances[this_src] = distances[src] + weight;
//                 previous[this_src] = src;
//                 minHeap.push({this_src, distances[this_src]});
//             }
//         }
//     }
//     return distances;
// }

// vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    
// }

// void print_path(const vector<int>& v, int total) {

//     cout << "Total cost is " << total << endl;
// }
