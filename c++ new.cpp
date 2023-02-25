
#include<iostream>
//#include "stdafx.h"
#include<stdlib.h>
using namespace std;


class Array
{
private:
    int *A;
    int size;
    int length;
    
    void swap(int *x, int *y);
    
public:
    
    Array ()
    {
        size = 10;
        length = 0;
        A= new int[size];
    
    }
    Array (int sz)
    {
        size = sz;
        length = 0;
        A=new int [size];
    }
    
    ~Array ()
    {
    delete []A;
    
    }
    int get_length(){
  
        return length;
    }


    //int get_length();
    void Display();
    void Append(int x);
    void Insert(int index , int x);
    void CreateArray (int arrNum);

    int LinearSearch(int key);
    int BinarySearch(int key);
    //int RBinSearch(int a[], int l, int h, int key);
    int Delete(int index);
    int  Get(int index);
    void Set( int index, int x);
    int Max();
    int Min ();
    int Sum ();
    float Avg();
    void ReverseWithAuxiliaryArray();
    void Reverse();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    void leftShift();
    void rightShift();
    //void CreateArray(int arrNum);
//private:
 
    Array* Merge(Array *arr2);
    Array* Union(Array *arr2);
    Array* Intersection(Array *arr2);
    Array* Diffrence(Array *arr2);
};



void Array::Display() {

    int i;
    printf("\nElements are\n");
    for(i=0; i<length; i++){
        printf("%d",A[i]);
        }
  // if(i>arr.length-1) {
    //    printf(" , ");
   // }
}
void Array::Append(int x) {
    if(length<size) {
        A[length++]=x;
    }
}

void Array::Insert(int index, int x) {
    int i;
    if(index>=0 && index <= length) {

        for(i=length; i>index; i--)
            A[i]=A[i-1];

        A[index]=x;
        length++;

    }
}
int Array::Delete( int index) {
    int x= 0;
    int i;
    if(index>=0 && index<length) {
        x=A[index];
        for(i=index; i<length-1; i++)
            A[i]=A[i+1];
        length--;
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
int Array::LinearSearch(int key) {
    int i;
    for(i=0; i<length; i++) {
        if(key==A[i]) {
            if(i!=0) {
                swap(&A[i], &A[0]);
                //swap(&arr->A[i], &arr->A[i-1]);
            }
            return i;

        }
    }
    return -1;
}
int Array::BinarySearch(int key) {
    int l,mid,h;
    l=0;
    h=length-1;
    while(l<=h) {
        mid= (l+h)/2;
        if(key==A[mid]) {
            return mid;
        } else if (key<A[mid]) {
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
int Array::Get (int index)
{
    if(index>=0 && index<length) {
        return A[index];
    }
    return -1;
}

void Array::Set(int index, int x)
{
    if(index >=0 && index < length) {
        A[index]= x;
    }
}

int Array::Max() {
    int max = A[0];
    int i;
    for (i=1; i<length; i++)
    {
        if(A[i]>max) {
            max=A[i];
        }
    }
    return max;
}

int Array::Sum ()
{
    int s = 0 ;
    int i ;
    for (i=0; i<length; i++)
    {
        s += A[i];
    }
    return s;
}

int Array::Min () {
    int min = A[0];
    int i;
    for (i=1; i<length; i++)
    {
        if(A[i]<min) {
            min = A[i];
        }
    }
    return min;
}

float Array::Avg() {
    return  (float)Sum() / length;
}

void Array::ReverseWithAuxiliaryArray() {
    int *B;
    int i,j;
    B=(int *)malloc(length*sizeof(int));
    for(i=length-1,j=0; i>=0; i--,j++) {

        B[j]=A[i];
    }
    for(i=0; i<length; i++) {

        A[i]=B[i];
    }


}

void Array::Reverse() {
    int i,j;
    for(i=0,j=length-1; i!=j; i++,j--) {
        swap(&A[i],&A[j]);
    }

}

void Array::leftShift() {
    if(length==0) {
        return;
    }
    int i,rotationElemen=A[0];

    for(i=1; i<length; i++) {
        A[i-1]=A[i];
    }
    A[length-1]= rotationElemen;
}
void Array::rightShift() {
    if(length==0) {
        return;
    }
    int i,rotationElemen=A[length-1];

    for(i=length-2; i>=0; i--) {
        A[i+1]=A[i];
    }
    A[0]= rotationElemen;
}
void Array::InsertSort(int x) {
    int i = length-1;
    if(length==size) {
        printf("There is no space for inserting!\n");
        return;
    }
    while(i>=0 && A[i]>x)
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=x;
    length++;
}

int Array::isSorted() {
    int i;
    for(i=0; i<length-1; i++) {
        if(A[i]>A[i+1]) {
            return 0;
        }

    }
    return 1;
}
void Array::Rearrange() {
    int i,j;
    i=0;
    j=length-1;
    while(i<j)
    {
        while(A[i]<0) {
            i++;
        }
        while(A[j]>0) {
            j--;
        }
        if(i<j) {
            swap(&A[i],&A[j]);
        }


    }

}

void Array::CreateArray (int arrNum) {
    int n,i,size;

//    arr->A=(int *)malloc(arr->size*sizeof(int));
 
    length=0;
    printf("Enter Number Of Numbers for array ");

    std::cout<<arrNum;

    printf(" :");

    scanf("%d",&n);
    // if (*n>arr->size) {

    //   printf("The number shouldn't be greater than the size");

    //}
    printf("Enter array elements One by one:\n");
    for(i=0; i<n; i++){
        scanf("%d",&A[i]);
        
        }
    length=n;
}

Array* Array::Merge(Array arr2)
{

    int i,j,k;
    i=j=k=0;
    
    Array *arr3;
    //arr3 =(struct Array* )malloc(sizeof(arr1)+sizeof(arr2));
    arr3 = new Array(this->length+arr2.get_length());
    //arr3->A=(int *)malloc(sizeof(arr1->A)+sizeof(arr2->A));

   
    while(i<length && j<arr2.get_length())
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k++]=A[i++];
            
        } else {
            arr3->A[k++]=arr2.A[j++];
        }
    }
    for(;i<length; i++) {
        arr3->A[k++]=A[i];
    }
    for(;j<arr2.length; j++) {
        arr3->A[k++]=arr2.A[j];

    }

    arr3->length=length+arr2.length;
//    arr3->size=size+arr2.size;
return arr3;
}


Array* Union(Array arr2)
{

    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3;
    arr3 = new Array(length+arr2.length);
    //arr3 =(struct Array* )malloc(sizeof(arr1)+sizeof(arr2));
   // arr3->A=(int *)malloc(sizeof(arr1->A)+sizeof(arr2->A));

   
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k++]=A[i++];
            
        } else if (arr2.A[j]<A[i]){
            arr3->A[k++]=arr2.A[j++];
        }else{
        
        arr3->A[k++] = A[i++];
        j++;
        }
    }
    for(;i<length; i++) {
        arr3->A[k++]=A[i];
    }
    for(;j<arr2.length; j++) {
        arr3->A[k++]=arr2.A[j];

    }

    arr3->length = k;
   // arr3->size=arr1->size+arr2->size;
