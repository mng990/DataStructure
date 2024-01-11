#include <bits/stdc++.h>

using namespace std;


// input c = ] || ) || }


bool isBalanced(char c, char topBracket){
    if(c == ')' && topBracket == '('){
        return true;
    }

    if(c == ']' && topBracket == '['){
        return true;
    }
    if(c == '}' && topBracket == '{'){
        return true;
    }

    return false;
}

void checkBracket(stack<pair<char, int>>* brackets, char c){

    pair<char, int> bracket(c, i+1);


    if(!brackets->empty()){
        char topBracket = brackets->top().first;
        bool balance = isBalanced(c, topBracket);

        if(balance == true)
            brackets.pop();
        else {
            brackets->push(bracket);
            break;
            }
        }

    else{
        brackets->push(bracket);
        break;
    }

    return;

}

void printAns(stack<pair<char, int>>* brackets){
    if(brackets->empty()){
        cout << "Success"<< endl;
    }

    else{
        cout << brackets->top().second << endl;
    }

    return;
}



int main()
{
    stack<char> stk;
    stack<pair<char, int>> brackets;
    string str;

    cin >> str;

    for(int i=0; i<str.length(); i++){

        char c = str.at(i);

        stk.push(c);

        if(c == ')' || c == ']' || c == '}'){
            checkBracket(&brackets, c);
        }

        if(c == '(' || c=='[' || c=='{'){
            pair<char, int> bracket(c, i+1);
            brackets.push(bracket);
        }
    }


    printAns(&brackets);

    return 0;
}
