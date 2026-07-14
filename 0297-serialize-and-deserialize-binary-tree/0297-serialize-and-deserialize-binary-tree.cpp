/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* currNode=q.front();
            q.pop();
            if(currNode==NULL) s.append("#,");
            else s.append(to_string(currNode->val)+',');
            if(currNode!=NULL){
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;

        vector<string> nodes;
        string temp="";

        for(char ch:data){
            if(ch==','){
                nodes.push_back(temp);
                temp="";
            }else{
                temp+=ch;
            }
        }
        TreeNode* root=new TreeNode(stoi(nodes[0]));

        queue<TreeNode*> q;
        q.push(root);
        int i=1;

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            if(nodes[i]!="#"){
                curr->left=new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;

            if(nodes[i]!="#"){
                curr->right=new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;

        }
        return root;

        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));