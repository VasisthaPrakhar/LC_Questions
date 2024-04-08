class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sa) {
        int n=st.size();
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        int j=0,k=0;
        while(j<n && k<10*n){
            if(sa[j]==st[q.front()]){
                q.pop();
            }else{
                int temp=q.front();
                q.pop();
                q.push(temp);
                j--;
            }
            j++,k++;
        }
        return q.size();
    }
};