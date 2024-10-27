#include<stdio.h>
#include<stdlib.h>
#include <omp.h>


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
    //printf("\n");
    int nowpos=0;
    int total_sum;
    int partial_sum;
    while(nowpos+NF<=NA){
        #pragma omp parallel private(partial_sum) shared(total_sum)
        {
            total_sum=0;
            partial_sum=0;
            for(int i=0;i<NF;i++){
                partial_sum+=A[nowpos+i]*F[NF-1-i];
            }

            #pragma omp critical
            {
                total_sum+=partial_sum;
            }
        }
        printf("%d\n",total_sum);
        nowpos++;
    }

    // ---- free memory ----
    free(F);
    free(A);
    // ---- end free ----
    return 0;
}