class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                bool valid = true;

                if(j - i + 1 >= 3) {
                    for(int x = i; x <= j; x++) {
                        for(int y = x + 1; y <= j; y++) {

                            if(gcd(nums[x], nums[y]) != 1) {
                                valid = false;
                                break;
                            }
                        }

                        if(!valid)
                            break;
                    }
                }

                if(valid)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};