long long sum(int *a, int n){
    int i; 
    long long int result = 0;
    
    for (i = 0; i < n; i++){
        result += a[i];
    }
    return result;
}