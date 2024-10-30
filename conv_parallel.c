#include<stdio.h>
#include<stdlib.h>
#include<omp.h>


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
    
    int *ans=malloc(sizeof(int) * NA-NF+1);

    #pragma omp parallel for num_threads(4)
    for(int i=0;i<NA-NF+1;i++){
        ans[i]=0;
        for(int j=0;j<NF;j++){
            ans[i]+=A[i+j]*F[NF-j-1];
        }
    }
    
    for(int i=0;i<=NA-NF;i++){
        printf("%d\n",ans[i]);
    }

    // ---- free memory ----
    free(ans);
    free(F);
    free(A);
    // ---- end free ----
    return 0;
}