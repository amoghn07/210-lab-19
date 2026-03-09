#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Node{
    double rating;
    string comments;
    Node *next;
};

class Movie{
private:
    string title;
    Node *head;
public:
    Movie()                    {head = nullptr;}
    string getTitle()          {return title;}
    void setTitle(string t)    {title = t;}
    Node* getList()             {return head;}
};

void addNode(Node *&, Node *&);

int main(){
    vector<Movie> movies;
    fstream fin;
    fin.open("reviews.txt");
    //populating vector
    if (fin.good()){
        for (int i = 0; i < 4; i++){
            Movie temp;
            temp.setTitle("Movie #" + to_string(i));
            Node *temphead = temp.getList();
            for (int j = 0; j < 4; j++){
                string com;
                Node *tempNode = new Node;
                //generating random rating between 1.0 and 5.0
                tempNode -> rating = rand() % 5 + 1.0;
                tempNode -> next = nullptr;
                getline(fin, com);
                tempNode -> comments = com;
                addNode(temphead, tempNode);
            }
        }
    }
    else{
        cout << "error opening file.";
    }
    fin.close();
    return 0;
}

void addNode(Node *&hd, Node *&curr){
    if (!hd){
        hd = curr;
    }
    else{
        curr -> next = hd;
        hd = curr;
    }
}