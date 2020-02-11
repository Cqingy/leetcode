#include<iostream>
#include<algorithm>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;
};

int main(void){
    int n;
    
    cin>>n;
    ListNode* head;
    head->value = 0;
    head->next = nullptr;
    // cout<<head->next<<'\n';
    delete head;
    cout<<head;
    // for(int i = 0; i < n; i++){
    //     int temp;
    //     cin>>temp;
        
    // }
    return 0;
}
