#include <bits/stdc++.h>
using namespace std;
// use the concept of sliding window ..... Another way of doing this is by replacing odd with 1 and even with 0 question converts to subarray with k sum 
class Solution {
public:
    int numberOfSubarrays(vector<int>& array, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  
        int count = 0;  
        int result = 0;  

        for(int num : array) {
            if(num % 2 != 0) {
                count++;
            }
            if(prefixCount.find(count - k) != prefixCount.end()) {
                result += prefixCount[count - k];
            }
            prefixCount[count]++;
        }

        return result;
    }
};
