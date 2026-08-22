class Solution {
public:
    bool palindrome(int l, int r, string &s) {

        if (l >= r)
            return true;

        if (!isalnum(s[l])) {
            return palindrome(l + 1, r, s);
        }

        if (!isalnum(s[r])) {
            return palindrome(l, r - 1, s);
        }

        if (tolower(s[l]) != tolower(s[r]))
            return false;

        return palindrome(l+1, r-1, s);
    }

    bool isPalindrome(string s) {
        return palindrome(0, s.length()-1, s);
    }
};