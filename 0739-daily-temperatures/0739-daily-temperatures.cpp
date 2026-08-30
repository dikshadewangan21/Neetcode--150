class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
         int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;  // stores indices

        for (int i = 0; i < n; i++) {

            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()]) {

                int prevDay = st.top();
                st.pop();

                result[prevDay] = i - prevDay;
            }

            st.push(i);
        }

        return result;
    }
};