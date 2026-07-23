#include <bits/stdc++.h>
using namespace std;

using Graph = unordered_map<int,vector<int>>;

void dfs(int node, Graph& adjList, unordered_set<int>& visited){
    if (visited.count(node)) return;
    visited.insert(node);
    cout<<node<<" ";
    for (int neighbour : adjList[node]){
          dfs(neighbour, adjList, visited);  
    }

}

void bfs(int start, Graph& adjList){
    unordered_set<int> visited;
    queue<int> q;
    q.push(start);
    visited.insert(start);         // Insert into visited always while pushing and not while popping.
    while (!q.empty()){
        int curr = q.front();
        q.pop();
        cout<< curr << " ";

        for (int neighbour : adjList[curr]){
            if (!visited.count(neighbour)){
                visited.insert(neighbour);
                q.push(neighbour);
        }
        }

    }
}

void dfsAll(Graph& adjList, int numNode){
    unordered_set<int> visited;

    for (int node =0; node < numNode; node++){
        if (!visited.count(node)){
            dfs(numNode,adjList,visited);
        }
    }
}

int main() {
    Graph adjList;

    // Undirected graph
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 5};
    adjList[3] = {1};
    adjList[4] = {1, 5};
    adjList[5] = {2, 4};

    cout << "BFS starting from 0: ";
    bfs(0, adjList);

    cout << "\nDFS starting from 0: ";
    unordered_set<int> visited;
    dfs(0, adjList, visited);

    cout << endl;

    return 0;
}