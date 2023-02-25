
class SymmetricMatrix {
private:
    int n;
    int *A;
public:
    SymmetricMatrix(){
      n=2;
      A=new int[2*(2+1)/2];
    }
    SymmetricMatrix(int n) {
        this->n=n;
        A=new int [n*(n+1)/2]{0};

    }
    void Set(int i, int j,int x);
    int Get(int i,int j);
    int GetDimension(){return n;}
    void Display();
    ~SymmetricMatrix ()
    {
        delete []A;

    }
};
void SymmetricMatrix::Set(int i, int j,int x) {
    if(i<=j) {
        A[(i-1)*n-(i-2)*(i-1)/2+(j-1)]=x;
    }
}

int SymmetricMatrix::Get(int i,int j) {
    if(i<=j)
    {
        return A[(i-1)*n-(i-2)*(i-1)/2+(j-1)];
    } else {
        return 0;
    }
}

void SymmetricMatrix::Display() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i<=j) {
                cout<<A[(i-1)*n-(i-2)*(i-1)/2+(j-1)]<<" ";
            } else {
           //     cout<<"0 ";
            cout<<A[i*(i-1)/2+j-1]<<" ";
            }


        }
                cout<<endl;

    }

}


void testSymmetricMatrixMatrixRowMajorClass(){
  int d;
  cout<<"Enter Dimensions";
  cin>>d;
  
  SymmetricMatrix lm(d);
  int x;
  cout<<"Enter All Elements";
  for(int i=1;i<=d;i++){
      for(int j=1;j<=d;j++){
          cin>>x;
          lm.Set(i,j,x);
          
      }
      
  }
  lm.Display();
 
    
}