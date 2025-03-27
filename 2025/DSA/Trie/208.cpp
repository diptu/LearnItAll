/*
208. Implement Trie (Prefix Tree)
reference : https://www.youtube.com/watch?v=giiaIofn31A
*/

#define SIZE 26

class Trie
{
private:
    struct Node
    {
        char data;
        Node *child[SIZE];
        bool isWord;
        Node(char c) : data(c), isWord(false)
        {
            for (int i = 0; i < SIZE; i++)
            {
                child[i] = nullptr;
            }
        }
    };
    Node *root;

public:
    Trie()
    {
        // initialize root with null char
        root = new Node('\0');
    }

    void insert(string word)
    {
        // Initialize the currentNode with the root node
        Node *currentNode = root;
        for (auto c : word)
        {
            // If node for current character does not exist
            if (currentNode->child[c - 'a'] == nullptr)
            {
                // then make a new node for current character
                currentNode->child[c - 'a'] = new Node(c);
            }

            // Keep the reference for the newly created node.
            currentNode = currentNode->child[c - 'a'];
        }
        currentNode->isWord = true;
    }

    bool search(string word)
    {
        Node *node = getNode(word);
        return (node != nullptr && node->isWord);
    }

    bool startsWith(string prefix)
    {
        return (getNode(prefix) != nullptr);
    }

private:
    Node *getNode(string word)
    {
        Node *currentNode = root;
        for (auto c : word)
        {
            if (currentNode->child[c - 'a'] == nullptr)
                return nullptr;

            // Keep the reference of next char.
            currentNode = currentNode->child[c - 'a'];
        }
        // return very last Node
        return currentNode;
    }
};