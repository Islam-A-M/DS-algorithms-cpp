#include<iostream>
#include<stdlib.h>
using namespace std;


struct Array {
    int *A;
    int size;
    int length;

};
void Display(struct Array arr) {

    int i;
    printf("\nElements are\n");
    for(i=0; i<arr.length; i++){
        printf("%d",arr.A[i]);
        }
  // if(i>arr.length-1) {
    //    printf(" , ");
   // }
}
void Append(struct Array *arr,int x) {
    if(arr->length<arr->size) {
        arr->A[arr->length++]=x;
    }
}

void Insert(struct Array *arr, int index, int x) {
    int i;
    if(index>=0 && index <= arr->length) {

        for(i=arr->length; i>index; i--)
            arr->A[i]=arr->A[i-1];

        arr->A[index]=x;
        arr->length++;

    }
}
int Delete(struct Array *arr, int index) {
    int x= 0;
    int i;
    if(index>=0 && index<arr->length) {
        x=arr->A[index];
        for(i=index; i<arr->length-1; i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;

    }
    return 0;
}
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}
int LinearSearch(struct Array *arr, int key) {
    int i;
    for(i=0; i<arr->length; i++) {
        if(key==arr->A[i]) {
            if(i!=0) {
                swap(&arr->A[i], &arr->A[0]);
                //swap(&arr->A[i], &arr->A[i-1]);
            }
            return i;

        }
    }
    return -1;
}
int BinarySearch(struct Array arr, int key) {
    int l,mid,h;
    l=0;
    h=arr.length-1;
    while(l<=h) {
        mid= (l+h)/2;
        if(key==arr.A[mid]) {
            return mid;
        } else if (key<arr.A[mid]) {
            h=mid-1;

        } else {
            l= mid+1;
        }
        //printf("%d",l,mid,h);
    }
    return -1;
}
int RBinSearch(int a[], int l, int h, int key) {
    int mid;
    if(l<=h) {
        mid=(l+h)/2;
        if(key==a[mid]) {
            printf("%d",mid);
            return mid;
        } else if(key<a[mid]) {
            return RBinSearch(a,l,mid-1,key);
        } else {
            return RBinSearch(a,mid+1,h,key);
        }

    }
    return -1;
}
int Get (struct Array a, int index)
{
    if(index>=0 && index<a.length) {
        return a.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if(index >=0 && index < arr->length) {
        arr->A[index]= x;
    }
}

int Max(struct Array arr) {
    int max = arr.A[0];
    int i;
    for (i=1; i<arr.length; i++)
    {
        if(arr.A[i]>max) {
            max=arr.A[i];
        }
    }
    return max;
}

int Sum (struct Array arr)
{
    int s = 0 ;
    int i ;
    for (i=0; i<arr.length; i++)
    {
        s += arr.A[i];
    }
    return s;
}

int Min (struct Array arr) {
    int min = arr.A[0];
    int i;
    for (i=1; i<arr.length; i++)
    {
        if(arr.A[i]<min) {
            min = arr.A[i];
        }
    }
    return min;
}

float Avg(struct Array arr) {
    return  (float)Sum(arr) / arr.length;
}

void ReverseWithAuxiliaryArray(struct Array *arr) {
    int *B;
    int i,j;
    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0; i>=0; i--,j++) {

        B[j]=arr->A[i];
    }
    for(i=0; i<arr->length; i++) {

        arr->A[i]=B[i];
    }


}

void Reverse(struct Array *arr) {
    int i,j;
    for(i=0,j=arr->length-1; i!=j; i++,j--) {
        swap(&arr->A[i],&arr->A[j]);
    }

}

void leftShift(struct Array *arr) {
    if(arr->length==0) {
        return;
    }
    int i,rotationElemen=arr->A[0];

    for(i=1; i<arr->length; i++) {
        arr->A[i-1]=arr->A[i];
    }
    arr->A[arr->length-1]= rotationElemen;
}
void rightShift(struct Array *arr) {
    if(arr->length==0) {
        return;
    }
    int i,rotationElemen=arr->A[arr->length-1];

    for(i=arr->length-2; i>=0; i--) {
        arr->A[i+1]=arr->A[i];
    }
    arr->A[0]= rotationElemen;
}
void InsertSort(struct Array *arr, int x) {
    int i = arr->length-1;
    if(arr->length==arr->size) {
        printf("There is no space for inserting!\n");
        return;
    }
    while(i>=0 &&arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int isSorted(struct Array arr) {
    int i;
    for(i=0; i<arr.length-1; i++) {
        if(arr.A[i]>arr.A[i+1]) {
            return 0;
        }

    }
    return 1;
}
void Rearrange(struct Array *arr) {
    int i,j;
    i=0;
    j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0) {
            i++;
        }
        while(arr->A[j]>0) {
            j--;
        }
        if(i<j) {
            swap(&arr->A[i],&arr->A[j]);
        }


    }

}

void CreateArray(struct Array *arr,int arrNum) {
    int n,i;
    printf("Enter size of an array num  ");
    std::cout<<arrNum;
    printf(" :");

    scanf("%d",&arr->size);

    arr->A=(int *)malloc(arr->size*sizeof(int));

    arr->length=0;
    printf("Enter Number Of Numbers for array ");

    std::cout<<arrNum;

    printf(" :");

    scanf("%d",&n);
    // if (*n>arr->size) {

    //   printf("The number shouldn't be greater than the size");

    //}
    printf("Enter array elements One by one:\n");
    for(i=0; i<n; i++){
        scanf("%d",&arr->A[i]);
        
        }
    arr->length=n;
}

