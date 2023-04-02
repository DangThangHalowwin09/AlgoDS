#include <iostream>
#include <vector>
using namespace std;
vector<int> subsetRes;
vector<int> set;
int k, n;
int sum = 0;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        set.push_back(k);
    }
}
void search(int k){
    if(k == n) {
        for(int i = 0; i < subsetRes.size(); i++)
        cout << subsetRes.at(i) << " ";
        cout << endl;
        sum++;
    }
    
    else {
    subsetRes.push_back(set[k]);
    search(k+1);
    subsetRes.pop_back();
    search(k+1);
    }
}
int main(){
    input();
    search(0);
    cout << sum;
}