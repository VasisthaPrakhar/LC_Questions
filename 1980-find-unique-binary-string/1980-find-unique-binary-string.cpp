class Solution {
public:
    string conv(int i){
        string s="";
        while(i){
            int k=i%2;
            s=to_string(k)+s;
            i/=2;
        }
        return s;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size(),k=nums[0].length();
        int lim=pow(2,k);
        set<string>st(nums.begin(),nums.end());
        for(int i=0;i<lim;i++){
            string s=conv(i);
            while(s.length()!=k){
                s=to_string(0)+s;
            }
            if(st.find(s)==st.end()){
                return s;
            }
        }
        return "";
    }
};