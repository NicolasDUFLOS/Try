#include <stdio.h>
#include "try.h"

static int
mul(int depth)
{
    int i;
    static struct ctx_s *pctx;
    if (depth == 0){
        if ((try(pctx, mul, depth)))
            return 0;
    }

    switch (scanf("%d", &i)) {
        case EOF :
            return 1; /* neutral element */
        case 0 :
            return mul(depth+1); /* erroneous read */
        case 1 :
            if (i) 
                return i * mul(depth+1);
            else
                throw(pctx, ~0);
    }
}

int
main()
{
    int product;

    printf("A list of int, please\n"); 
    product = mul(0);
    printf("product = %d\n", product); 
    return 0;
}