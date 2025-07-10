#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000000

// Constant Array
#define SEQ_SIZE 4

const char SEQ[SEQ_SIZE][SEQ_SIZE] = {
    {'A', 'C', 'A', 'G'},
    {'C', 'G', 'T', 'A'},
    {'A', 'T', 'C', 'G'},
    {'G', 'A', 'G', 'T'}
};

int resolve(char c){
    switch(c){
        case 'A':
            return 0;
        case 'G':
            return 1;
        case 'C':
            return 2;
        case 'T':
            return 3;
    }

    return -1;
}

int main(){
    int N;
    char dna_seq[SIZE+1];

    // 1. 초기화 후 입력 처리
    memset(dna_seq, '\0', SIZE+1);
    scanf("%d", &N);
    scanf("%s", dna_seq);

    // 2. Processing
    for(int i = N-1; i > 0; i--){
        dna_seq[i-1] = SEQ[ resolve(dna_seq[i-1]) ][ resolve(dna_seq[i]) ];
        dna_seq[i]   = '\0';
    }

    // 3. Output
    printf("%c\n", dna_seq[0]);

    exit(EXIT_SUCCESS);
}