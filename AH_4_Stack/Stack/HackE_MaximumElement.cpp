//Note: you only use O(1)
//Remember that the order in if loop is important. (line 26)
//substr => 
// Test in the past, relate to solve the getline 


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<int> getMax(vector<string> operations) {
    vector<int> res;
    stack<int> st;
    stack<int> saveMax;
    
    for(int i = 0; i < operations.size(); i++){
        string s = operations[i];      
        string queryString  = s.substr(0);
        int queryInt = stoi(queryString);
        
        if(queryInt == 1){
            string valueString = s.substr(2);
            int value = stoi(valueString);
            st.push(value);
            
            if(saveMax.empty() || saveMax.top() <= value){
            saveMax.push(value);
            }
            
        }
        else if(queryInt == 2){ 
            if(saveMax.top() == st.top()){
                saveMax.pop();
            }
            st.pop();
           
        }
        else {
            res.push_back(saveMax.top());  
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
