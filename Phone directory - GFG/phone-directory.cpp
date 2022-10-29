//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
struct Node {
	Node *links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}

	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}
    void fun(Node* node,string &pre,vector<string>&ans){
        if(node->isEnd()){
            ans.push_back(pre);
        }
        for(int i=0;i<26;i++){
            if(node->links[i]){
                pre.push_back('a'+i);
                fun(node->links[i],pre,ans);
                pre.pop_back();
            }
        }
    }
	vector<string> startsWith(string prefix) {
		Node* node = root;
		vector<string>ans;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return ans;
			}
			node = node->get(prefix[i]);
		}
		fun(node,prefix,ans);
		return ans;
	}
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string co[], string s)
    {
        // code here
        Trie trie;
        for(int i=0;i<n;i++){
            trie.insert(co[i]);
        }
        string t="";
        vector<vector<string>>ans;
        for(auto x:s){
            t.push_back(x);
            vector<string>res=trie.startsWith(t);
            if(res.size()==0){
                res.push_back("0");
            }
            ans.push_back(res);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends