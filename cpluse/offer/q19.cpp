#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool match(char* str, char* pattern) {
    if(*pattern == '\0' && *str == '\0') return true;
    else if(*pattern == '\0') return false;
    if(*(pattern + 1) == '*') {
        if(*str == *pattern || (*pattern == '.' && *str != '\0')) {
            return match(str + 1, pattern + 2) || \
                   match(str + 0, pattern + 2) || \
                   match(str + 1, pattern + 0);
        }else
        {
            return match(str, pattern + 2);
        }
        
    }
    if((*pattern == '.' && *str != '\0')  || *str == *pattern) {
        return match(str+1, pattern+1);
    }
    return false;
}

int main(void) {
    char str[20] = "a";
    char pattern[20] = ".*";
    cout<<match(str, pattern)<<endl;
    return 0;
}