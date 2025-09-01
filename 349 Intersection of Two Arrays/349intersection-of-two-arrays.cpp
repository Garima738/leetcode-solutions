class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        int n1=nums1.size();
        int n2=nums2.size();
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    bool found=false;
                    for(int k=0;k<res.size();k++){
                        if(res[k]==nums1[i]){
                            found=true;
                            break;
                        
                        }
                    }

                    if(!found){
                        res.push_back(nums1[i]);
                    }
                    break;


                    
                }
            }
        }
        return res;

    }
};