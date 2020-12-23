#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int atgc, char **argv)
{
  char *run_dir = (char *)malloc(1024);
  if (getcwd(run_dir, 1024) != NULL)
  {
    fprintf(stdout, "Current working dir: %s\n", run_dir);
  }
  return 0;
}