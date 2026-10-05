class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // int n = nums.size();
        // int i = 0;
        // int j = 0;

        // vector<int> ans;
        // vector<int> slide;

        // while (j < n) {

        //     slide.push_back(nums[j]);

        //     if (j - i + 1 < k) {
        //         j++;
        //     }

        //     else if (j - i + 1 == k) {

        //         int maxi = INT_MIN;

             
        //         for (int p = 0; p < slide.size(); p++) {
        //             maxi = max(maxi, slide[p]);
        //         }

        //         ans.push_back(maxi);

        //         slide.erase(slide.begin());

        //         i++;
        //         j++;
        //     }
        // }

        // return ans;


        vector<int>ans;
        deque<int>q;
        int n = nums.size();
        int i=0;
        int j= 0;
        while(j<n){
            while(q.size()>0 && q.back()<nums[j]){
                q.pop_back();
            }
            q.push_back(nums[j]);

            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                ans.push_back(q.front());
                if(q.front()==nums[i]){
                    q.pop_front();

                }
                i++;
                j++;
                
            }
        }
        return ans;
    }
};