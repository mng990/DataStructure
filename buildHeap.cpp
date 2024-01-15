#include <bits/stdc++.h>

using namespace std;


class heap{
private:
    vector<int> arr;
    vector<pair<int, int>> record;
public:
    heap(int len, ifstream& fin){

        for(int i=0; i<len; i++){
            int num;
            fin >> num;
            arr.push_back(num);
        }
    }

    void swapNode(int i, int j){
        int temp = arr.at(i);
        arr.at(i) = arr.at(j);
        arr.at(j) = temp;
    }


    void upHeap(int idx){

        if(idx == 0) return ;

        int pidx = (idx-1)/2;
        int parent = arr.at(pidx);
        int child  = arr.at(idx);

        if(parent > child){
            swapNode(pidx, idx);

            pair<int, int> r(pidx, idx);

            record.push_back(r);
        }

        return upHeap(pidx);
    }

    void forUpHeap(int len){
        for(int i=len-1; i>=0; i--){
            upHeap(i);
        }

        return ;
    }


    void printRecord(ofstream& fout){
        fout << record.size() << endl;
        for(int i=0; i<record.size(); i++){
            pair<int, int> r = record.at(i);
            fout << r.first << " " << r.second <<endl;
        }
    }

};

void test(){
    int len, cnt =0;
    int start;

    ifstream fin("./test/04");
    ofstream fout;

    fout.open("./test/ans");


    fin >> len;

    heap* h = new heap(len, fin);


    h->forUpHeap(len);

    h->printRecord(fout);

    fin .close();
    fout.close();

    delete h;

    return;
}

int main()
{
/*
    int len, cnt =0;
    int start;

    fin >> len;

    heap* h = new heap(len);


    h->forUpHeap(len);

    h->printRecord();
*/

    test();

    return 0;
}
