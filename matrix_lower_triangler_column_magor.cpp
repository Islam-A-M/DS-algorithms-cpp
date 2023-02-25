// row major
struct Matrix
{
    int *A;
    int n;
};

// row major
void set(struct Matrix *m, int i, int j, int x) {

    if(i >= j) {
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j] = x;
    }

}
// row major
int get(struct Matrix m, int i, int j) {
    if(i >= j) {
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
    } else {
        return 0;
    }
}
// row major
void Display(struct Matrix m) {
    int i,
    j;
    for(i = 1; i <= m.n; i++) {
        for(j = 1; j <= m.n; j++) {
            if(i >= j) {
                printf("%d ", m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]);

            } else {
                printf("0 ");
            }


        }
        printf("\n");
    }

}

void testMatrixColumnMajor() {
    struct Matrix m;
    int i,
    j,
    x;
    printf("Enter Dimension \n");

    scanf("%d", &m.n);

    m.A = (int *)malloc(m.n*(m.n-1)/2*sizeof(int));
    printf("enter all elements \n");
    for(i = 1; i <= m.n; i++) {
        for(j = 1; j <= m.n; j++) {
            scanf("%d", &x);
            set(&m, i, j, x);

        }

    }
    printf("\n\n");
    Display(m);
}