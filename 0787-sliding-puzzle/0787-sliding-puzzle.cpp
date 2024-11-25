
class Solution {
public:
    //! Time Complexity: O(N!) - N is the number of tiles in the board.
    //! Auxiliary Space: O(N!) - Space for visited states and BFS queue.

    int slidingPuzzle(vector<vector<int>>& board) {
        // Convert the board to a string representation for easier manipulation
        string startState = "";
        for (const auto& row : board)
            for (int num : row)
                startState += (num + '0');
        
        string targetState = "123450"; // Goal state

        // BFS queue to explore board states; each element is {state, moves}
        queue<pair<string, int>> bfsQueue;
        bfsQueue.push({startState, 0});

        // Visited set to avoid re-processing states
        unordered_map<string, bool> visited;
        visited[startState] = true;

        // Define valid swaps for each index (pre-computed adjacency list)
        vector<vector<int>> adjList = {
            {1, 3},       // 0
            {0, 2, 4},    // 1
            {1, 5},       // 2
            {0, 4},       // 3
            {1, 3, 5},    // 4
            {2, 4}        // 5
        };

        while (!bfsQueue.empty()) {
            auto [currentState, moves] = bfsQueue.front();
            bfsQueue.pop();

            if (currentState == targetState) {
                return moves; // Return the minimum moves to solve the puzzle
            }

            int zeroIdx = currentState.find('0'); // Find the position of '0'

            // Try all valid swaps for the current position of '0'
            for (int swapIdx : adjList[zeroIdx]) {
                string nextState = currentState;
                swap(nextState[zeroIdx], nextState[swapIdx]); // Swap tiles

                if (!visited[nextState]) {
                    visited[nextState] = true;
                    bfsQueue.push({nextState, moves + 1});
                }
            }
        }

        return -1; // If no solution is found
    }
};
