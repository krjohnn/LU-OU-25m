#define OPENSSL_SUPPRESS_DEPRECATED

#include <string>
#include <iostream>

#include <mpi.h>
#include <stdio.h>
#include <openssl/md5.h>
#include <iomanip>
#include <fstream>
using namespace std;

// Function to print the MD5 hash in hexadecimal format
void print_MD5(unsigned char *md, long size = MD5_DIGEST_LENGTH){
    for (int i = 0; i < size; i++){
        cout << hex << setw(2) << setfill('0') << (int)md[i];
    }
    cout << endl;
}

// Function to compute and print MD5 hash of a given string
void computeMD5FromString(const string &str){
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5((unsigned char *)str.c_str(), str.length(), result);

    cout << "MD5 of '" << str << "' : ";
    print_MD5(result);
}

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    computeMD5FromString("aaaaab");

    // Print off a hello world message
    printf("Hello world from processor %s, rank %d out of %d processors\n",
           processor_name, world_rank, world_size);

    // Finalize the MPI environment.
    MPI_Finalize();
}
