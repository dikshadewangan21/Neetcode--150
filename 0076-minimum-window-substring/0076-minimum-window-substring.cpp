class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length())
            return "";

        int need[128] = {0};

        // Count characters required from t
        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int required = t.length();

        int minLength = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];

            // This character was needed
            if (need[c] > 0) {
                required--;
            }

            need[c]--;

            // Window is valid
            while (required == 0) {

                // Update minimum window
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                // Remove left character
                char leftChar = s[left];
                need[leftChar]++;

                if (need[leftChar] > 0) {
                    required++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX)
            return "";

        return s.substr(start, minLength);
    }
};