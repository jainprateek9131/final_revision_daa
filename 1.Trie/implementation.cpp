
The word "Trie" is an excerpt from the word "retrieval".

Trie, which is also known as “Prefix Trees”, is a tree-like data structure which proves to be quite efficient for solving problems related to strings.
It provides fast retrieval, and is mostly used for searching words in a dictionary, providing auto suggestions in a search engine, and even for IP routing.

It's implemented using Tree. Trie is a data structure which is very efficient for searching word . However, it has one very big disadvantage of using a lot 
of memory as every node contains character array of alphabet size. It marks down the ending of word by assigning it as leaf node.
Searching a word in trie has complexity of O(n) ,where n is the length of a word searched. Time as well as space complexity can be reduced by using Compressed Trie.

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>

using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(struct TrieNode *, string);

bool search(struct TrieNode *, string);

// Driver
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        // Input keys (use only 'a' through 'z' and lower case)
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }

        struct TrieNode *root = getNode();
        // Construct trie
        for (int i = 0; i < n; i++) insert(root, keys[i]);

        string abc;

        cin >> abc;
        // Search for different keys

        if (search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
        // char ex;
        // cin >> ex;
        // cout << ex << "\n";
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++



//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    // code here
    struct TrieNode *curNode = root;
    for(int i=0;i<key.size();i++){
        int index = key[i] - 'a';
        if(curNode->children[index] == NULL){
            curNode->children[index] = new TrieNode();;
        }
        curNode = curNode->children[index];
    }
    curNode->isLeaf = true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    // code here
    struct TrieNode *curNode = root;
    for(int i=0;i<key.size();i++){
        int index = key[i] -  'a';
        if(curNode->children[index] == NULL)return false;
        curNode = curNode->children[index];
    }
    if(curNode->isLeaf == true)return true;
    return false;
}
