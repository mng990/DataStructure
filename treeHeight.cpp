#include <bits/stdc++.h>

using namespace std;

class Node{

private:
    int data;
    vector<Node*> children;

public:

    Node(){
        data = NULL;
    }

    Node(int idx){
        data = idx;
    }

    void pushChild(Node* child){
        children.push_back(child);
    }

    int childrenSize(){
        return children.size();
    }

    Node* getChild(int cidx){
        return children.at(cidx);
    }

    bool isLeaf(){
        return children.empty();
    }

    int getData(){
        return data;
    }


    friend ostream& operator <<(ostream& os, Node& N){
        cout << N.getData();

        for(int i=0; i<N.childrenSize(); i++){
            cout << "/" << *N.getChild(i);
        }

        return os;
    }

};




int getHeight(Node* root){

    Node* next;
    int len;
    int rtn = 1;


    len = root->childrenSize();


    for(int i=0; i<len; i++){
        next = root->getChild(i);
        int h = getHeight(next)+1;

        if(rtn < h) rtn = h;
    }

    return rtn;

}




int main()
{
    int len, height, parent;
    Node* root, child;

    vector<Node*> tree;

    cin >> len;

    for(int i=0; i<len; i++){
        tree.push_back(new Node(i));
    }



    for(int j=0; j<len; j++){
        cin >> parent;

        if(parent != -1){
            tree.at(parent)->pushChild(tree.at(j));
        }
        else{
            root = tree.at(j);
        }
    }




    height = getHeight(root);


    cout << height << endl;




    return 0;
}
