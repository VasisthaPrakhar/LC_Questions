class Solution {
public:
    bool winnerOfGame(string c) {
        vector<int>a,b;
        int n=c.length();
        int j=0;
        while(j<n){
            if(c[j]=='A'){
                int cnt=0;
                while(j<n && c[j]=='A'){
                    cnt++;
                    j++;
                }
                //cout<<cnt<<"cibasiubci ";
                a.push_back(cnt);
                j--;
            }else{
                int cnt=0;
                while(j<n && c[j]=='B'){
                    cnt++;
                    j++;
                }
                b.push_back(cnt);
                //cout<<cnt<<"cibasiubci ";
                j--;
            }
            j++;
        }
        int c1=0,c2=0;
        for(auto x:a){
            if(x>2){
                c1+=x-2;
            }
        }
        for(auto x:b){
            if(x>2){
                c2+=x-2;
            }
        }
        //cout<<c1<<" "<<c2<<endl;
        return c1>c2;
    }
};