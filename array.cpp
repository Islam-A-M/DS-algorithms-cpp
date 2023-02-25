
template<class T>

class Array
{
private:
    T *A;
    int size;
    int length;

    void swap(T *x, T *y);

public:

    Array ()
    {
        size = 10;
        length = 0;
        A= new T[size];

    }
    Array (int sz)
    {
        size = sz;
        length = 0;
        A=new T[size];
    }

    ~Array ()
    {
        delete []A;

    }
    int get_length() {

        return length;
    }


    //int get_length();
    void Display();
    void Append(T x);
    void Insert(int index, T x);
    void CreateArray (int arrNum);


    T LinearSearch(int key);
    T BinarySearch(int key);
    //int RBinSearch(int a[], int l, int h, int key);
    T Delete(int index);
    T  Get(int index);
    void Set( int index, T x);
    int Max();
    int Min ();
    int Sum ();
    float Avg();
    void ReverseWithAuxiliaryArray();
    void Reverse();
    void InsertSort(T x);
    int isSorted();
    void Rearrange();
    void leftShift();
    void rightShift();
    Array<T>* Merge(Array<T> &arr2);
    Array<T>* Union(Array<T> &arr2);
    Array<T>* Intersection(Array<T> &arr2);
    Array<T>* Diffrence(Array<T> &arr2);
    T findMissingElement();
    void findMissingElements();
    void findMissingElementsUnsorted();
    void findDuplicateSortList();
    void findDuplicateSortListAndCount();
    void findDuplicateSortingListAndCountHash();
    void findDuplicateUnsortedArray();
    void findDuplicateUnsortedArrayHashtable();
    void findPairWithSumk(T k);
    void findPairWithSumkHashtable(T k);
    void findPairWithSumksorted(T k);
    void isThereDiffrenceEqTo(int s);

    //void Sort();
    //void CreateArray(int arrNum);
//private:

};
template<class T>
void Array<T>::findMissingElementsUnsorted() {

    //or sort it
    int l = A[0];
    int h = A[0];
    int n = length;
    cout<<"Missing elements is"<<endl;
    for(int i = 0 ; i<n; i++)
    {

        if(A[i]<l)
        {
            l=A[i];
        }
        if(A[i]>h) {
            h=A[i];
        }
    }
    Array *H = new Array(h);
    for(int i = 0 ; i<n; i++)
    {

        H->A[A[i]]++;
    }
    for(int i= l; i<=h; i++ )
    {
        if(H->A[i]==0) {
            cout<<i<<endl;
        }
    }
}
template<class T>
T Array<T>::findMissingElement()
{
    T sum = 0;
    for (int i=0; i<length; i++) {
        sum = sum +A[i];
    }

    T s =A[length-1]*(A[length-1]+1)/2;

    return s-sum;
}

