#include <bits/stdc++.h>
#include <sstream>

using namespace std;

class vertex{
private:
    int key;
    int left;
    int right;

public:
    vertex(int _key, int _left, int _right){
        key = _key;
        left = _left;
        right = _right;
    }

    int getKey(){
        return key;
    }

    int getLeft(){
        return left;
    }

    int getRight(){
        return right;
    }
};


class binaryTree{
private:
    vector<vertex*> vvtx;
public:
    binaryTree(int len){
        int key, left, right;

        for(int i=0; i<len; i++){
            cin >> key >> left >> right;
            vertex* vp = new vertex(key, left, right);
            vvtx.push_back(vp);
        }
    }

    ~binaryTree(){
        for(vertex* vp: vvtx){
            delete vp;
        }

        delete this;
    }

    void inOrder(int vidx){

        vertex* now = vvtx.at(vidx);

        int key  = now->getKey();
        int left = now->getLeft();
        int right= now->getRight();

        if(left != -1){
            inOrder(left);
        }

        cout << key << " ";


        if(right != -1){
            inOrder(right);
        }
    }

    void preOrder(int vidx){

        vertex* now = vvtx.at(vidx);

        int key  = now->getKey();
        int left = now->getLeft();
        int right= now->getRight();

        cout << key << " ";

        if(left != -1){
            preOrder(left);
        }

        if(right != -1){
            preOrder(right);
        }

    }

    void postOrder(int vidx){

        vertex* now = vvtx.at(vidx);

        int key  = now->getKey();
        int left = now->getLeft();
        int right= now->getRight();

        if(left != -1){
            postOrder(left);
        }

        if(right != -1){
            postOrder(right);
        }

        cout << key << " ";
    }

    void run(){

        inOrder(0);

        cout << endl;

        preOrder(0);

        cout << endl;

        postOrder(0);

    }
};


int main()
{
    int n;

    cin >> n;

    binaryTree* btp = new binaryTree(n);

    btp -> run();


    return 0;
}
