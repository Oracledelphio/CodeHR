#include <bits/stdc++.h>
using namespace std;

using Graph = unordered_map<int,vector<int>>;
bool hasCycleUndirected(int node, int parent, Graph& adjList, unordered_set<int>& visited){
    visited.insert(node);
    for (int neighbour : adjList[node]){
        if (!visited.count(neighbour)){
            if (hasCycleUndirected(neighbour,node,adjList, visited)) return true;
        }
        else if (neighbour != parent) return true;
    }
    return false;
}