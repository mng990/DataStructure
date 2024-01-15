#include <bits/stdc++.h>

using namespace std;

class intSet{
private:
    long long M;
    long long x;
    set<long long> _intset;
    set<long long>::iterator it;
public:
    intSet(){
        M = pow(10, 9) + 1;
        x = 0;
    }

    void _find(long long num){
        it = _intset.find(num);
        if(it == _intset.end())
            cout << "Not found"<<endl;
        else
            cout << "Found" << endl;
    }

    void _add(long long num){
        _intset.insert(num);
    }

    void _del(long long num){
        it = _intset.find(num);

        if(it != _intset.end())
            _intset.erase(it);
    }

    long long _sum(long long l, long long r){
        long long rtn = 0;

        for(it = _intset.begin(); it != _intset.end(); it++){
            if(*it >= l && *it <= r)
                rtn += *it;
        }

        return rtn;
    }

    long long convert(long long num){
        return (num+x)%M;
    }


    void cmd(string c){
        long long l, r;

        if(c == "+"){
            cin >> l;
            _add(convert(l));
        }

        if(c == "-"){
            cin >> l;
            _del(convert(l));
        }

        if(c == "?"){
            cin >> l;
            _find(convert(l));
        }

        if(c == "s"){
            cin >> l >> r;
            x = _sum(convert(l), convert(r));
            cout << x << endl;
        }
    }


    void run(){
        int loop;
        string c;

        cin >> loop;

        for(int i=0; i<loop; i++){
            cin >> c;
            cmd(c);
        }
    }

};

int main()
{

    intSet* iset = new intSet();

    iset -> run();


    return 0;
}
