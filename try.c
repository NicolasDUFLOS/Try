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
    asm ("movl %%esp, %0" "\n\t" "movl %%ebp, %0"
            : "=r"(pctx->esp)
            , "=r"(pctx->ebp)
        );
    return f(arg);
}

int
throw
(struct ctx_s *pctx, int r)
{
    asm ("movl %1, %%esp" "\n\t" "movl %1, %%ebp"
            :
            : "r" (pctx->esp)
            , "r" (pctx->ebp)
    );
    return r;
}