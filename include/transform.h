#ifndef TRANSFORM_H
#define TRANSFORM_H

#define DATA_SIZE 100
#define NUM_PROCESSES 5
#define CHUNK_SIZE (DATA_SIZE / NUM_PROCESSES)

void transform(int *data, int size);

void print_array(const char *label, const int *data, int size);

#endif
