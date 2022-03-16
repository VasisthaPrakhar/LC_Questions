class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        int n=pu.size();
        stack<int>s;
        int j=0,i=0;
        while(i<n && j<n){
            if(!s.empty()){
                s.push(pu[i++]);
                while(!s.empty() && s.top()==po[j]){
                    j++;
                    s.pop();
                }
            }else{
                if(pu[i]!=po[j])
                    s.push(pu[i++]);
                else
                    i++,j++;
            }
        }
        return s.size()==0;
    }
};