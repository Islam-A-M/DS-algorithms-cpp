
void toLowerCase(char A[])
{
    //char A[]="WELCOME";
    int i;
    for(i=0; A[i]!='\0'; i++)
    {
        A[i]=A[i]+32;
    }
    printf("%s \n",A);

}
void toggleCase()
{
    char A[]="WeLcOmE";
    int i;
    for(i=0; A[i]!='\0'; i++)
    {
        if(A[i]>=65&&A[i]<=90) {
            A[i]=A[i]+32;
        } else if (A[i]>='a'&&A[i]<=122) {
            A[i]=A[i]-32;
        }
    }
    printf("%s \n",A);
}
void getVowelsAndConsonants() {
    char A[] = "How are you";
    int i, vcount,ccount= 0;
    for(i=0; A[i]!='\0'; i++)
    {
        if(A[i]=='a'|| A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u' ||A[i]=='A'|| A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='U') {
            vcount++;
        } else if ((A[i]>=65&& A[i]<=90)||(A[i]>=97&&A[i]<=122))
        {
            ccount++;
        }

    }
    printf("Vowels is %d and consonants is %d \n",vcount,ccount);
}

void countWords(char A[])
{
    int i,word=1;
    for(i=0; A[i]!='\0'; i++)
    {
        if(A[i]==' '&&A[i-1]!=' ')
        {
            word++;
        }
    }
    printf("Words count is %d \n",word);
}
int isValid(char *name) {
    int i;
    for(i=0; name[i]!='\0'; i++)
    {
        if(!(name[i]>=65&&name[i]<=90)
                &&!(name[i]>=97&&name[i]<=122)
                &&!(name[i]>=48&&name[i]<=57)) {
            return 0;
        }
    }
    return 1;
}

