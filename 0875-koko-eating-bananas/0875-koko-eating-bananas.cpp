class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right) {

            int mid = left + (right - left) / 2;

            long long hours = 0;

            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;
            }

            if (hours <= h) {
                // mid works, but maybe a smaller k can work
                right = mid - 1;
            }
            else {
                // mid is too slow
                left = mid + 1;
            }
        }

        return left;
    }
};