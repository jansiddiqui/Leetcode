#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long tSum = 0;
        int minAbsVal = INT_MAX;
        int negCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tSum += abs(matrix[i][j]);
                if (matrix[i][j] < 0) {
                    negCount++;
                }
                minAbsVal = min(minAbsVal, abs(matrix[i][j]));
            }
        }

        // If the count of negative numbers is odd, subtract twice the smallest absolute value
        if (negCount % 2 != 0) {
            tSum -= 2 * minAbsVal;
        }

        return tSum;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix1 = {{1, -1}, {-1, 1}};
    cout << sol.maxMatrixSum(matrix1) << endl;

    vector<vector<int>> matrix2 = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
    cout << sol.maxMatrixSum(matrix2) << endl;

    return 0;
}
