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
    if (k == n) solution();
    else {
        for(int i = 0; i <= 1 ; i++){
            res = res.append(to_string(i));
            search(k+1);
            res.pop_back();
        }
    }
}

int main() {
    input();
    search(0);
}
