#include "stdio.h"
#include "stdlib.h"

#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

//#define DEBUG

void *malloc_zhang(size_t size, float* pmemory_bytes, float* pmemory_bytes_max, char* filename, unsigned int line_number) {
    void* ptr;
    ptr = (void *) malloc(size);
    if (ptr == NULL) {
        #ifdef DEBUG
        printf("ERROR: malloc fault in %s, line %u\n", filename, line_number);
        #endif
        abort();
    }
    if (pmemory_bytes != NULL) {
        *pmemory_bytes += (float) size;
    }
    if (pmemory_bytes_max != NULL) {
        *pmemory_bytes_max = max(*pmemory_bytes_max, *pmemory_bytes);
    }
    return ptr;
}

void *calloc_zhang(size_t nitems, size_t size, float* pmemory_bytes, float* pmemory_bytes_max, char* filename, unsigned int line_number) {
    void* ptr;
    ptr = (void *) calloc(nitems, size);
    if (ptr == NULL) {
        #ifdef DEBUG
        printf("ERROR: calloc fault in %s, line %u\n", filename, line_number);
        #endif
        abort();
    }
    if (pmemory_bytes != NULL) {
        *pmemory_bytes += (float) nitems * size;
    }
    if (pmemory_bytes_max != NULL) {
        *pmemory_bytes_max = max(*pmemory_bytes_max, *pmemory_bytes);
    }
    return ptr;
}

void free_zhang(void *ptr, size_t size, float* pmemory_bytes){
    free(ptr);
    if (pmemory_bytes != NULL) {
        *pmemory_bytes -= (float) size;
    }
}

int main(int argc, char* argv[]) {

    double * d;
    int * ii;
    int N = 3;

    float memory_bytes = 0.0;
    float memory_bytes_max = 0.0;

    // d = malloc(N*sizeof(*d)); 
    // ii = malloc(N*sizeof(*ii)); 

    // d = malloc_zhang(N*sizeof(*d), &memory_bytes, &memory_bytes_max, __FILE__, __LINE__);
    // printf("memory_bytes = %f, memory_bytes_max = %f\n", memory_bytes, memory_bytes_max);
    // ii = malloc_zhang(N*sizeof(*ii), &memory_bytes, &memory_bytes_max, __FILE__, __LINE__);
    // printf("memory_bytes = %f, memory_bytes_max = %f\n", memory_bytes, memory_bytes_max);

    d = calloc_zhang(N, sizeof(*d), &memory_bytes, &memory_bytes_max, __FILE__, __LINE__);
    printf("memory_bytes = %f, memory_bytes_max = %f\n", memory_bytes, memory_bytes_max);
    ii = calloc_zhang(N, sizeof(*ii), &memory_bytes, &memory_bytes_max, __FILE__, __LINE__);
    printf("memory_bytes = %f, memory_bytes_max = %f\n", memory_bytes, memory_bytes_max);

    for (int i = 0; i < N; i++){
        d[i] = i;
        ii[i] = i;
    }
    for (int i = 0; i < N; i++){
        printf("d[%d] = %f, ii[%d] = %d\n", i, d[i], i, ii[i]);
    }

    printf("memory_bytes = %f, memory_bytes_max = %f\n", memory_bytes, memory_bytes_max);
    
    free_zhang(d, N*sizeof(*d), &memory_bytes);

    printf("memory_bytes = %f, memory_bytes_max = %f\n", memory_bytes, memory_bytes_max);

    free_zhang(ii, N*sizeof(*ii), &memory_bytes);

    // free(d);
    // free(ii);

    printf("memory_bytes = %f, memory_bytes_max = %f\n", memory_bytes, memory_bytes_max);

    return 0;
}