class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int j=0;
      int temp=nums[0];
      for(int i=0;i<nums.size();i++){
          if(temp!=nums[i]){
            nums[j+1]=nums[i];
            j++;
            temp=nums[i];
          }
      }
      return (j+1);
    }
};