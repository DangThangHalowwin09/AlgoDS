#include <iostream>
#include <vector>
using namespace std;

vector<int> permutationRes;
vector<int> inputSet;
const int MAX = 1000;
bool visited[MAX];
int n, k;
int sum = 0;


void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        inputSet.push_back(k);
    }

}
void solution() {
    for (int i = 0; i < n; i++)
        cout << permutationRes.at(i) << " ";
    cout << endl;
}

void search(int k) {
    if (permutationRes.size() == n) {
        solution();
    }
    else {
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            permutationRes.push_back(inputSet[i]);
            search(k + 1);
            visited[i] = false;
            permutationRes.pop_back();
        }
    }
}

int main() {
    input();
    search(0);
    cout << sum;
}
