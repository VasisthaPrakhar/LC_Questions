class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int>freq(26,-1);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']=i;
        }
        int left=0,right=-1;
        vector<int>ans;
        for(int i=0;i<n;i++){
            right=freq[s[i]-'a']>right?freq[s[i]-'a']:right;
            if(right==i){
                ans.push_back(i-left+1);
                right=-1;
                left=i+1;
            }
        }
        return ans;
    }
};