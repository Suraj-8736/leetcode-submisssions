class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr = nums;

        auto digitSum = [](int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };

        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int s1 = digitSum(a);
            int s2 = digitSum(b);

            if (s1 == s2)
                return a < b;

            return s1 < s2;
        });

        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != arr[i]) {
                swaps++;

                int j = pos[arr[i]];

                pos[nums[i]] = j;
                pos[arr[i]] = i;

                swap(nums[i], nums[j]);
            }
        }

        return swaps;
    }
};