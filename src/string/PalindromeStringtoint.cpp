#include <iostream>
#include <string>
#include <algorithm>

//O(n) times with no additional O(1) space -- checking palindrome 
bool IsPalindrome(const std::string &s){
    for(int i=0, j=s.size()-1; i<j; ++i, --j){
        if(s[i] != s[j])
            return false;
    }
    return true;
}

int SSDDecodeColId(const std::string & col){
    int result = 0;
    for(char c : col){
        result = result *26 + c-'A';
    }
    return result;
}

std::string IntToString(int x){
    bool is_neagtive = false;
    if(x <=0)
        is_neagtive = true;
    std::string s;

    do {
        /* code */
        s += '0' + abs(x%10);
        x/=10;
    } while (x);
    if(is_neagtive)
        s += '-';
    return std::string(s.rbegin(), s.rend());
}

int StringToInt(const std::string &s){
    int result = 0;
    for(int i= s[0] == '-'?1:0; i<s.size(); i++){
        const int digit = s[i] - '0';
        result = result *10 +digit;

    }
    return s[0] == '-'? -result : result;
}

int main(){
    std::string s;
    std::cin >> s;
    if(IsPalindrome(s))
        std::cout << "Given String is Palindrome" << std::endl;
    else
        std:: cout << "The String is not Palindrome" << std::endl;
   
    std::string s1 = "1234";
    int x = 1234;
    std::cout << StringToInt(s1)<< std::endl;
    std::cout << IntToString(x) << std::endl;
    std::cout << SSDDecodeColId("AAZ") <<std::endl;
    return 0;
}