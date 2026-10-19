class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> v;
        int i ,s=0,eq=0;
        // sort(nums.begin(),nums.end()); it can be avoided 
        for(int val:nums){
            if(val<target) s++;
            if(val==target) eq++;
        }
        for(i=0;i<eq;i++){
            v.push_back(s+i);
        }
        return v;
    }
};