class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;  // Use a string to track the current combination
        generateParenthesisHelper(result, current, n, n);
        return result;
    }

private:
    void generateParenthesisHelper(vector<string>& result, string& current, int openCount, int closeCount) {
        if (openCount == 0 && closeCount == 0) {
            result.push_back(current);
            return;
        }

        if (openCount > 0) {
            current.push_back('(');
            generateParenthesisHelper(result, current, openCount - 1, closeCount);
            current.pop_back();
        }

        if (closeCount > openCount) {
            current.push_back(')');
            generateParenthesisHelper(result, current, openCount, closeCount - 1);
            current.pop_back();
        }
    }
};
