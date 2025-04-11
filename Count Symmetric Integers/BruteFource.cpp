#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int countSymetricIntegers(int low, int high){
        int cnt = 0;
        for(int num=low;num<=high;num++){
            string s = to_string(num);
            int l = s.length();

            if(l%2 != 0){
                continue;
            }

            int leftSum = 0;
            int rightSum = 0;

            for(int i=0;i<l/2;i++){
                leftSum += s[i]-'0';
            }
            for(int i=l/2;i<l;i++){
                rightSum += s[i]-'0';
            }
            if(leftSum == rightSum){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution sol;
    int low = 1200, high = 1230;
    cout << "Symmetric integers between "<<low <<" and "<<high<<": "<<sol.countSymetricIntegers(low, high)<<endl;
    return 0;
}