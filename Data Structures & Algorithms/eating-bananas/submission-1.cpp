class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k_max = *max_element(piles.begin(), piles.end());
        int k_min = 1;
        int k = k_max;

        while (k_min <= k_max) {
            int k_mid = k_min + ((k_max - k_min) / 2);
            int hours = 0;
            for (int i=0; i<piles.size(); i++) {
                hours += piles[i] / k_mid;
                if (piles[i] % k_mid != 0) {
                    hours++;
                }
            }
            
            if (hours > h) {
                k_min = k_mid + 1;
            }
            else {
                k_max = k_mid - 1;
                if (k > k_mid) {
                    k = k_mid;
                }
            }
            
        }

        return k;
    }
};
