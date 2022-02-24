class Solution {
public:
    long long countVowels(string word) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n=word.length();
        long long ans=0;
        for(int i=0;i<n;i++){
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
                long long j=(i)<(n-i-1)?i:(n-i-1);
                long long k=(j*(2*(n-2)+(j-1)*(-2))/2); //sum of AP
                ans+=(n+k);  
            }
        }
        return ans;
    }
};