#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// //查看一个函数的地址，用到函数指针 数据类型 (*自定义符号)(形参)

// static unsigned int PFN_ARR[100] = {0};
// void func1(void);
// void func2(int a);

// void func1(void)
// {
//     void (*pfn)(void) = func1;  //函数名就是函数所占的首地址
//     unsigned int func_addr = (unsigned int)pfn;
//     PFN_ARR[0] = func_addr;
//     printf("func1:%X\n",func_addr);
// }

// void func2(int a)
// {
//     void(*pfn)(int) = func2;
//     unsigned int func_addr = (unsigned int)pfn;
//     PFN_ARR[1] = func_addr;
//     printf("func2:%X\n",func_addr);
// }

// int main(void)
// {
//     void(*pfn)();
//     func1();
//     func2(5);
//     // pfn = (void(*)())(PFN_ARR[0]);
//     // pfn();
//     getchar();
//     return 0;
// }

// int main(void)
// {
//     int n,m;
//     scanf("%d",&n);
//     while(n > 0)
//     {
//         scanf("%d",&m);
//         int a[m][m];
//         int i,j,k;
//         int num = 1;
//         a[0][0] = 1;
//         for(int k = 1;k < m;k++)
//         {
//             for(i = k,j = 0;j <= k && i >= 0;j++,i--)
//             {
//                 a[i][j] = (++num);
//             }
//         }
//         for(i = m; i > 0;i--)
//         {
//             for(j = 0;j < i;j++)
//             {
//                 printf("%d ",a[m-i][j]);
//             }
//             printf("\n");
//         }
//         n--;
//     }
//     return 0;
// }





int main()
{
    // int m,p,n;
    // scanf("%d",&m);
    // scanf("%d",&p);
    // scanf("%d",&n);
    // int a[m][p];
    // int b[p][n];
    // for(int i = 0;i < m;i++)
    // {
    //     for(int j = 0;j < p;j++)
    //     {
    //         scanf("%d",&a[i][j]);
    //     }
    // }
    // for(int i = 0;i < p;i++)
    // {
    //     for(int j = 0;j < n;j++)
    //     {
    //         scanf("%d",&b[i][j]);
    //     }
    // }
    // int k = 0,h = 0;
    // int res[m][n];
    // memset(res,0,sizeof(res));
    // for(int i = 0;i < m;i++)
    // {
    //     for(int j = 0;j < n;j++)
    //     {
    //         for(int l = 0;l < p;l++)
    //         {
    //             res[h][k] += (a[i][l]*b[l][j]);
    //         }
    //         k++;
    //     }
    //     k = 0;
    //     h++;
    // }
    // for(int i = 0;i < m;i++)
    // {
    //     for(int j = 0;j < n;j++)
    //     {
    //         if(j == n-1)
    //         printf("%d\n",res[i][j]);
    //         else
    //         printf("%d ",res[i][j]);
    //     }
    // }
    // return 0;



    // char a[10];
    // int num;
    // scanf("%s",a);
    // scanf("%d",&num);
    // int len = strlen(a);
    // for(int i = 0;i < strlen(a);i++)
    // {
    //     a[i] = a[i] + num%32;
    // }
    // for(int i = 0;i < len;i++)
    // printf("%c",a[i]);
    // return 0;
}