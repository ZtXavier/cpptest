#include<bits/stdc++.h>
using namespace std;
// int main() {
//     int a,b;
//     cin >> a >> b;
//     a = abs(a);
//     if(b > 0) {
//         cout << a;
//     }else {
//         cout << -a;
//     }
//     return 0;
// }


// int main() {
//     int s1,s2;
//     cin >> s1 >> s2;
//     int bsz = s1 > s2 ? s1 : s2;
//     vector<int> nums1(bsz);
//     vector<int> nums2(bsz);
//     if(s1 > s2){
//         for(int i = 0; i < bsz; ++i) {
//             int num;
//             cin >> num;
//             nums1[i] = num;
//         }
//         for(int i = bsz-s2; i < bsz; ++i) {
//             int num;
//             cin >> num;
//             nums2[i] = num;
//         }

//     } else {
//          for(int i = bsz-s1; i < bsz; ++i) {
//             int num;
//             cin >> num;
//             nums1[i] = num;
//         }
//          for(int i = 0; i < bsz; ++i) {
//             int num;
//             cin >> num;
//             nums2[i] = num;
//         }
//     }



//     reverse(nums1.begin(), nums1.end());
//     reverse(nums2.begin(), nums2.end());
//     vector<int> ret;
//     int pre = 0;
//     int j = 0;
//     for(j = 0; j < bsz; ++j) {
//         int added = nums1[j] + nums2[j] + pre;
//         ret.push_back((added)%(j + 2));
//         pre = added / (j+2);
//     }
//     if(pre != 0){
//         ret.push_back(pre);
//     }

//     for(int i = ret.size() - 1; i >= 0; --i) {
//         cout << ret[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }
