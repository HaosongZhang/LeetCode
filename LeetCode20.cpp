class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == ')') {
                if(sta.empty() || sta.top() != '(') {
                    return false;
                }
                sta.pop();
            }
            else if(s[i] == '}') {
                if(sta.empty() || sta.top() != '{') {
                    return false;
                }
                sta.pop();
            }
            else if(s[i] == ']') {
                if(sta.empty() || sta.top() != '[') {
                    return false;
                }
                sta.pop();
            }
            else {
                sta.push(s[i]);
            }
        }
        if(sta.empty()) {
            return true;
        }
        return false;
    }
};
