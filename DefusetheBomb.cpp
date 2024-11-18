#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0) {
            return result; // All elements should be zero when k is zero.
        }
        
        // Helper lambda to get the sum of elements with circular indexing.
        auto getSum = [&code, n](int start, int count, bool forward) {
            int sum = 0;
            if (forward) {
                for (int i = 1; i <= count; ++i) {
                    sum += code[(start + i) % n];
                }
            } else {
                for (int i = 1; i <= count; ++i) {
                    sum += code[(start - i + n) % n];
                }
            }
            return sum;
        };

        if (k > 0) {
            // Sum the next k elements
            for (int i = 0; i < n; ++i) {
                result[i] = getSum(i, k, true);
            }
        } else {
            // Sum the previous -k elements
            k = -k; // Convert k to positive for convenience
            for (int i = 0; i < n; ++i) {
                result[i] = getSum(i, k, false);
            }
        }

        return result;
    }
};

int main(){
    Solution Solution;
    vector<int> arr = {2, 3, 4, 0, 7};
    int k=3;
    vector<int> result = Solution.decrypt(arr, k);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}
