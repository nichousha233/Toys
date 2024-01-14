#include "stdio.h"
#include "stdlib.h"
#include "math.h"

//#define DEBUG

void *malloc_zhang(size_t size, float* memory_bytes, char* filename, unsigned int line_number) {
    void* ptr;
    ptr = (void *) malloc(size);
    if (memory_bytes != NULL) {
        *memory_bytes += (float) size;
    }
    if (ptr == NULL) {
        #ifdef DEBUG
        printf("ERROR: malloc fault in %s, line %u\n", filename, line_number);
        #endif
        abort();
    }
    return ptr;
}

void *calloc_zhang(size_t nitems, size_t size, float* memory_bytes, char* filename, unsigned int line_number) {
    void* ptr;
    ptr = (void *) calloc(nitems, size);
    if (memory_bytes != NULL) {
        *memory_bytes += (float) nitems * size;
    }
    if (ptr == NULL) {
        #ifdef DEBUG
        printf("ERROR: calloc fault in %s, line %u\n", filename, line_number);
        #endif
        abort();
    }
    return ptr;
}

void free_zhang(void *ptr, size_t size, float* memory_bytes){
    free(ptr);
    if (memory_bytes != NULL) {
        *memory_bytes -= (float) size;
    }
}

int main(int argc, char* argv[]) {


    double * d;
    int * ii;
    int N = 3;
    float count1 = 0.0;
    float count2 = 0.0;
    // d = malloc(N*sizeof(*d)); 
    // ii = malloc(N*sizeof(*ii)); 
    d = malloc_zhang(N*sizeof(*d), &count1, __FILE__, __LINE__);
    ii = malloc_zhang(N*sizeof(*ii), &count2, __FILE__, __LINE__);
    // d = malloc_zhang(N*sizeof(*d), NULL, __FILE__, __LINE__);
    // ii = malloc_zhang(N*sizeof(*ii), NULL, __FILE__, __LINE__);
    // d = calloc_zhang(N, sizeof(*d), &count1, __FILE__, __LINE__);
    // ii = calloc_zhang(N, sizeof(*ii), &count2, __FILE__, __LINE__);
    // d = calloc_zhang(N, sizeof(*d), NULL, __FILE__, __LINE__);
    // ii = calloc_zhang(N, sizeof(*ii), NULL, __FILE__, __LINE__);
    // d = calloc(N, sizeof(*d));
    // ii = calloc(N, sizeof(*ii));
    for (int i = 0; i < N; i++){
        d[i] = i;
        ii[i] = i;
    }
    for (int i = 0; i < N; i++){
        printf("d[%d] = %f, ii[%d] = %d\n", i, d[i], i, ii[i]);
    }
    free_zhang(d, N*sizeof(*d), &count1);
    free_zhang(ii, N*sizeof(*ii), &count2);
    // free(d);
    // free(ii);
    printf("count1 = %f, count2 = %f\n", count1, count2);

    return 0;
}