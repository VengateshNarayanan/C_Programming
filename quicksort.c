#include <stdio.h>
 
#define size 100


void merge(int a[], int, int, int); void merge_sort(int a[], int, int);

int main()
{
int arr[size], i, n;


printf("Enter the number of elements in the array: "); scanf("%d", &n);

printf("\nEnter the elements of the array: ");


for(i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}


merge_sort(arr, 0, n - 1);


printf("\nSorted array is:\n");


for(i = 0; i < n; i++)
 
{
printf("%d\t", arr[i]);
}


return 0;
}


void merge(int arr[], int beg, int mid, int end)
{
int i = beg;
int j = mid + 1; int index = 0; int temp[size];

while(i <= mid && j <= end)
{
if(arr[i] <= arr[j])
{
temp[index] = arr[i]; i++;
}
else
{
temp[index] = arr[j]; j++;
 
}


index++;
}


if(i > mid)
{
while(j <= end)
{
temp[index] = arr[j]; j++;
index++;
}
}
else
{
while(i <= mid)
{
temp[index] = arr[i]; i++;
index++;
}
}


for(i = beg, index = 0; i <= end; i++, index++)
 
{
arr[i] = temp[index];
}
}


void merge_sort(int arr[], int beg, int end)
{
int mid;


if(beg < end)
{
mid = (beg + end) / 2;


merge_sort(arr, beg, mid); merge_sort(arr, mid + 1, end);

merge(arr, beg, mid, end);
}
}
