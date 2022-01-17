class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        stack<int>s;
        s.push(a[0]);
        for(int i=1;i<n;i++){
            if(!s.empty() && (a[i]<0 && s.top()>0)){
                int k,f=1,f1=1;
                while(!s.empty() && abs(s.top())<=abs(a[i])){
                    k=s.top();
                    if(k*a[i]>=0){
                        s.push(a[i]);
                        f1=0;
                        break;
                    }
                    else if(abs(k)==abs(a[i])){
                        s.pop();
                        f=0;
                        break;
                    }
                    s.pop();
                }
                if(s.empty() && abs(k)<abs(a[i])) {
                    s.push(a[i]);
                }
                else if(!s.empty() && f1 && f && a[i]*s.top()>=0){
                    s.push(a[i]);
                }
            }else{
                s.push(a[i]);
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};