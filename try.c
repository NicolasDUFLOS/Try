// try.c DUFLOS DYMENT

#include <stdio.h>
#include "try.h"

typedef struct ctx_s{
    void *esp;
    void *ebp;
};

int
try
(struct ctx_s *pctx, funct_t *f, int arg)
{
    asm ("movl %%esp, %0" "\n\t" "movl %%ebp, %1"
            : "=r"(pctx->esp)
            , "=r"(pctx->ebp)
        );
    return f(arg);
}

int
throw
(struct ctx_s *pctx, int r)
{
    static struct ctx_s *spctx;
    static int res;

    res = r;
    asm ("movl %0, %%esp" "\n\t" "movl %1, %%ebp"
            :
            : "r" (spctx->esp)
            , "r" (spctx->ebp)
    );
    return res;
}
