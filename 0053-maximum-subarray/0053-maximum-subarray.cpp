class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0,ans=INT_MIN;
        for(int val:nums){
            cs+=val;
            ans=max(cs,ans);
            if(cs<0){
                cs=0;
            }
        }
        return ans;
    }
};