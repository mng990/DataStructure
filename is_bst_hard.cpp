#include <bits/stdc++.h>

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
    binaryTree(){
        int key, left, right, len;

        cin >> len;

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

    bool isItBST(int vidx, bool rtn, int prevKey, bool dir){

        if(rtn == false) return rtn;
        if(vvtx.empty()) return true;

        vertex* now  = vvtx.at(vidx);

        int key  = now->getKey();
        int left = now->getLeft();
        int right= now->getRight();

        if(left != -1 && rtn == true){
            int leftKey = vvtx.at(left)->getKey();

            rtn = (leftKey < key);

            if(vidx != 0 && rtn == true){
                if(dir == true) rtn = (leftKey < prevKey );
                else            rtn = (leftKey >= prevKey);
            }
        }

        if(right != -1 && rtn == true){
            int rightKey = vvtx.at(right)->getKey();

            rtn = (rightKey >= key);

            if(vidx != 0 && rtn == true){
                if(dir == true) rtn  = (rightKey < prevKey);
                else            rtn = (rightKey >= prevKey );
            }
        }



        if(left  != -1 && rtn == true)
            rtn = isItBST(left , rtn, key, true);

        if(right != -1 && rtn == true)
            rtn = isItBST(right, rtn, key, false);

        return rtn;
    }

    void problem01(){

        inOrder(0);

        cout << endl;

        preOrder(0);

        cout << endl;

        postOrder(0);

    }

    void problem02(){
        bool rtn = isItBST(0, true, -1, true);

        if(rtn == true)
            cout << "CORRECT"  << endl;
        else
            cout << "INCORRECT" << endl;
    }
};


int main()
{

    binaryTree* bst = new binaryTree();

    bst -> problem02();


    return 0;
}
