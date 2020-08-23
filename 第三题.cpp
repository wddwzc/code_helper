#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

vector<int> parents;

bool flag = true;

int find(int index) {
    // while (parents[index] != index) {
    //     parents[index] = parents[parents[index]];
    // }
    if (parents[index] != index) {
        parents[index] = find(parents[index]);
    }
    
    return parents[index];
}

void Union(int x, int y) {
    parents[find(x)] = find(parents[y]);
    return;
}

void dfs(unordered_map<int, set<int>> &mapping, int index_judge, int index2);

int main()
{
    unordered_map<string, int> indexes;
    unordered_map<long long, string> ops;
    int index = 0;
    int N, M;
    cin >> N;
    for (int p = 0; p < N; ++p) {
        cin >> M;
        string str;
        vector<string> equa_p1, equa_p2, equa_ops;
        vector<string> nequa_p1, nequa_p2, nequa_ops;
        vector<string> big_p1, big_p2, big_ops;
        
        for (int q = 0; q < M; ++q) {
            cin >> str;
            // cout << str << endl;
            int pos;
            string param1, param2, op;
            for (pos = 0; pos < str.size(); ++pos) {
                if (!isalnum(str[pos])) {
                    param1 = str.substr(0, pos);
                    if (str[pos] == '!') {
                        op = str.substr(pos, 2);
                        param2 = str.substr(pos + 2, str.size() - pos - 2);
                    }
                    else {
                        op = str.substr(pos, 1);
                        param2 = str.substr(pos + 1, str.size() - pos - 1);
                    }

                    // cout << param1 << " " << op << " " << param2 << endl;

                    int ind1, ind2;
                    if (!indexes.count(param1)) {
                        ind1 = index;
                        indexes[param1] = index++;
                    }  
                    if (!indexes.count(param2)) {
                        ind2 = index;
                        indexes[param2] = index++;
                    }
                    // ops[ind1 * 1000000 + ind2] = op;

                    if (op == "!=") {
                        nequa_p1.push_back(param1);
                        nequa_p2.push_back(param2);
                    }
                    else if (op == "=") {
                        equa_p1.push_back(param1);
                        equa_p2.push_back(param2);
                    }
                    else if (op == ">") {
                        big_p1.push_back(param1);
                        big_p2.push_back(param2);
                    }
                    else if (op == "<") {
                        big_p1.push_back(param2);
                        big_p2.push_back(param1);
                    }

                    break;
                }
            }
        }

        parents.resize(index);
        for (int i = 0; i < index; ++i) {
            parents[i] = i;
        }

        for (int i = 0; i < equa_p1.size(); ++i) {
            int ind1 = indexes[equa_p1[i]];
            int ind2 = indexes[equa_p2[i]];
            Union(ind1, ind2);
        }

        for (int i = 0; i < nequa_p1.size(); ++i) {
            int ind1 = find(indexes[nequa_p1[i]]);
            int ind2 = find(indexes[nequa_p2[i]]);
            // if (find(ind1) == find(ind2)) {
            if (ind1 == ind2) {
                flag = false;
                break;
            }
        }

        unordered_map<int, set<int>> mapping;
        
        for (int i = 0; i < big_p1.size(); ++i) {
            if (flag) {
                int ind1 = find(indexes[big_p1[i]]);
                int ind2 = find(indexes[big_p2[i]]);
                if (ind1 == ind2) {
                    flag = false;
                    break;
                }
                if (!mapping.count(ind1)) {
                    mapping[ind1].insert(ind2);
                }
                else {
                    if (!mapping[ind1].count(ind2)) {
                        mapping[ind1].insert(ind2);
                    }
                    dfs(mapping, ind1, ind1);
                }
            }
            else {
                break;
            }
        }

        if (flag)  cout << "True" << endl;
        else        cout << "False" << endl;

    }
    
    system("pause");
    return 0;
}


void dfs(unordered_map<int, set<int>> &mapping, int index_judge, int index2) {
    if (!flag) return;
    if (!mapping.count(index2)) return;
    for (auto ele : mapping[index2]) {
        int next = find(ele);
        cout << next << endl;
        if (index_judge == next) {
            flag = false;
        }
        else {
            dfs(mapping, index_judge, next);
        }
    }
    return;
}