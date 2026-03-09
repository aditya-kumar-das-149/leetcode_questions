class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        long long a=1;
        if(nums.size()==0 ) return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<k) count++;
        }
        for(int i=0;i<nums.size();i++){
            a=nums[i];
            for(int j=i+1;j<nums.size();j++){
                a*=nums[j];
                if(a<k){
                    count++;
                }else{
                    break;
                }
            }
        }
        return count;
    }
};