template<class T>
void Array<T>::findMissingElements()
{
    T l = A[0];
    T h = A[length-1];
    int n = length;
    T diff=l-0;
    cout<<"Missing elements is"<<endl;
    for(int i = 0 ; i<n; i++) {

        if(A[i]-i != diff) {
            while(diff<A[i]-i) {
                cout<<i+diff<<endl;
                diff++;
            }


        }

    }
}
template<class T>
void Array<T>::Display() {

    int i;

    printf("\nElements are\n");
    for(i=0; i<length; i++) {
        printf("%d",A[i]);
    }
    cout<<"\n"<<endl;
    cout<<"pair with sum k number"<<endl;
    // isThereDiffrenceEqTo(4);
    //findPairWithSumksorted(7);
    // findPairWithSumkHashtable(7);
    //findPairWithSumk(6);

    // cout<<"Duplicate element"<<endl;
    //findDuplicateUnsortedArrayHashtable();
    // findDuplicateUnsortedArray();
    // findDuplicateSortingListAndCountHash();
    //findDuplicateUnsortedArray();
    //findDuplicateSortList();
    // findDuplicateSortListAndCount();
    //cout<<findMissingElement()<<endl;
    //findMissingElements();
    // findMissingElementsUnsorted();
    // if(i>arr.length-1) {
    //    printf(" , ");
    // }
}
template<class T>
void Array<T>::Append(T x) {
    if(length<size) {
        A[length++]=x;
    }
}
template<class T>
void Array<T>::Insert(int index, T x) {
    int i;
    if(index>=0 && index <= length) {

        for(i=length; i>index; i--)
            A[i]=A[i-1];

        A[index]=x;
        length++;

    }
}
template<class T>
T Array<T>::Delete( int index) {
    T x= 0;
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
template<class T>
void Array<T>::swap(T *x, T *y) {
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}
template<class T>
T Array<T>::LinearSearch(int key) {
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
template<class T>
T Array<T>::BinarySearch(int key) {
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

template<class T>
T Array<T>::Get (int index)
{
    if(index>=0 && index<length) {
        return A[index];
    }
    return -1;
}
template<class T>
void Array<T>::Set(int index, T x)
{
    if(index >=0 && index < length) {
        A[index]= x;
    }
}
template<class T>
int Array<T>::Max() {
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
template<class T>
int Array<T>::Sum ()
{
    int s = 0 ;
    int i ;
    for (i=0; i<length; i++)
    {
        s += A[i];
    }
    return s;
}
template<class T>
int Array<T>::Min () {
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
template<class T>
float Array<T>::Avg() {
    return  (float)Sum() / length;
}
template<class T>
void Array<T>::ReverseWithAuxiliaryArray() {
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
template<class T>
void Array<T>::Reverse() {
    int i,j;
    for(i=0,j=length-1; i!=j; i++,j--) {
        swap(&A[i],&A[j]);
    }

}
template<class T>
void Array<T>::leftShift() {
    if(length==0) {
        return;
    }
    int i,rotationElemen=A[0];

    for(i=1; i<length; i++) {
        A[i-1]=A[i];
    }
    A[length-1]= rotationElemen;
}
template<class T>
void Array<T>::rightShift() {
    if(length==0) {
        return;
    }
    int i,rotationElemen=A[length-1];

    for(i=length-2; i>=0; i--) {
        A[i+1]=A[i];
    }
    A[0]= rotationElemen;
}
template<class T>
void Array<T>::InsertSort(T x) {
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
template<class T>
int Array<T>::isSorted() {
    int i;
    for(i=0; i<length-1; i++) {
        if(A[i]>A[i+1]) {
            return 0;
        }

    }
    return 1;
}
template<class T>
void Array<T>::Rearrange() {
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


template<class T>
void Array<T>::CreateArray (int arrNum) {
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
    for(i=0; i<n; i++) {
        scanf("%d",&A[i]);

    }
    length=n;
}
template<class T>
Array<T>* Array<T>::Merge(Array<T> &arr2) {

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
    for(; i<length; i++) {
        arr3->A[k++]=A[i];
    }
    for(; j<arr2.get_length(); j++) {
        arr3->A[k++]=arr2.A[j];

    }

    arr3->length=length+arr2.get_length();
//    arr3->size=size+arr2.size;
    return arr3;
}

template<class T>
Array<T>* Array<T>::Union(Array<T> &arr2)
{

    int i,j,k;
    i=j=k=0;

    struct Array *arr3;
    arr3 = new Array(length+arr2.get_length());
    //arr3 =(struct Array* )malloc(sizeof(arr1)+sizeof(arr2));
    // arr3->A=(int *)malloc(sizeof(arr1->A)+sizeof(arr2->A));


    while(i<length && j<arr2.get_length())
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k++]=A[i++];

        } else if (arr2.A[j]<A[i]) {
            arr3->A[k++]=arr2.A[j++];
        } else {

            arr3->A[k++] = A[i++];
            j++;
        }
    }
    for(; i<length; i++) {
        arr3->A[k++]=A[i];
    }
    for(; j<arr2.get_length(); j++) {
        arr3->A[k++]=arr2.A[j];

    }

    arr3->length = k;
    // arr3->size=arr1->size+arr2->size;
    return arr3;
}

template<class T>
Array<T>* Array<T>::Intersection(Array<T> &arr2)
{

    int i,j,k;
    i=j=k=0;

    struct Array *arr3;
    arr3 = new Array(length+arr2.get_length());
    //arr3 =(struct Array* )malloc(sizeof(arr1)+sizeof(arr2));
    // arr3->A=(int *)malloc(sizeof(arr1->A)+sizeof(arr2->A));


    while(i<length && j<arr2.get_length())
    {
        if(A[i]<arr2.A[j])
        {
            i++;

        } else if (arr2.A[j]<A[i]) {
            j++;
        } else if (A[i]==arr2.A[j]) {

            arr3->A[k++] = A[i++];
            j++;
        }
    }


    arr3->length = k;
    //arr3->size=arr1->size+arr2->size;
    return arr3;
}
template<class T>
Array<T>* Array<T>::Diffrence(Array<T> &arr2)
{

    int i,j,k;
    i=j=k=0;

    struct Array *arr3;
    arr3 = new Array(length+arr2.get_length());
    //  arr3 =(struct Array* )malloc(sizeof(arr1)+sizeof(arr2));
    //arr3->A=(int *)malloc(sizeof(arr1->A)+sizeof(arr2->A));


    while(i<length && j<arr2.get_length())
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k++]=A[i++];

        } else if (arr2.A[j]<A[i]) {
            j++;
        } else {

            i++;
            j++;
        }
    }
    for(; i<length; i++) {
        arr3->A[k++] = A[i];
    }

    arr3->length = k;
    //  arr3->size=arr1->size+arr2->size;
    return arr3;
}
template<class T>
void Array<T>::findDuplicateSortList()
{
    T lastDuplicate ;
    int n = length;
    for(int i=0; i<n; i++) {
        if(A[i]==A[i+1]&&A[i]!=lastDuplicate) {
            cout<<A[i]<<endl;
            lastDuplicate = A[i];
        }
    }
}
template<class T>
void Array<T>::findDuplicateSortListAndCount()
{
    int n = length-1;
    int i;
    for(i=0; i<n; i++) {
        if(A[i]==A[i+1]) {
            int count= i+1;
            while(A[count]==A[i])count++;
            printf("%d is appearing %d times \n", A[i],count-i);
            i=count-1;
        }
    }
}

template<class T>
void Array<T>::findDuplicateSortingListAndCountHash() {
    Array *H = new Array(A[length-1]);
    for(int i=0; i<length; i++) {
        H->A[A[i]]++;
    }
    for(int i=0; i<=H->size; i++)
    {
        if(H->A[i]>1)printf("Element %d is duplicated %d times \n",i,H->A[i]);
    }
}

template<class T>
void Array<T>::findDuplicateUnsortedArray()
{
//O(n2)

    for(int i = 0; i<length-1; i++)
    {
        int count = 1;
        if(A[i]!=-1)
        {
            for(int j= i+1; j<length; j++)
            {
                if(A[i]==A[j])
                {
                    count++;
                    A[j]=-1;
                }

            }
            if(count>1)printf("number %d is duplicated %d Times \n",A[i],count);
        }
    }
}
template<class T>
void Array<T>::findDuplicateUnsortedArrayHashtable()
{
//o(n)
    T h = A[0];
    for(int i = 0; i<length; i++)
    {
        if(A[i]>h)
        {
            h=A[i];
        }
    }
    Array *H = new Array(h);
    for(int i=0; i<length; i++) {
        H->A[A[i]]++;
    }
    for(int i = 0; i<=H->size; i++) {
        if(H->A[i]>1) {
            printf("number %d is duplicated %d Times \n",i,H->A[i]);
        }
    }
}
template<class T>
void Array<T>::findPairWithSumk(T k)
{
//Unsorted list
//quadratic time o(n2)
    for(int i = 0 ; i<length-1; i++)
    {
        for(int j = i+1; j<length; j++)
        {
            if(A[i]+A[j] == k)
            {
                printf("%d + %d = %d",A[i],A[j],k);
            }
        }
    }
}

template<class T>
void Array<T>::findPairWithSumkHashtable(T k)
{
//unsorted array
//Time o(2n) = o(n)
// it's trade off if we want save space the time will be more
//if we want to save time the space will be more
    T h = A[0];
//T l = A[0];

    for(int i = 0; i<length; i++) {
        if(A[i]>h) {
            h=A[i];
        }
//if(A[i]<l){
//l=A[i];
//}
    }
    Array *H = new Array(h);
    for(int i = 0; i<length; i++ ) {
        if(H->A[k-A[i]]!=0) {
            printf("%d + %d = %d\n",A[i],k-A[i],k);

        }
        H->A[A[i]]=1;
    }

}
template<class T>
void Array<T>::findPairWithSumksorted(T k)
{
//o(n) its linear
    int i=0,j=length-1;
    //for(int i=0,j=length-1;i<k)
    while(i<j)
    {
        if(A[i]+A[j]==k)
        {
            printf("%d + %d = %d \n",A[i],A[j],k);
            i++;
            j--;
        } else if (A[i]+A[j]>k)
        {
            j--;
        } else
        {
            i++;
        }
    }
}
template<class T>
void Array<T>::isThereDiffrenceEqTo(int s)
{
    int i=0,j=1;
    while(j<length) {
        if(A[j]-A[i]<s) {
            j++;
        } else if(A[j]-A[i]==s) break;
        else i++;
    }
    if(j<length) printf("yes");
}

void testArray(){
 Array<int> *arr;
    Array<int> *arr2;
    
    //struct Array arr3;
    Array<int> *arr3;


    int n,i,size,appendValue,insertValue,deletedElement, searchingKey, setValue, ch;
    printf("Enter size of an array num  1");
    //std::cout<<arrNum;
    printf(" :");

    scanf("%d",&size);

    arr = new Array<int>(size);
    arr->CreateArray(1);
    printf("Enter size of an array num  2");
    //std::cout<<arrNum;
    printf(" :");

    scanf("%d",&size);

    arr2 = new Array<int>(size);
    arr2->CreateArray(2);

    do {
        //Menu update
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Merge\n");
        printf("6. Display\n");

        printf("7. Exit\n");

        printf("Enter your chooice");

        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter an element and index ");
            scanf("%d%d",&insertValue,&i);
            arr->Insert(i,insertValue);
            break;
        case 2:
            printf("Enter index ");
            scanf("%d",&i);
            deletedElement= arr->Delete(i);
            printf("Deleted Element is %d \n",deletedElement);
            break;
        case 3:
            printf("Enter element to search ");
            scanf("%d",&searchingKey);

            printf("%d\n",arr->LinearSearch(searchingKey));
            printf("%d\n",arr->BinarySearch(searchingKey));
            break;
        case 4:
            printf("Sum is %d \n",arr->Sum());
            break;
        case 5:
            arr3=arr->Merge(*arr2);
            arr3->Display();
            break;
        case 6:
            arr->Display();





        }

    } while(ch<7);

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


}