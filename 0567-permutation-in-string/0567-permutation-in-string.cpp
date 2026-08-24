class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        // Count characters of s1
        for (char c : s1) {
            count1[c - 'a']++;
        }

        int windowSize = s1.length();

        // First window
        for (int i = 0; i < windowSize; i++) {
            count2[s2[i] - 'a']++;
        }

        // Check first window
        if (count1 == count2) {
            return true;
        }

        // Slide the window
        for (int i = windowSize; i < s2.length(); i++) {

            // Add new character
            count2[s2[i] - 'a']++;

            // Remove old character
            count2[s2[i - windowSize] - 'a']--;

            // Check if frequencies match
            if (count1 == count2) {
                return true;
            }
        }

        return false;
    }
};