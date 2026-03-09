#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const double lower_bd = 1.0;
const double upper_bound = 5.0;
const long max_rand = 1000000L;

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
    Node* getList()            {return head;}
    void setList(Node *h)      {head = h;}
};

void output(Node *);
void addNode(Node *&, Node *&);

int main(){
    vector<Movie> movies;
    fstream fin;
    fin.open("reviews.txt");
    //populating vector
    if (fin.good()){
        for (int i = 0; i < 4; i++){
            Movie temp;
            temp.setTitle("Movie #" + to_string(i+1));
            Node *temphead = temp.getList();
            for (int j = 0; j < 4; j++){
                string com;
                Node *tempNode = new Node;
                //generating random rating between 1.0 and 5.0, source: geeks4geeks
                tempNode -> rating = lower_bd + (upper_bound - lower_bd) * (rand() % max_rand) / max_rand;
                tempNode -> next = nullptr;
                getline(fin, com);
                tempNode -> comments = com;
                addNode(temphead, tempNode);
            }
            temp.setList(temphead);
            movies.push_back(temp);
        }
    }
    else{
        cout << "error opening file.";
    }
    fin.close();

    //outputting the vector
    for (auto &val: movies){
        cout << val.getTitle() << ": \n";
        output(val.getList());
    }
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

void output(Node *head){
    Node *temp = head;
    int count;
    float revTotal;
    cout << "Outputting Reviews:\n";
    while (temp){
        count++;
        cout << "\t> Review #" << count << ": " << temp -> rating;
        cout << ": " << temp -> comments << endl;
        revTotal += temp -> rating;
        temp = temp -> next;
    }
    cout << "\t> Average: " << revTotal / count;
}