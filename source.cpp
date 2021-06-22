#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

vector<long long> numbers;
vector<int> operators; //+ = 0 / - = 1 / * = 2

//+
void operation1() {
    int counter = 0;
    vector<int> temp;
    for (int i = 0; i < operators.size(); ++i) {
        if (operators[i] == 0) {
            numbers[counter] += numbers[i + 1];
        } else {
            temp.push_back(operators[i]);
            counter++;
            numbers[counter] = numbers[i + 1];
        }
    }
    operators.clear();
    operators = move(temp);
    int t = numbers.size();
    for (int i = 0; i < t - counter - 1; ++i) {
        numbers.pop_back();
    }
}
//-
void operation2(){
    int counter = 0;
    vector<int> temp;
    for (int i = 0; i < operators.size(); ++i) {
        if (operators[i] == 1) {
            numbers[counter] -= numbers[i + 1];
        } else {
            temp.push_back(operators[i]);
            counter++;
            numbers[counter] = numbers[i + 1];
        }
    }
    operators.clear();
    operators = move(temp);
    for (int i = 0; i < numbers.size() - counter - 1; ++i) {
        numbers.pop_back();
    }
}

////+>*>-
void operation3(){
    int counter = 0;
    vector<int> temp;
    for (int i = 0; i < operators.size(); ++i) {
        if (operators[i] == 2) {
            numbers[counter] *= numbers[i + 1];
        } else {
            temp.push_back(operators[i]);
            counter++;
            numbers[counter] = numbers[i + 1];
        }
    }
    operators.clear();
    operators = move(temp);
    for (int i = 0; i < numbers.size() - counter - 1; ++i) {
        numbers.pop_back();
    }
}

void split(string s) {
    string temp;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
            numbers.push_back(stoi(temp));
            temp.clear();
            if (s[i] == '+') operators.push_back(0);
            if (s[i] == '-') operators.push_back(1);
            if (s[i] == '*') operators.push_back(2);
        } else temp.push_back(s[i]);
    }
    numbers.push_back(stoi(temp));
}

long long result(){
    set<long long, greater<long long>> answer;
    vector<long long> temp = numbers;
    vector<int> temp_oper = operators;

    operation1();
    operation2();
    operation3();
    long long r1 = numbers[0]>0 ? numbers[0] : -numbers[0];
    answer.insert(r1);
    numbers.clear();
    numbers=temp;
    operators.clear();
    operators=temp_oper;
    cout<<r1<<endl;

    operation1();
    operation3();
    operation2();
    long long r2 = numbers[0]>0 ? numbers[0] : -numbers[0];
    answer.insert(r2);
    numbers.clear();
    numbers=temp;
    cout<<r2<<endl;
    operators.clear();
    operators=temp_oper;

    operation2();
    operation1();
    operation3();
    long long r3 = numbers[0]>0 ? numbers[0] : -numbers[0];
    answer.insert(r3);
    numbers.clear();
    numbers=temp;
    cout<<r3<<endl;
    operators.clear();
    operators=temp_oper;

    operation2();
    operation3();
    operation1();
    long long r4 = numbers[0]>0 ? numbers[0] : -numbers[0];
    answer.insert(r4);
    numbers.clear();
    numbers=temp;
    cout<<r4<<endl;
    operators.clear();
    operators=temp_oper;

    operation3();
    operation1();
    operation2();
    long long r5 = numbers[0]>0 ? numbers[0] : -numbers[0];
    answer.insert(r5);
    numbers.clear();
    numbers=temp;
    cout<<r5<<endl;
    operators.clear();
    operators=temp_oper;

    operation3();
    operation2();
    operation1();
    long long r6 = numbers[0]>0 ? numbers[0] : -numbers[0];
    answer.insert(r6);
    numbers.clear();
    numbers=temp;
    cout<<r6<<endl;
    operators.clear();
    operators=temp_oper;

    return *answer.begin();
}

long long solution(string expression) {
//  input = move(expression);
    long long answer = 0;
    split(expression);
//  operation3();
//  operation1();
//  operation2();
//  cout<<numbers[0]<<endl;
//  for (int i = 0; i < operators.size(); ++i) {
//    cout << operators[i] << endl;
//  }
    return result();
}