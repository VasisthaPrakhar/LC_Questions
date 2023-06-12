class Solution {
public:
    
    vector<string> summaryRanges(vector<int>& a) {
        int n=a.size();
        vector<string>ans;
        if(n==0){
            return ans;
        }
        if(n==1){
            ans.push_back(to_string(a[0]));
            return ans;
        }
        int j=0,i=0;
        while(j<n){
            i=j;
            int k=j++;
            while(j<n && a[k]+1==a[j]){
                j++,k++;
            }
            j--;
            
            string st;
            if(a[j]!=a[i])
                st=to_string(a[i])+"->"+to_string(a[j]);
            else
                st=to_string(a[j]);
            ans.push_back(st);
            j++;
        }
        return ans;
    }
};