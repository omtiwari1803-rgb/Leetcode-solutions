class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            } 
            else {
                // Check whether the next character is ')'
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;  // Consume the second ')'
                } 
                else {
                    insertions++;  // Insert a missing ')'
                }

                // Match the closing pair with an opening '('
                if (open > 0) {
                    open--;
                } 
                else {
                    insertions++;  // Insert a missing '('
                }
            }
        }

        // Each unmatched '(' requires two ')'
        insertions += open * 2;

        return insertions;
    }
};
