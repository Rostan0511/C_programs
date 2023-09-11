#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("Elements of The Array are:\n");
        for(int i=0;i<arr.length;i++)
        {
            printf("Element At Index[%d] is %d.\n",i,arr.A[i]);
        }
}

void Add(struct Array *arr)
{   
    int n,i;
    if(arr->length<arr->size)
        {
            printf("Enter element to add:\n");
            scanf("%d",&n);
            arr->A[arr->length]=n;
            arr->length++;
            printf("Element added Sucessfully.\n");
        }
        else
        {
            printf("Array is already full till its maximum capacity\n");
        }

}

void Insert(struct Array *arr)
{
    int index,n,i;
    printf("Enter element to insert:\n");
    scanf("%d",&n);
    printf("At what index you would like to insert:\n");
    scanf("%d",&index);
    if(index>=0 && index<arr->length)
    {
        if(arr->length<arr->size)
        {
            for(i=arr->length;i>index;i--)
            {
                arr->A[i]=arr->A[i-1];
            }
            arr->A[index]=n;
            arr->length++;
        }
    }
}

void Delete(struct Array *arr)
{
    int index,i;
    printf("Enter the index of the Element you Want to Delete:\n");
    scanf("%d",&index);
    int DeletedElement=arr->A[index];
    if(index>=0 && index<arr->length)
    {
        for(i=index;i<arr->length-1;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        printf("Element %d is deleted Sucessfully.\n",DeletedElement);
    }
    else
    {
        printf("Invalid Index Deletion");
    }
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
            printf("Enter your choice\n");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1 : Display(arr);
                     break;
            case 2 : Display(arr);
                     Insert(&arr);
                     Display(arr);
                     break;
            case 3 : Display(arr);
                     Add(&arr);
                     Display(arr);
                     break;         
            case 4 : Display(arr);
                     Delete(&arr);
                     Display(arr);
                     break;         
            
            default: printf("Choice Error\n");
                break;
            }
            

        } 
        else
        {
            printf("Input Size Exceeds Array Size(Error) TRY AGAIN!!\n");
        }
        return 0;
        
}
