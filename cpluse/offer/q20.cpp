#include<iostream>
#include<vector>
using namespace std;

bool scanUnsignedInter(char* &string) {
    const char* before = string;
    while(*string != '\0' && (*string >= '0' && *string <= '9')) string++;
    return string > before;
}

bool scanInter(char* &string) {
    if(*string == '+' ||*string == '-')string++;
    return scanUnsignedInter(string);
}

bool isNumeric(char* string)
{
    bool numeric = scanInter(string);
    if(*string == '.') {
        string++;
        numeric = scanUnsignedInter(string) || numeric;
    }
    if(*string == 'E' || *string == 'e') {
        string++;
        numeric = numeric && scanInter(string);
    }
    if(*string == '\0') return numeric;
    return false;
}

int main(void) {
    char number[20] = "-.123";
    cout<<isNumeric(number)<<endl;
    return 0;
}