class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int &a, int &b)->bool{
            string aa=to_string(a),bb=to_string(b);
            return aa+bb>bb+aa;
        });
        string ans="";
        for(auto x:nums){
            ans+=to_string(x);
        }
        int i=0;
        while(i<ans.length() && ans[i]=='0'){
            i++;
        }
        if(i>0){
            i--;
        }
        return ans.substr(i);
    }
};