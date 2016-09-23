typedef struct ctx_s;
typedef int (funct_t)(int); /* A function that returns an int from an int */
int try(struct ctx_s *pctx, funct_t *f, int arg); /* execute funtion f with argument arg and register current state in pctx */
int throw(struct ctx_s *pctx, int r);