void reverse(char A[]) {

    int i;
    for(i=0; A[i]!='\0'; i++)
    {}

    i=i-1;
    char B[i];
    int j;
    for(j=0; i>=0; i--,j++)
    {
        B[j]=A[i];
    }
    B[j]='\0';
    printf("%s \n",B);

}
void reverse2(char A[]) {
    char t;
    int i,j;
    for(j=0; A[j]!='\0'; j++)
    {}
    j=j-1;
    for(i=0; i<j; i++,j--)
    {
        t=A[i];
        A[i]=A[j];
        A[j]=t;
    }
}
void compareStrings(char A[], char B[], int caseSensetive)
{

    int i,j;

    for(i=0,j=0; A[i]!='\0'&&B[j]!='\0'; i++,j++)
    {


        if(caseSensetive == 0)
        {

            if(A[i]>=65&&A[i]<=90) {
                A[i]=A[i]+32;
            }
            if(B[j]>=65&&B[j]<=90) {
                B[j]=B[j]+32;
            }
        }
        if(A[i]!=B[j])
        {
            break;
        }

    }

    if(A[i]==B[j]) {

        printf("equal");
    } else if(A[i]>B[j]) {
        printf("ASCII code for diff char Greater");
    } else {
        printf("ASCII code for diff char Smaller");
    }
}
void checkPlalindrom2(char A [])
{

    int i,j;
    for(j=0; A[j]!='\0'; j++)
    {}
    j=j-1;
    for(i=0; i<j; i++,j--) {
        if(A[i]!=A[j])
        {

            printf("Not Palindrom");
            break;
        }
    }
}
void checkPalindrom(char A[])
{
    int i;

    for(i=0; A[i]!='\0'; i++)
    {}

    i=i-1;
    char B[i];
    for(i=0; A[i]!='\0'; i++)
    {
        B[i]=A[i];
    }



    reverse2(B);
    printf("%s \n",B);
    compareStrings(A,B,1);
}
void findDuplicateUnsortedArrayStr(char A[])
{

    int length;
    for(length=0; A[length]!='\0'; length++)
    {}

    for(int i = 0; i<length; i++)
    {
        int count = 1;
        for(int j = i+1; j<length; j++)
        {
            if(A[i]==A[j] &&A[i]!='0') {
                A[j]='0';
                count++;

            }
        }
        if(count>1 ) {
            cout<<A[i]<<" duplicated "<<count<< " times"<<endl;
//printf("%c is duplicated %d times \n",A[i],count);

        }
    }


}
void findDuplicatedCharHashtable(char A[])
{
    int H[52]= {0},i;
    // for(int o=0; o<52; o++) {
    //   H[o]=0;

    //}
    for(i = 0; A[i]!='\0'; i++)
    {
        if(A[i]>='a'&&A[i]<='z') {



            H[A[i]-97]+=1;
        } else if(A[i]>='A'&&A[i]<='Z')
        {

            H[A[i]-65+26]+=1;
        }
    }
    cout<<"length"<<i<<endl;

    for(int j = 0 ; j<52; j++) {
        if(H[j]>1) {

            if(j>=26) {
                int index = j-26;
                printf("%c is duplicated %d times \n",index+65,H[j]);
            } else {
                printf("%c is duplicated %d times \n",j+97,H[j]);

            }
        }
    }
}
void findDuplicates(char A[])
{
    long int H=0,x=0;
    for(int i=0; A[i]!='\0'; i++)
    {
        x=1;
        x=x<<(A[i]-97);
        if((x&H)>0)
        {
            printf("%c is Duplicates \n",A[i]);

        } else {
            H=x|H;
        }
    }

}
void checkIfAnagram(char A[], char B [])
{
    int i, H[26]= {0};
    for(i=0; A[i]!='\0'; i++)
    {
        H[A[i]-97]+=1;
    }
    for(i=0; B[i]!='\0'; i++) {
        H[B[i]-97]-=1;


    }
    for(int n=0; n<i; n++)
    {
        if(H[n]!=0) {

            printf("not anagram");
            return;

        }
    }

    if(B[i]=='\0')
    {
        printf("Its Anagram");
    }
}
void perm(char s[],int k) {
    static int A[10]= {0};
    static char Res[10];

    int i;
    if(s[k]=='\0') {
        Res[k]='\0';
        printf(Res);
        printf("\n");
    } else {
        for(i=0; s[i]!='\0'; i++) {
            if(A[i]==0) {
                Res[k]=s[i];
                A[i]=1;
                perm(s,k+1);
                A[i]=0;
            }

        }
    }

}

void PermSwap(char s[],int l, int h) {
    int i;
    if(l==h) {
        printf(s);
        printf("\n");
    } else {
        for(i=l; i<=h; i++) {
            swap(s[l],s[i]);
            PermSwap(s,l+1,h);
            swap(s[l],s[i]);
        }

    }
}

void testString(){
    // char string[]= "Welcome";
    //  int indexLength;
    //  for(indexLength=0;string[indexLength]!='\0';indexLength++)
    //  {
    // }
    // printf("Length is %d",indexLength);
//toggleCase("wOrD");
//getVowelsAndConsonants();
//countWords("Hello  World");

//char *name = "Anit321";
//if(isValid(name)){
//cout<<"valid"<<endl;
//}else{
//cout<<"not valid"<<endl;
//}
//char A[]="islam";
//reverse(A);
    // char A[]="azza";
    // checkPlalindrom2(A);
    // char B[]="islam";
    //compareStrings(A,B,0);
    // reverse2(A);
    //printf("%s ",A);
    
  //  struct Matrix m;
   // m.n=4;
  //  setDiagonal(&m,1,1,5);
  //  setDiagonal(&m,2,2,8);
  //  setDiagonal(&m,3,3,9);
   // setDiagonal(&m,4,4,12);
   // int getD = getDiagonal(m,2,2);
   // printf("%d \n",getD);
   // DisplayMatrix(m);

    //char A[]= "abc";
    //char B[]="malsi";
    //perm(A,0);
    //PermSwap(A,0,2);
// findDuplicateUnsortedArrayStr(A);
    // findDuplicatedCharHashtable(A);
    //findDuplicates(A);

    // checkIfAnagram(A,B);
    
}