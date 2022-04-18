class Solution {
public:
    int numberOfRounds(string lt, string l) {
        vector<int>a={0,15,30,45,60};
        int ans=0;
        int h1=stoi(lt.substr(0,2));
        int m1=stoi(lt.substr(3,2));
        int h2=stoi(l.substr(0,2));
        int m2=stoi(l.substr(3,2));
        int f=lower_bound(a.begin(),a.end(),m1)-a.begin();
        int f1=lower_bound(a.begin(),a.end(),m2)-a.begin();
        if(h1<h2){
            ans+=4-f;
            ans+=(h2-h1-1)*4;
            if(a[f1]==m2){
                ans+=f1;
            }else{
                ans+=(f1-1);
            }
        }else if(h2<h1){
            ans+=4-f;
            ans+=(24-h1-1)*4;
            ans+=(h2)*4;
            if(a[f1]==m2){
                ans+=f1;
            }else{
                ans+=(f1-1);
            }
        }else{
            if(m1>m2){
                ans+=4-f;
                ans+=(24-h1-1)*4;
                ans+=h2*4;
                if(a[f1]!=m2){
                    f1--;
                }
                ans+=f1;
            }else{
                if(a[f1]!=m2){
                    f1--;
                }
                ans+=f1-f;
            }
        }
        
        return ans<0?0:ans;
    }
};