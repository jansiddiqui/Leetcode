#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    // Step 1: Find the LCS using dynamic programming
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Step 2: Reconstruct the SCS
    int i = m, j = n;
    string scs;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            scs.push_back(str1[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            scs.push_back(str1[i - 1]);
            i--;
        } else {
            scs.push_back(str2[j - 1]);
            j--;
        }
    }

    // Append remaining characters from str1 and str2
    while (i > 0) {
        scs.push_back(str1[i - 1]);
        i--;
    }
    while (j > 0) {
        scs.push_back(str2[j - 1]);
        j--;
    }

    // Reverse to get the correct order
    reverse(scs.begin(), scs.end());
    return scs;
}

int main() {
    string str1 = "abac";
    string str2 = "cab";
    cout << "Shortest Common Supersequence: " << shortestCommonSupersequence(str1, str2) << endl;
    return 0;
}