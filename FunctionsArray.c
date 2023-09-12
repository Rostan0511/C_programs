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

int ElementSet(struct Array *arr,int index,int x)
{
    if(index >= 0 && index < arr->length)
    {
        arr->A[index]=x;
    }
    return x;
}

int ElementGet(struct Array arr,int index)
{
    if(index>=0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

int FindMin(struct Array arr)
{
        int Min=arr.A[0];
        for(int i=1;i<arr.length;i++)
        {
            if(arr.A[i]<Min)
            {
                Min=arr.A[i];
            }
        }
        return Min;
    

}
int FindMax(struct Array arr)
{
    int Max=arr.A[0];
        for(int i=1;i<arr.length;i++)
        {
            if(arr.A[i]>Max)
            {
                Max=arr.A[i];
            }
        }
        return Max;
    
}
int CalculateSum(struct Array arr)
{
    int s=0,i;
    for(i=0;i<arr.length;i++)
    {
        s=s+arr.A[i];
    }
    return s;
}
float CalculateAvg(struct Array arr)
{
     if (arr.length == 0) 
    {
        return 0.0; // Avoid division by zero
    }
    return (float)CalculateSum(arr) / arr.length;
}

int main()
{
    struct Array arr = {.A = (int[]){32, 13, 41, 51, 62}, .length = 5};
    printf("Element searched using Get Function is = %d\n",ElementGet(arr,2));
    Display(arr);
    ElementSet(&arr,2,11);
    Display(arr);
    printf("Minimum = %d\n",FindMin(arr));
    printf("Maximum  = %d\n",FindMax(arr));
    printf("Sum = %d\n",CalculateSum(arr));
    printf("Average = %f\n",CalculateAvg(arr));
    return 0;

}

