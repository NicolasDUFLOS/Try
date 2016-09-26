// try.c DUFLOS DYMENT

#include <stdio.h>
#include "try.h"

struct ctx_s{
    void *esp;
    void *ebp;
};

int
try
(struct ctx_s *pctx, funct_t *f, int arg)
{
<<<<<<< HEAD
    asm ("movl %%esp, %0" "\n\t" "movl %%ebp, %1"
            : "=r"(pctx->esp)
            , "=r"(pctx->ebp)
        );
=======
    asm ("movl %%esp, %0" : "=r"(pctx->esp));
    asm ("movl %%ebp, %0" : "=r"(pctx->ebp));
>>>>>>> c28c7f611066f4c8590f9edbad320b9bcec6d7b8
    return f(arg);
}

int
throw
(struct ctx_s *pctx, int r)
{
<<<<<<< HEAD
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
=======
    static int res;
    static struct ctx_s *spctx;
    res = r;
    spctx = pctx;
    asm ("movl %1, %%esp" "\n\t" "movl %1, %%ebp"
            :
            : "r"(spctx->esp)
            , "r"(spctx->ebp)
    );
    return res;
}
>>>>>>> c28c7f611066f4c8590f9edbad320b9bcec6d7b8
