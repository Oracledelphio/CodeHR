#include <bits/stdc++.h>
using namespace std;

using Graph = unordered_map<int, vector<int>>;

void dfs (int node, Graph& adjList, unordered_set<int>& visited){
    if (visited.count(node)) return;
    visited.insert(node);
    cout<<node << " ";
    for (int neighbour : adjList[node]){
        dfs(neighbour,adjList,visited);
        }
    }

void bfs(Graph& adjList, int start){
    unordered_set<int> visited;
    queue<int> q;
    q.push(start);
    visited.insert(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for ( int neighbour: adjList[curr]){
            if (!visited.count(neighbour)){
                visited.insert(neighbour);
                q.push(neighbour);
            }

        }
    }
}