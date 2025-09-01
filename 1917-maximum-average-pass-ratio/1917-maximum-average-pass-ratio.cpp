class Solution {
    typedef pair<int,int> pii;
public:
   double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    auto profit = [&](double pass, double total) {
        return (pass + 1) / (total + 1) - pass / total;
    };
    double total = 0;
    priority_queue<pair<double, array<int, 2>>> pq;
    for (auto &c : classes) {
        total += (double) c[0] / c[1];
        pq.push({profit(c[0], c[1]), {c[0], c[1]}});
    }
    while (extraStudents--) {
        auto [added_profit, c] = pq.top(); pq.pop();
        total += added_profit;
        pq.push({profit(c[0] + 1, c[1] + 1), {c[0] + 1, c[1] + 1}});
    }
    return total / classes.size();
}
};

// low denomenator

// 1/2 + 3/5 + 2/2

// 0.5 + 0.6 + 1 +

// 0.66 + 0.66 + 1

// --------------------

// 2/4 + 3/9 + 4/5 + 2/10

// 3/5 + 3/9 + 4/5 + 2/10

// 5/7 + 3/9 + 5/6 + 2/10




// 3/5 + 4/5

//     4/6 + 4/5 = 1.466
//         0.5 + 1/6 

//     3/5 + 5/6 = 1.433
//         3/5 + 0.666 + 1/6



// 3/6 + 1/6 = 0.5 + 1/6 = 0.666 
// 3/5 + 1/6

// 4/6 = 0.666 + 1/6 = 0.8333