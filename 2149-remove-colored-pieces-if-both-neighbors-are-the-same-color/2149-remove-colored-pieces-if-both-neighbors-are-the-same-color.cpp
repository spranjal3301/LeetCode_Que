class Solution {
public:
    bool winnerOfGame(string colors) {
      int n = colors.size();
    long long aliceMoves = 0; // Use long long to prevent integer overflow
    long long bobMoves = 0;   // Use long long to prevent integer overflow

    int consecutiveA = 0;
    int consecutiveB = 0;

    // Count consecutive pieces of the same color
    for (int i = 0; i < n; i++) {
        if (colors[i] == 'A') {
            consecutiveA++;
            consecutiveB = 0; // Reset consecutiveB
        } else {
            consecutiveB++;
            consecutiveA = 0; // Reset consecutiveA
        }

        // Check if Alice can make moves
        if (consecutiveA >= 3) {
            aliceMoves += consecutiveA - 2;
        }

        // Check if Bob can make moves
        if (consecutiveB >= 3) {
            bobMoves += consecutiveB - 2;
        }
    }

    // If Alice has more moves, she wins; otherwise, Bob wins
    return aliceMoves > bobMoves;
    }
};