return arr3;
}


Array* Intersection(Array arr2)
{

    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3;
    arr3 = new Array(length+arr2.length);
    //arr3 =(struct Array* )malloc(sizeof(arr1)+sizeof(arr2));
   // arr3->A=(int *)malloc(sizeof(arr1->A)+sizeof(arr2->A));

   
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            i++;
            
        } else if (arr2.A[j]<A[i]){
          j++;
        }else if (A[i]==arr2.A[j]){
        
        arr3->A[k++] = A[i++];
        j++;
        }
    }
   

    arr3->length = k;
    //arr3->size=arr1->size+arr2->size;
    return arr3;
}

Array* Diffrence(Array arr2)
{

    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3;
      arr3 = new Array(length+arr2.length);
  //  arr3 =(struct Array* )malloc(sizeof(arr1)+sizeof(arr2));
    //arr3->A=(int *)malloc(sizeof(arr1->A)+sizeof(arr2->A));

   
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k++]=A[i++];
            
        } else if (arr2.A[j]<A[i]){
            j++;
        }else{
        
        i++;
        j++;
        }
    }
    for(;i<length;i++){
    arr3->A[k++] = A[i];
    }

    arr3->length = k;
  //  arr3->size=arr1->size+arr2->size;
return arr3;
}
int main()
{

    Array *arr;
    Array *arr2;
    //struct Array arr3;
    Array *arr3;
    

    int n,i,size,appendValue,insertValue,deletedElement, searchingKey, setValue, ch;
    printf("Enter size of an array num  1");
    //std::cout<<arrNum;
    printf(" :");

    scanf("%d",&size);

    arr = new Array(size);
    CreateArray(&arr,1);
    printf("Enter size of an array num  2");
    //std::cout<<arrNum;
    printf(" :");

    scanf("%d",&size);

    arr2 = new Array(size);
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
        arr.Insert(i,insertValue);
        break;
    case 2: printf("Enter index ");
        scanf("%d",&i);
        deletedElement= arr.Delete(i);
        printf("Deleted Element is %d \n",deletedElement);
        break;
    case 3: printf("Enter element to search ");
        scanf("%d",&searchingKey);
                
        printf("%d\n",arr.LinearSearch(searchingKey));
        printf("%d\n",BinarySearch(arr,searchingKey));
        break;
    case 4: printf("Sum is %d \n",arr.Sum());
        break;
    
    case 5:arr.Display();

       
        
      
        
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
    