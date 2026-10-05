class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        // Step 1: Count frequency
        for(char task : tasks) {
            freq[task - 'A']++;
        }

        // Step 2: Find maximum frequency
        int maxFreq = 0;

        for(int f : freq) {
            maxFreq = max(maxFreq, f);
        }

        // Step 3: Count tasks having maximum frequency
        int maxCount = 0;

        for(int f : freq) {
            if(f == maxFreq) {
                maxCount++;
            }
        }

        // Step 4: Calculate minimum CPU cycles
        int result = (maxFreq - 1) * (n + 1) + maxCount;

        return max((int)tasks.size(), result);
    }
};