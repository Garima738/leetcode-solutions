// class Solution {
// public:
//     vector<string> result;

//     bool find(int i, int j, string& word, int index,
//               vector<vector<char>>& board) {

//         if(index == word.length()) {
//             return true;
//         }

//         int m = board.size();
//         int n = board[0].size();

//         if(i < 0 || j < 0 || i >= m || j >= n ||
//            board[i][j] == '$') {
//             return false;
//         }

//         if(board[i][j] != word[index]) {
//             return false;
//         }

//         char temp = board[i][j];
//         board[i][j] = '$';

//         bool found =
//             find(i + 1, j, word, index + 1, board) ||
//             find(i - 1, j, word, index + 1, board) ||
//             find(i, j + 1, word, index + 1, board) ||
//             find(i, j - 1, word, index + 1, board);

//         board[i][j] = temp;

//         return found;
//     }

//     vector<string> findWords(vector<vector<char>>& board,
//                              vector<string>& words) {

//         int m = board.size();
//         int n = board[0].size();

//         for(string word : words) {

//             bool foundWord = false;

//             for(int i = 0; i < m && !foundWord; i++) {

//                 for(int j = 0; j < n; j++) {

//                     if(board[i][j] == word[0]) {

//                         if(find(i, j, word, 0, board)) {

//                             result.push_back(word);

//                             foundWord = true;
//                             break;
//                         }
//                     }
//                 }
//             }
//         }

//         return result;
//     }
// };
class Solution {
public:

    struct Node {
        Node* child[26];
        string word;

        Node() {
            word = "";
            for(int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    vector<string> result;

    void insert(Node* root, string& word) {

        Node* curr = root;

        for(char ch : word) {

            int index = ch - 'a';

            if(curr->child[index] == nullptr) {
                curr->child[index] = new Node();
            }

            curr = curr->child[index];
        }

        curr->word = word;
    }


    void dfs(int i, int j, Node* curr,
             vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        // Boundary / visited
        if(i < 0 || j < 0 || i >= m || j >= n ||
           board[i][j] == '#') {
            return;
        }

        char ch = board[i][j];

        int index = ch - 'a';

        // Current prefix doesn't exist in Trie
        if(curr->child[index] == nullptr) {
            return;
        }

        curr = curr->child[index];

        // Complete word found
        if(curr->word != "") {

            result.push_back(curr->word);

            // Prevent duplicate
            curr->word = "";
        }

        // Mark visited
        board[i][j] = '#';

        // 4 directions
        dfs(i + 1, j, curr, board);
        dfs(i - 1, j, curr, board);
        dfs(i, j + 1, curr, board);
        dfs(i, j - 1, curr, board);

        // Backtrack
        board[i][j] = ch;
    }


    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        Node* root = new Node();

        // Put all words into Trie
        for(string& word : words) {
            insert(root, word);
        }

        int m = board.size();
        int n = board[0].size();

        // Start DFS from every cell
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                dfs(i, j, root, board);

            }
        }

        return result;
    }
};