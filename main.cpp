#include <bits/stdc++.h>

using namespace std;

class DisjointSet{
private:
    vector<int> parents;
    vector<int> vranks;

public:
    DisjointSet(int n): parents(n+1), vranks(n+1, 0){
        for(int i=1; i<n+1; i++){
            parents.at(i) = i;
        }
    }

    int find(int i){
        if(parents[i] == i) return i;
        else{
            return this->find(parents[i]);
        }
    }

    void setUnion(int a, int b){
        int root_a = this->find(a);
        int root_b = this->find(b);


        if(root_a == root_b){
            return ;
        }

        else{
            if(vranks[root_a] < vranks[root_b]){
                parents[root_a] = root_b;
            }

            else if(vranks[root_a] == vranks[root_b]){
                int root_min = min(root_a, root_b);
                int root_max = max(root_a, root_b);
                parents[root_max] = parents[root_min];
                vranks [root_min]++;

            }

            else{
                parents[root_b] = root_a;
            }

        }
    }


    int forest(){
        int rtn = 0;
        for(int i=1; i < parents.size(); i++){
            cout << i << "/" <<parents.at(i) << "/" << vranks.at(i) << endl;

            if(i == this->find(i)){
                //cout << vranks[i] << endl;
                rtn += vranks[i];
            }
        }

        return rtn;
    }

    int maxHeight(){
        return *max_element(vranks.begin(), vranks.end());
    }

    void printDjs(){
        int len = parents.size();

        for(int i=1; i<len; i++){
            cout << i << "/" << parents.at(i) << "/" << vranks.at(i)<<endl;
        }
    }
};

int main()
{
    int len = 12;

    DisjointSet* djs = new DisjointSet(len);

// 巩力 1

    djs->setUnion(2, 10);
    djs->setUnion(7, 5);
    djs->setUnion(6, 1);
    djs->setUnion(3, 4);
    djs->setUnion(5, 11);
    djs->setUnion(7, 8);
    djs->setUnion(7, 3);
    djs->setUnion(12, 2);
    djs->setUnion(9, 6);
    cout << djs->find(6) <<endl;
    cout << djs->find(3) <<endl;
    cout << djs->find(11)<<endl;
    cout << djs->find(9) << endl;

    djs->printDjs();



// 巩力 2
/*
    djs->setUnion(2, 10);
    djs->setUnion(7, 5);
    djs->setUnion(6, 1);
    djs->setUnion(3, 4);
    djs->setUnion(5, 11);
    djs->setUnion(7, 8);
    djs->setUnion(7, 3);
    djs->setUnion(12, 2);
    djs->setUnion(9, 6);

    cout << djs->forest() << endl;
*/

// 巩力 3
/*

    for(int i=1; i<12; i++){
        djs->setUnion(i, i+1);
    }

    cout << djs->forest() << "/" << djs->maxHeight() << endl;
*/

//巩力 4
/*
    for(int i=1; i < (len+1)/2; i++){
        djs->setUnion(i, 2*i);
    }

    for(int i=1; i<(len+1)/3; i++){
        djs->setUnion(i, 3*i);
    }
    for(int i=1; i<(len+1)/5; i++){
        djs->setUnion(i, 5*i);
    }

    for(int i=1; i<len+1; i++){
        djs->find(i);
    }

    cout << djs->maxHeight() << endl;
*/


    return 0;
}
