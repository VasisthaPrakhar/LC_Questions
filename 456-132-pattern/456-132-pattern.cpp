class Solution {
public:
    bool find132pattern(vector<int>& a) {
        int n=a.size();
        if(n<3){
            return false;
        }
        stack<int>s;
        int last=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(last>a[i]){
                return true;
            }else{
                while(!s.empty() && a[i]>s.top()){
                    last=s.top();
                    s.pop();
                }
            }
            s.push(a[i]);
        }
        return false;
    }
};