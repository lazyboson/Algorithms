class Solution {
public:
    bool isValid(string s) {
        stack<char> verifier;
        map<char, char> paranth;
        paranth.insert({')', '('});
        paranth.insert({']', '['});
        paranth.insert({'}', '{'});
        for (auto c:s) {
            auto it = paranth.find(c);
            if(it != paranth.end()){
                if(verifier.empty() || verifier.top() != it->second)
                    return false;
                verifier.pop();
            } else {
                verifier.push(c);
            }
        }
        if(verifier.empty())
           return true;
        return false;
    }
};
