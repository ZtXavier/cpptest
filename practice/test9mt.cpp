#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main()  {
    int n;
    cin >> n;
    vector<double> vt;
    for(int i = 0 ;i < n; ++i) {
        double tmp;
        cin >> tmp;
        vt.push_back(tmp);
    }
    
    int nop;
    cin >> nop;
    for(int j = 0;j < nop; ++j) {
        char op;
        int opn;
        cin >> opn >> op;
        // cin >> op;
        vector<double> vt_num = vt;
        vector<char> vt_op(n - 1,'+');
        
        vt_op[opn - 1] = op; 
        stack<double> stn;
        stack<char> stc;


        double ret = vt_num[0];
        stn.push(ret);
        for(int k = 1;k < n; k++) {
            if(vt_op[k - 1] == '*' || vt_op[k - 1]  == '/') {
                double tmp = stn.top();
                if(vt_op[k - 1] == '*' && !stn.empty()) {
                    stn.pop();
                    tmp *= vt_num[k];
                    stn.push(tmp);
                } else {
                    stn.pop();
                    tmp /= vt_num[k];
                    stn.push(tmp);
                }
            } else {
                if(vt_op[k - 1] == '-'){
                    stn.push((-vt_num[k])); 
                    stc.push('+');
                }else{
                    stn.push(vt_num[k]);
                    stc.push(vt_op[k - 1]);
                }
            }
        }
        while(!stc.empty()) {
            double a,b;
            a = stn.top();
            stn.pop();

            b = stn.top();
            stn.pop();

            char ch = stc.top();
            stc.pop();
            if(ch == '+') {
                a += b;
            }else {
                a -= b;
            }
            stn.push(a);
        }
        if(j == n - 1){
            printf("%.1lf",stn.top());

        }else {
            printf("%.1lf ",stn.top());
        }
    }
    return 0;
}

// int main() {
//     int n;
//     cin >> n;
//     vector<int> vt;
//     for(int i = 0;i < n; ++i) {
//         int tmp;
//         cin >> tmp;
//         vt.push_back(tmp);
//     }

//     sort(vt.begin(),vt.end());
//     int ret = 0;
//     for(int i = 1;i < n;i++) {
//         ret += abs(vt[i] - vt[i - 1]);
//     }
//     cout << ret;
//     return 0;
// }
