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
    int *FF=malloc(sizeof(int) * NF);

    for(int i=0;i<NA-NF+1;i++){
        ans[i]=0;
    }

    for(int i=0;i<NF;i++){
        FF[i]=F[NF-i-1];
    }
    
    for(int i=0;i<NA;i++){
        //int tid=omp_get_thread_num();
        for(int j=0;j<NF;j++){
            if(i-j<0){
                break;
            }
            if(i-j>NA-NF){
                continue;
            }
            //printf("T:%d i=%d j=%d i-j=%d\n",tid,i,j,i-j);
            ans[i-j]+=A[i]*FF[j];
        }
    }
    
    for(int i=0;i<=NA-NF;i++){
        printf("%d\n",ans[i]);
    }
    
    for(int i=0;i<=NA-NF;i++){
        printf("%d\n",ans[i]);
    }

    // ---- free memory ----
    free(ans);
    free(FF);
    free(F);
    free(A);
    // ---- end free ----
    return 0;
}