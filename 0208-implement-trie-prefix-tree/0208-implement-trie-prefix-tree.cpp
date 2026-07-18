class Node{
public:
    unordered_map<char,Node*> children;
    bool endOfWord;

    Node(){
        endOfWord=false;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
        
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->children.count(word[i])==0){
                temp->children[word[i]]=new Node();
            }
            temp=temp->children[word[i]];
        }
        temp->endOfWord=true;
        
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->children.count(word[i])){
                temp=temp->children[word[i]];
            }else{
                return false;
            }
        }
        return temp->endOfWord;
        
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(int i=0;i<prefix.size();i++){
           if(temp->children.count(prefix[i])==0){
            return false;
           }
           temp=temp->children[prefix[i]];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */