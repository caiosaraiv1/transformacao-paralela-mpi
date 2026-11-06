#include <stdio.h>
#include "transform.h"

void transform(int *data, int size)
{
      for (int i = 0; i < size; i++)
            data[i] = data[i] * data[i];
}

void print_array(const char *label, const int *data, int size)
{
      printf("[Processo 0] %s: [", label);
      for (int i = 0; i < size; i++)
      {
            printf("%d", data[i]);
            if (i < size - 1)
                  printf(", ");
      }
      printf("]\n");
}
