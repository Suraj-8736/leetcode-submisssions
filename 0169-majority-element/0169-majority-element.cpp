class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int fq=0,ans=0;
        for(int val:nums){
            if(fq==0) ans=val;
            if(ans==val) fq++;
            else fq--;
        }
        return ans;
    }
};