#include<stdio.h>
int main()
{
    int size=10;
    int arr[10];
    printf("Enter the elements in the array \n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",& arr[i]);
    }
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==2)
        {
            count++;

        }
    }
    printf("Number occurancy of 2 in an array is %d",count);
    return 0;
}
