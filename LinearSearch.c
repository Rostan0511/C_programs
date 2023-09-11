#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int *A;
    int size;
    int length;
};
/*void Display(struct Array arr)
{
    printf("Elements of The Array are:\n");
        for(int i=0;i<arr.length;i++)
        {
            printf("Element At Index[%d] is %d.\n",i,arr.A[i]);
        }
}*/

int LinearSearch(struct Array arr)
{   
    int key;
           printf("Enter the Key Element To search inside Array:\n");
           scanf("%d",&key);
    
    for(int i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
        {
            printf("Element Found Sucuessfully at index: ");
            return i;
        }   
    }
    printf("Element Not Found\n");
    return -1;
} 
int main()
{
    int choice,size,i,sizeUsing;
    struct Array arr;
    arr.length=0;
    printf("Enter The Maximum Size of Array:\n");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size * sizeof(int));
    printf("Enter length of Array to be used:\n");
    scanf("%d",&sizeUsing);
        if(sizeUsing<arr.size)
        {
            arr.length=sizeUsing;
            printf("Enter elements of Array:\n");
            for (int i = 0; i < sizeUsing; i++)
            {   
                printf("Enter element for index[%d]:\n",i);
                scanf("%d",&arr.A[i]);
            }
           
           printf("%d\n",LinearSearch(arr));
            
            

        } 
        else
        {
            printf("Input Size Exceeds Array Size(Error) TRY AGAIN!!\n");
        }
        return 0;
        
}
