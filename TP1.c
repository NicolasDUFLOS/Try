//TP1 DUFLOS DYMENT
#include <stdio.h>
#include <setjmp.h>

int
print
(void)
{
  int x, y;
  asm ("movl %%ebp, %0" "\n\t" "movl %%esp, %0"

               : "=r"(x)  /* x is output operand */

               , "=r"(y)   /* y is output operand */
        );
  printf ("ebp : %d; esp : %d\n", x, y);
  printf ("adress x : %d\n", (int)&x);
  printf ("adress y : %d\n", (int)&y);
  return 0;
}

// Avec l'appel de lafonction récursif on remarque que le début de la pile ne change pas contrairement à la fin qui s'incrémente au fur et à mesure des appels.
int
print_rec
(int i){
  if (i == 0){
    print();
  }
  else{
    printf("%d", i);
    print_rec(--i);
    printf("adresse i : %d\n", (int)&i);
    print();
  }
  return 0;
}

// Avec les appels imbriqués les valeurs de début et de fin de pile ne changent pas.
int
print_imb
(void){
  int i;
  i = 0;
  printf("Appel 1 : ");
  print();
  printf("adresse i : %d\n", (int)&i);
  printf ("Appel 2 : ");
  print();
  return 0;
}


int main(int argc, char const *argv[]) {
  printf("Appels successifs :\n");
  print_rec(5);
  printf("\nAppels imbriqués :\n");
  print_imb();
  return 0;
}
