class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;

        for(int i = 0; i < n; i++) {

            // Collision tabhi hogi:
            // stack ka top +ve ho  AND current asteroid -ve ho
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0) {

                // Current asteroid bada hai
                // Example: 5 vs -8
                // 5 destroy hoga -> pop
                if(abs(asteroids[i]) > st.top()) {
                    st.pop();
                }

                // Dono same size ke hain
                // Example: 5 vs -5
                // Dono destroy honge
                else if(abs(asteroids[i]) == st.top()) {
                    st.pop();

                    // Current asteroid bhi destroy ho gaya
                    asteroids[i] = 0;
                    break;
                }

                // Stack wala asteroid bada hai
                // Example: 8 vs -5
                // Current asteroid destroy ho jayega
                else {
                    asteroids[i] = 0;
                    break;
                }
            }

            // Agar current asteroid destroy nahi hua
            // tabhi stack mein push karo
            if(asteroids[i] != 0) {
                st.push(asteroids[i]);
            }
        }

        // Stack se answer nikalo
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Stack se reverse order mein elements milte hain
        reverse(ans.begin(), ans.end());

        return ans;
    }
};