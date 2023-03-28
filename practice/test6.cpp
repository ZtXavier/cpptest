#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<cmath>

// int main(int argc,char* argv[]) {
//     int n;
//     std::cin >> n;
//     int arr[n];
//     for(int i = 0;i < n;++i){
//         std::cin >> arr[i];
//     }
//     std::string st;
//     std::cin >> st;
//     std::vector<int> b,r;
//     int ret = 0;
//     for(int i = 0;i < n;i++) {
//         if(st[i] == 'R') {
//             r.push_back(arr[i]);
//         }else {
//             b.push_back(arr[i]);
//         }
//     }
//     for(int &rr : r) {
//         for(int &bb : b) {
//             ret = (ret + (long long)rr * bb)%1000000007;
//         }
//     }

//     std::cout << ret << std::endl;
//     return 0;
// }




// int main() {
//    std::string st;
//    std::string ret = "0.";
//    std::cin >> st;
//    int Index = 2;
//    int Max = -1;
//    int i = 0;
//    while (Index < st.size()){
//         for( i = Index; i < st.size(); i++) {
//             if((st[i] - '0') > Max ) {
//                 Max = st[i] - '0';
//                 std::cout << Max << std::endl;
//                 Index = i;
//             }
//         }
//         ret += st[Index++];
//         Max = -1;
//    }
//    std::cout << ret << std::endl;
//     return 0;
// }


int main() {
    int n;
    std::cin >> n;
    int a[n][n];
    std::vector<int> v;
    for(int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    
    return 0;
}