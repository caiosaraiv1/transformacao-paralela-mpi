#include <mpi.h>
#include "transform.h"

int main(int argc, char **argv)
{
      int rank;
      int original[DATA_SIZE];
      int transformed[DATA_SIZE];
      int local_chunk[CHUNK_SIZE];

      MPI_Init(&argc, &argv);
      MPI_Comm_rank(MPI_COMM_WORLD, &rank);

      if (rank == 0)
            for (int i = 0; i < DATA_SIZE; i++)
                  original[i] = i + 1;

      MPI_Scatter(original, CHUNK_SIZE, MPI_INT,
                  local_chunk, CHUNK_SIZE, MPI_INT,
                  0, MPI_COMM_WORLD);

      transform(local_chunk, CHUNK_SIZE);

      MPI_Gather(local_chunk, CHUNK_SIZE, MPI_INT,
                  transformed, CHUNK_SIZE, MPI_INT,
                  0, MPI_COMM_WORLD);

      if (rank == 0)
      {
            print_array("Vetor original", original, DATA_SIZE);
            print_array("Vetor transformado", transformed, DATA_SIZE);
      }

      MPI_Finalize();
      return 0;
}
