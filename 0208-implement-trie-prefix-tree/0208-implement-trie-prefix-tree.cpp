class TrieNode{
public:
    char ch;
    vector<TrieNode*>v;
    bool end;
    TrieNode(char c){
        ch=c;
        for(int i=0;i<26;i++) v.push_back(nullptr);
        end=false;
    }
};
class Trie {
public:
TrieNode* root;
    Trie() {
        root=new TrieNode('/');
    }

    void insertion(TrieNode* root,string&word,int i){
        int n=word.size();
        if(i==n){
            root->end=true;
            return;
        }

        int index=word[i]-'a';
        TrieNode* child;
        if(root->v[index]==nullptr){
            child=new TrieNode(word[i]);
            root->v[index]=child;
        }
        else{
            child=root->v[index];
        }

        insertion(child,word,i+1);

    }
    
    void insert(string word) {
        insertion(root,word,0);
    }

    bool searching(TrieNode* root,string&word,int i){
        int n=word.size();
        if(i==n){
            return root->end;
        }

        int index=word[i]-'a';

        if(root->v[index]==nullptr) return false;
        TrieNode* child=root->v[index];
        return searching(child,word,i+1);
    }
    
    bool search(string word) {
        return searching(root,word,0);
    }

    bool prefixsearch(TrieNode* root,string&word,int i){
        int n=word.size();
        if(i==n){
            return true;
        }

        int index=word[i]-'a';

        if(root->v[index]==nullptr) return false;
        TrieNode* child=root->v[index];
        return prefixsearch(child,word,i+1);
    }
    
    bool startsWith(string prefix) {
        return prefixsearch(root,prefix,0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */