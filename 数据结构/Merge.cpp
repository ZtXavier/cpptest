#include<iostream>
#include<vector>
 
void Merge(int *arr,int l,int r,int m)  
{
    // i 为移动的总步数
    int aux[r - l + 1];
    for(int i = l;i <=r;i++)
    {
        aux[i-l] = arr[i];
    }

    int k = l;
    int h = m + 1;
    for(int i = l;i <= r;i++)
    {
        if(k > m)
        {
            arr[i] = aux[h - l];
            h++;
        }
        else if(h > r)
        {
            arr[i] = aux[k - l];
            k++;
        }
        // 若在该处交换，拷贝数据的指针不动，被拷贝数据的指针++
        else if(aux[k - l] > aux[h - l])
        {
            arr[i] = aux[h - l];
            h++;
        }
        else
        {
            arr[i] = aux[k - l];
            k++;
        }
    }
}

void Merge_sort(int *arr,int l,int r)
{
    if(l >= r)
    return;
    int mid = (r + l)/2;
    Merge_sort(arr,l,mid);
    Merge_sort(arr,mid+1,r);
    Merge(arr,l,r,mid);
}

void Merge_sort_init(int *a,int l,int r)
{
    Merge_sort(a,l,r-1);
}

int main()
{
    
    int a[7] = {1,7,5,5,5,9,3};

    Merge_sort_init(a,0,7);
    for(int i = 0;i < 7;i++)
    {
        std::cout << a[i] << std::endl;
    }
    return 0;
}