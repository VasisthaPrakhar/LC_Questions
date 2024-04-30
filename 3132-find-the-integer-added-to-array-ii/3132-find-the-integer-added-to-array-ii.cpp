class Solution {
public:
    bool fun(vector<int>&a, vector<int>&b,int k){
        unordered_map<int,int>m;
        for(auto x:a){
            m[x+k]++;
        }
        for(auto x:b){
            if(m.find(x)==m.end()){
                return false;
            }else{
                m[x]--;
                if(m[x]==0){
                    m.erase(x);
                }
            }
        }
        return true;
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int a=INT_MAX,b=INT_MAX,c=INT_MAX;
        if(fun(nums1,nums2,nums2[0]-nums1[0])){
            a=nums2[0]-nums1[0];
        }
        if(fun(nums1,nums2,nums2[0]-nums1[1])){
            b=nums2[0]-nums1[1];
        }
        if(fun(nums1,nums2,nums2[0]-nums1[2])){
            c=nums2[0]-nums1[2];
        }
        return min({a,b,c});
    }
};