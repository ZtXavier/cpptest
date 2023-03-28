#include <iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

// int main() {
//     int n;
//     vector<int> vt;

//     cin >> n;
//     for(int i = 0;i < n;i++) {
//         int tmp;
//         cin >> tmp;
//         vt.push_back(tmp);
//     }

//     sort(vt.begin(),vt.end());
//     int p = 0;
//     int Max = -1;
//     for(auto &a : vt) {
//         if(p >= 3) {
//             break;
//         }
//         if(Max < a) {
//             Max = a;
//             p++;
//         } 
//     }
//     if(p != 3){
//         printf("-1");
//     }else {
//         printf("%d",Max);
//     }
//     return 0;
// }
// 64 位输出请用 printf("%lld")

// int main(void)
// {
//     int n;
//     while(std::cin >> n)
//     {
//         int *a = new int[n];
//         int sum = 0;
//         for(int i=0; i<n; ++i)
//         {
//             std::cin >>a[i];
//             if(i > 0)
//                sum += abs(a[i]-a[i-1]);//求出所有应走的距离
//         }

//         int iMaxDist = 0;
//         for(int j=1; j<n-1; ++j)
//         {
//             //对所有的点(非起点终点) 求出忽略之后与不忽略之间的差距
//             //选择最大差距的那个点，即是要忽略的点
//             int iDist = abs(a[j-1]-a[j]) + abs(a[j]-a[j+1])\
//                 - abs(a[j-1]-a[j+1]); 
//             if(iDist > iMaxDist)
//                 iMaxDist = iDist;
//         }
//         //总的距离减去忽略省下来的距离即要走的距离
//         std::cout << sum-iMaxDist << std::endl;
//         delete []a;

//     }
//     return 0;
// }

// int main() {
//     int n;
//     cin >> n;
//     int *arr = new int[n];
//     int *arr1 = new int[n];
//     for(int i = 0; i < n; ++i) {
//         cin >> arr[i];
//         arr1[i] = arr[i];
//     }

//     sort(&arr[0],&arr[n-1]);
//     int sm = 0;
//     for(int i = 0;i < n; i++){
//         if(arr1[i] != arr[i]) {
//             sm++;
//         }
//     }
//     if(sm == 0) {
//         printf("0");
//     }else{
//         printf("%d",sm-1);
//     }
//     return 0;
// }


#include <iostream>
#include<algorithm>
#include<map>
#include<vector>

int main()
  {
     int n,temp;
     cin>>n;
     vector<int> v;
     map<int,int> m;
     for(int i=0;i<n;i++) 
       {  cin>>temp;
          v.push_back(temp);
          m[temp]=i;
       }
     sort(v.begin(),v.end());
     int t=n,count=0;
     for(int i=0;i<n-1;i++)
       {
           if (m[v[i]]>m[v[i+1]])
              {
                 m[v[i+1]]=t++;
                 count++;
              }
       }
     cout<<count<<endl;
}