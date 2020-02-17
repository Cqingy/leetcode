#include<iostream>
#include<algorithm>
using namespace std;

void replaceSpace(char *str,int length) {
    if(str == NULL || length <= 0)return;
    int old_length = 0;
    int new_length = 0;
    while(str[old_length] != '\0') {
        if(str[old_length] == ' '){
            new_length += 1;
        }
        old_length += 1;
    }
    new_length = old_length + 2 * new_length;
    if(new_length > length)return;
    while(old_length >= 0){
        if(str[old_length] == ' ') {
            str[new_length--] = '0';
            str[new_length--] = '2';
            str[new_length--] = '%';
        }else{
            str[new_length--] = str[old_length];
        }
        old_length -= 1;
    }
}

int main(void) {
    char str[20];

    cin>>str;
    cout<<str<<endl;
    return 0;
}