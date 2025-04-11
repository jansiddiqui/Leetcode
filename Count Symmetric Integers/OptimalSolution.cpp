#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int cnt = 0;
            for(int num=low;num<=high;num++){
                if(num>=10 && num<=99 && num%11 == 0){ //for two digit no.
                    cnt++;
                }else if(num >= 1000 && num<=9999){// for four digit no.
                    int first = num/1000;
                    int second = (num/100)%10;
                    int third = (num/10)%10;
                    int fourth = (num/1)%10;
                    if(first + second == third + fourth){
                        cnt++;
                    }
                }
            }
            return cnt;
        }
    };

int main(){
    Solution s;
    int low = 1200, high = 1230;
    cout<<"Symetric Integer between "<<low<<" and "<<high<<": "<< s.countSymmetricIntegers(low, high);
    return 0;
}