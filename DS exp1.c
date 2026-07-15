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
    int x;
    printf("Enter the x =");
    scanf("%d",&x):
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==x)
        {
            count++;
            if(index==-1){
                index=i;
            }
        }
    }
    if(index!=-1){
      printf("position of first occurance of x is %d \n",index+1);
    }else{
    printf("x is not found");
    }
    printf("Number of occurance of x in an array is %d",count);
    return 0;
}
