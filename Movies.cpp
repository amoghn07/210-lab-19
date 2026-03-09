#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node{
    double rating;
    string comments;
    Node *next;
};

class Movie{
private:
    string title;
    Node *list;

public:

};

void addNode(Node *&, Node *&);

int main(){
    return 0;
}

void addNode(Node *&hd, Node *&curr){
    if (!hd){
        hd = curr;
    }
    else{
        Node *temp = hd;
        curr -> next = hd -> next;
    }
}