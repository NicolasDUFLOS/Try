typedef struct ctx_s{
    void *esp;
    void *ebp;
}

typedef int (func_t)(int); /* A function that returns an int from an int */
int try(struct ctx_s *pctx, func_t*f, int arg); /* execute funtion f with argument arg and register current state in pctx */
int throw(struct ctx_s *pctx, int r);