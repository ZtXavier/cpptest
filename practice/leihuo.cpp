#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    int c, n;
    unordered_map<int, int> mp;
    queue<pair<int, int>> q;
    cin >> c >> n;
    int num = c;
    int a, b;
    int d;
//     cin >> a >> b;
    for(int i = 0; i < n; ++i) { 
        cin >> a >> b;
        if(a >= 0) {
            if(q.empty() && num == c && b > c) {
                c = num = b;
                mp[a] = num;
                num = 0;
                cout << 0 << endl;
                continue;
            }
            mp[a] = b;
            if(num >= b) {
                num = num - b;
                cout << b << endl;
            }else {
                mp[a] =  -1;
                q.push(make_pair(a, b));

                cout << 0 << endl;
            }
        } else {
            if(mp[b] != -1) {
                int tmp = mp[b];
                cout << tmp << endl;
                num += tmp;
            } 
            while(!q.empty()) {
                int f = q.front().first;
                if(num >= q.front().second) {
                    num -= q.front().second;
                    mp[f] = q.front().second;
                }
                q.pop();
            }
        }
    }
    return 0;
}
