class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> pointers(k, 0);
        vector<int> result(2, 0);
        int currentMin = INT_MAX;

        // Create a min heap using a priority queue.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Find the initial max value among all lists and add it to the min heap.
        int currentMax = INT_MIN;
        for (int i = 0; i < k; i++) {
            minHeap.push({nums[i][0], i});
            currentMax = max(currentMax, nums[i][0]);
        }

        // Loop until we reach the end of any list.
        while (true) {
            pair<int, int> minElement = minHeap.top();
            minHeap.pop();

            int minVal = minElement.first;
            int listIndex = minElement.second;

            // Check the current range.
            if (currentMax - minVal < currentMin) {
                currentMin = currentMax - minVal;
                result[0] = minVal;
                result[1] = currentMax;
            }

            // Move the pointer of the list.
            pointers[listIndex]++;

            // If any list reaches its end, break the loop.
            if (pointers[listIndex] == nums[listIndex].size()) {
                break;
            }

            // Push the next element from the list to the min heap.
            minHeap.push({nums[listIndex][pointers[listIndex]], listIndex});

            // Update the current max value.
            currentMax = max(currentMax, nums[listIndex][pointers[listIndex]]);
        }

        return result;
    }
};