struct Array* Merge(struct Array *arr1,struct Array *arr2)
{

    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3;
    arr3 =(struct Array* )malloc(sizeof(arr1)+sizeof(arr2));
    arr3->A=(int *)malloc(sizeof(arr1->A)+sizeof(arr2->A));

   
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            
        } else {
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(;i<arr1->length; i++) {
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length; j++) {
        arr3->A[k++]=arr2->A[j];

    }

    arr3->length=arr1->length+arr2->length;
    arr3->size=arr1->size+arr2->size;
return arr3;
}


struct Array* Union(struct Array *arr1,struct Array *arr2)
{

    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3;
    arr3 =(struct Array* )malloc(sizeof(arr1)+sizeof(arr2));
    arr3->A=(int *)malloc(sizeof(arr1->A)+sizeof(arr2->A));

   
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            
        } else if (arr2->A[j]<arr1->A[i]){
            arr3->A[k++]=arr2->A[j++];
        }else{
        
        arr3->A[k++] = arr1->A[i++];
        j++;
        }
    }
    for(;i<arr1->length; i++) {
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length; j++) {
        arr3->A[k++]=arr2->A[j];

    }

    arr3->length = k;
    arr3->size=arr1->size+arr2->size;
return arr3;
}


struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{

    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3;
    arr3 =(struct Array* )malloc(sizeof(arr1)+sizeof(arr2));
    arr3->A=(int *)malloc(sizeof(arr1->A)+sizeof(arr2->A));

   
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            i++;
            
        } else if (arr2->A[j]<arr1->A[i]){
          j++;
        }else if (arr1->A[i]==arr2->A[j]){
        
        arr3->A[k++] = arr1->A[i++];
        j++;
        }
    }
   

    arr3->length = k;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}

struct Array* Diffrence( Array *arr1,struct Array *arr2)
{

    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3;
    arr3 =(struct Array* )malloc(sizeof(arr1)+sizeof(arr2));
    arr3->A=(int *)malloc(sizeof(arr1->A)+sizeof(arr2->A));

   
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            
        } else if (arr2->A[j]<arr1->A[i]){
            j++;
        }else{
        
        i++;
        j++;
        }
    }
    for(;i<arr1->length;i++){
    arr3->A[k++] = arr1->A[i];
    }

    arr3->length = k;
    arr3->size=arr1->size+arr2->size;
return arr3;
}
int main()
{

    struct Array arr;
    struct Array arr2;
    //struct Array arr3;
    struct Array *arr3;
    

    int n,i,appendValue,insertValue,deletedElement, searchingKey, setValue, ch;
    CreateArray(&arr,1);
    CreateArray(&arr2,2);
    
    do{
    //Menu update
    printf("Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    
    printf("Enter your chooice");
    
    scanf("%d",&ch);
    switch(ch)
    {
    case 1: printf("Enter an element and index ");
        scanf("%d%d",&insertValue,&i);
        Insert(&arr,i,insertValue);
        break;
    case 2: printf("Enter index ");
        scanf("%d",&i);
        deletedElement= Delete(&arr,i);
        printf("Deleted Element is %d \n",deletedElement);
        break;
    case 3: printf("Enter element to search ");
        scanf("%d",&searchingKey);
                
        printf("%d\n",LinearSearch(&arr,searchingKey));
        printf("%d\n",BinarySearch(arr,searchingKey));
        break;
    case 4: printf("Sum is %d \n",Sum(arr));
        break;
    
    case 5:Display(arr);

       
        
      
        
    }
    
        }while(ch<6);
    
    //End Menu
    
    
    
    
    
    //printf("get value with index \n");
    //scanf("%d",&searchingKey);
    //printf("%d \n",Get(arr,searchingKey));


    // printf("Insert sorted value :\n");
    //scanf("%d",&insertValue);
    //InsertSort(&arr,insertValue);


  //  printf("%d length value is \n",arr.length);

    //printf("%d Max value is \n",Max(arr));
    //printf("%d Min value is \n",Min(arr));
   // printf("%d Sum of values is \n",Sum(arr));
    // printf("%f Avg of values is \n",Avg(arr));
    // printf("%d  is sorted ",isSorted(arr));
    //  printf("Set new value \n");
    //scanf("%d",&setValue);
    // Set(&arr,searchingKey,setValue);

    // printf("Search for a key");
    // scanf("%d",&searchingKey);
    //printf("%d\n",LinearSearch(&arr,searchingKey));
    //printf("%d\n",BinarySearch(arr,searchingKey));
    // printf("%d\n",RBinSearch(arr.A,0,arr.length,searchingKey));
    //  printf("Append new value");
    //  printf("Insert new value:\n");



    //scanf("%d",&insertValue);

    // printf("index:\n");
    //scanf("%d",&i);

    //Append(&arr,appendValue);
    //Insert(&arr,i,insertValue);

// printf("Delete a value in index:\n");

    //scanf("%d",&deleteIndex);
    //Delete(&arr,deleteIndex);
    // Rearrange(&arr);
    //Display(arr);
 

 //   arr3=Merge(&arr,&arr2);
    //arr3=Union(&arr,&arr2);
    //arr3=Intersection(&arr,&arr2);
  //  arr3=Diffrence(&arr,&arr2);
  //  Display(*arr3);
    //Reverse(&arr);
    //rightShift(&arr);
    //Display(arr);
    //rightShift(&arr);
    //Display(arr);


    return 0;
}
    