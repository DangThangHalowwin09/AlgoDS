#include<iostream>
#include<string>

using namespace std;
int n;
string res;

void input() {
    cin >> n;
}

void solution() {
    cout << res << endl;
}

void search(int k) {
    if (res.length() == n) solution();
    else {
        res = res.append("1");
        search(k + 1);
        res.pop_back();
        res = res.append("0");
        search(k + 1);
        res.pop_back();
    }
}

int main() {
    input();
    search(0);
}
