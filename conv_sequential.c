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

    int *ans=malloc(sizeof(int) * NA-NF+1);
    
    for(int k=0;k<=NA-NF;k++){
        ans[k]=0;
        for(int i=0;i<NF;i++){
            ans[k]+=A[k+i]*F[NF-1-i];
        }
    }
    
    for(int k=0;k<=NA-NF;k++){
        printf("%d\n",ans[k]);
    }

    // ---- free memory ----
    free(ans);
    free(F);
    free(A);
    // ---- end free ----
    return 0;
}