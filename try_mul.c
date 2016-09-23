#include <stdio.h>
#include "try.h"

static struct ctx_s *pctx;

static int
mul()
{
    int i;

    switch (scanf("%d", &i)) {
        case EOF :
            return 1; /* neutral element */
        case 0 :
            return mul(); /* erroneous read */
        case 1 :
            if (i){ 
                printf("Coucou");
                return i * mul();
            }
            else{
                printf("GET BACK!");
                throw(&pctx, 0);
            }
    }
}

int
main(int argc, char *argv[])
{
    int product;

    printf("A list of int, please\n"); 
    product = try(&pctx, mul, 0);
    printf("product = %d\n", product); 
    return 0;
}