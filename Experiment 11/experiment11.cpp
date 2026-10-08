#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node of Huffman Tree
struct Node {
    char data;
    int frequency;

    Node *left, *right;

    Node(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

// Generate Huffman Codes
void generateCodes(Node* root, string code,
                   unordered_map<char, string>& huffmanCode) {

    if (root == nullptr)
        return;

    // Leaf node
    if (root->left == nullptr && root->right == nullptr) {
        huffmanCode[root->data] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Huffman Coding function
void huffmanCoding(string text) {

    // Count frequency of each character
    unordered_map<char, int> frequency;

    for (char ch : text) {
        frequency[ch]++;
    }

    // Create priority queue
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a node for every character
    for (auto pair : frequency) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {

        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node(
            '\0',
            left->frequency + right->frequency
        );

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Root of Huffman Tree
    Node* root = pq.top();

    // Generate codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // Display frequencies and codes
    cout << "\nCharacter  Frequency  Huffman Code\n";
    cout << "---------------------------------\n";

    for (auto pair : frequency) {
        cout << "    " << pair.first
             << "          " << pair.second
             << "          " << huffmanCode[pair.first]
             << endl;
    }

    // Display encoded text
    string encodedText = "";

    for (char ch : text) {
        encodedText += huffmanCode[ch];
    }

    cout << "\nOriginal Text: " << text;
    cout << "\nEncoded Text: " << encodedText << endl;
}

int main() {

    string text;

    cout << "Enter text: ";
    getline(cin, text);

    huffmanCoding(text);

    return 0;
}