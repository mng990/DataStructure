#include <bits/stdc++.h>
#include <sstream>

using namespace std;

string run(map<int, string>& phoneBook){
    string cmd;
    int number;

    cin >> cmd >> number;

    if(cmd == "add"){
        string name;

        cin >> name;
        phoneBook[number] = name;

        return "";
    }
    if(cmd == "find"){

        map<int, string>::iterator it;
        string NF = "not found";

        it = phoneBook.find(number);

        if(it != phoneBook.end()){
            return phoneBook[number] + "\n";
        }
        else{
            return NF+"\n";
        }


    }
    if(cmd == "del"){
        map<int, string>::iterator it;

        it = phoneBook.find(number);

        if(it!=phoneBook.end()){
            phoneBook.erase(it);
        }

        return "";
    }

}


int main()
{
    map<int, string> phoneBook;

    int len;

    cin >> len;

    for(int i=0; i<len; i++){
        cout<< run(phoneBook);
    }

    return 0;
}
