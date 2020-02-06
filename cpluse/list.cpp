#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;
};

void print_all_nodes(ListNode* node){
    if(node == nullptr){
        cout<<"it is null"<<'\n';
    }
    while(node != nullptr){
        cout<<node->value<<'\n';
        node = node->next;
    }
}

void add_node(ListNode* list, ListNode* node){
    if(list == nullptr){
        cout<<"this is null list\n";
    }else if(node == nullptr){
        cout<<"this is null node\n";
    }
    while(list->next != nullptr){
        list = list->next;
    }
    list->next = node;
    cout<<"insert success\n";
}

ListNode* remove_node(ListNode* list, int val){
    if(list == nullptr){
        cout<<"this is null list\n";
    }
    ListNode* start = list;
    if(list->value == val){
        list = list->next;
        return list;
    }
    while(list->next != nullptr){
        if(list->next->value == val){
            list->next = list->next->next;
            cout<<"delete one node\n";
        }
        
        list = list->next;
    }
    return start;
}

int main(void){
    ListNode* node = new ListNode();
    node->value = 5;
    node->next = nullptr;
    ListNode* node2 = new ListNode();
    node2->value = 6;
    node->next = nullptr;
    add_node(node, node2);
    node = remove_node(node, 1);
    print_all_nodes(node);
    return 0;
}