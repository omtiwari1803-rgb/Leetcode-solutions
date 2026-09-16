class Solution {
public:
    int helper(const string &s, int i, long long num, int sign) {

        // Base case
        if (i >= s.size() || !isdigit(s[i]))
            return sign * num;

        int digit = s[i] - '0';

        // Check overflow BEFORE updating num
        if (num > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        // Add current digit
        num= (num*10)+digit;

        // Recursive call
        return helper(s,i + 1,num,sign);
    }

    int myAtoi(string s) {
        int i= 0;

        // 1. Skip spaces
        while (i < s.size() && s[i] == ' ')
            i++;

        // 2. Determine sign
        int sign = 1;

        if (i<s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // 3. Process digits recursively
        return helper(s,i,0,sign);
    }
};