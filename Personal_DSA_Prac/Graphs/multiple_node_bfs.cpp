// Multiple chemical gas nozzles are opened simultaneously in an $M \times N$ etching chamber. 
//How many seconds does it take for the gas to cover every clear cell in the chamber?

// The Algorithm Secret:Instead of pushing one starting point into your std::queue, you push ALL nozzles into the queue at Time t = 0 
//before starting the loop. 
//Because BFS guarantees level-by-level expansion, the gas expands outward from all nozzles simultaneously like ripples in a pond.

//TEMPLATE NOT ACTUAL

#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int getTimeToFill(vector<vector<int>>& grid){
    int M = grid.size();
    int N = grid[0].size();
    queue<pair<int,int>> q;
    int target_cells = 0;

    for (int i = 0; i<M; i++){
        for (int j=0; j< N ; j++){
            if (grid[i][j]==2){
                q.push({i,j});
            } else if (grid[i][j]==1){
                target_cells++;
            }
        }
    }
    if (target_cells == 0) return 0;

    int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int time_elapsed = 0;
    
    while (!q.empty() && target_cells > 0) {
        int level_size = q.size(); // Number of active edges expanding IN THIS SECOND
        
        for (int k = 0; k < level_size; k++) {
            auto [r, c] = q.front();
            q.pop();

            // Try all 4 directions
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                // Boundary check AND validity check
                if (nr >= 0 && nr < M && nc >= 0 && nc < N && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; // Mark visited/filled
                    target_cells--;   // One less cell to cover
                    q.push({nr, nc}); // Add new edge to queue for next second
                }
            }
        }
        time_elapsed++; // Increment time AFTER an entire level finishes expanding
    }

    // If target_cells > 0, some cells were blocked by obstacles (0) and unreachable
    return (target_cells == 0) ? time_elapsed : -1;
}
