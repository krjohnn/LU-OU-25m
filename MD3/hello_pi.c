#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20000000000LL   // 2e9 samples (adjust to get ~10s on 1 core)

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    long long local_N = N / size;   // block distribution
    long long i, local_count = 0, global_count = 0;

    // unique seed per rank
    unsigned int seed = (unsigned int) time(NULL) + rank * 1234567;

    MPI_Barrier(MPI_COMM_WORLD);
    double start = MPI_Wtime();

    for (i = 0; i < local_N; i++) {
        double x = rand_r(&seed) / (double) RAND_MAX;
        double y = rand_r(&seed) / (double) RAND_MAX;
        if (x*x + y*y <= 1.0)
            local_count++;
    }

    MPI_Reduce(&local_count, &global_count, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);
    double end = MPI_Wtime();

    if (rank == 0) {
        double pi = 4.0 * (double)global_count / (double)N;
        printf("Processes: %d\n", size);
        printf("Time: %.4f seconds\n", end - start);
        printf("PI ≈ %.6f\n", pi);
    }

    MPI_Finalize();
    return 0;
}
