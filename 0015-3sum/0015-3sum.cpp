// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> vec;
//         for(int i=0;i<nums.size();i++){
//             int j=i+1;
//             int k=i+2;

//             while(i!=j && i!=k && j<nums.size()){
//                 k=i+2;
//                 while(j!=k && k<nums.size()){
//                     if((nums[i]+nums[j]+nums[k])==0){
//                        vector<int> v={nums[i],nums[j],nums[k]};
//                        sort(v.begin(),v.end());
//                        if(vec.empty()){
//                         vec.push_back(v);
//                        }
//                        else{
//                         int flag=0;
//                         for(int m=0;m<vec.size();m++){
//                             if(v==vec[m]){
//                               flag++;
//                             }
//                         }
//                         if(flag==0){
//                             vec.push_back(v);
//                         }
//                        }
                       
//                     }
//                     k++;
//                 }
//                 j++;
//             }
            
//         }
//         return vec;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> vec;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-2; i++) {

            // Skip duplicate elements
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0) {

                    vec.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // Skip duplicates
                    while(j < k && nums[j] == nums[j-1])
                        j++;

                    while(j < k && nums[k] == nums[k+1])
                        k--;
                }

                else if(sum < 0) {
                    j++;
                }

                else {
                    k--;
                }
            }
        }

        return vec;
    }
};