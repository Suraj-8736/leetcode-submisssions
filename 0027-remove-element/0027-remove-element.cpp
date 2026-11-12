class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==val){
              count++;
            }
            else{
                nums[i-count]=nums[i];
            }
        }
        return (nums.size()-count);
        
    }
};