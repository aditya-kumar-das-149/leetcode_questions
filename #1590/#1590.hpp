#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for (int x : nums) sum += x;
        int r = sum % p;
        if (r == 0) return 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        long long pref = 0;
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            pref = (pref + nums[i]) % p;
            int need = (pref + p - r) % p;
            auto it = mp.find(need);
            if (it != mp.end()) {
                ans = min(ans, i - it->second);
            }
            mp[pref] = i;
        }
        return ans == n ? -1 : ans;
    }
};
