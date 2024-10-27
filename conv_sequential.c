#include<stdio.h>
#include<stdlib.h>

int main(){
    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < NF; i++){
        scanf("%d", &F[i]);
    }
    // ---- end input and malloc----

    // implement here
    printf("\n");
   
    int nowpos=0;
    int sum;
    while(nowpos+NF<=NA){
        sum=0;
        for(int i=0;i<NF;i++){
            sum+=A[nowpos+i]*F[NF-1-i];
        }
        printf("%d\n",sum);
        nowpos++;
    }

    // ---- free memory ----
    free(F);
    free(A);
    // ---- end free ----
    return 0;
}