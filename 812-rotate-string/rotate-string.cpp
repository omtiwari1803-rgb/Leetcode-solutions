class Solution {
public:
    bool rotateString(string s, string goal) {
        string doubleS= s+s;
        if(s.length() != goal.length()) return false;

        return doubleS.find(goal) != string::npos;
    }
};