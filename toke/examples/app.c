#include "./toke.h"

int main(int argc, char **argv)
{
  Node* h = tokenize("Test,example,string",',');
  int count = size_of(h);
  printf("Head address is %p\n", h);
  printf("Elements: \n");
  for (int i=0;i<count;i++) {
    printf("%s\n", h->token);
    h = h->next;
  }
    return 0;
}
