class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix_product;
        vector<int> suffix_product;
        vector<int> total_product;

        for (int i=0; i<nums.size(); i++) {
            int product = 1;
            if (i==0) {
                prefix_product.push_back(product);
            }
            else {
                for (int j=0; j<i; j++) {
                    product *= nums[j];
                }
                prefix_product.push_back(product);
            }
        }

        for (int i=nums.size()-1; i>=0; i--) {
            int product = 1;
            if (i==nums.size()-1) {
                suffix_product.push_back(product);
            }
            else {
                for (int j=nums.size()-1; j>i; j--) {
                    product *= nums[j];
                }
                suffix_product.insert(suffix_product.begin(), product);
            }
        }

        for (int i=0; i<nums.size(); i++) {
            total_product.push_back(prefix_product[i]*suffix_product[i]);
        }

        return total_product;
    }
};
