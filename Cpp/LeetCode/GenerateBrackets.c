/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char **arr, *elem, **arr_tmp, *elem_tmp;
int i, N, elem_size;

void looper(int l, int r, int* returnSize) {
    if(r==N) {
        arr_tmp = arr;
        arr = malloc(((*returnSize)+1)*sizeof(char*));
        for(i=0; i<*returnSize; i++) arr[i] = arr_tmp[i];
        elem = malloc(elem_size+1);
        for(i=0; i<elem_size; i++) elem[i] = elem_tmp[i];
        elem[i] = 0;
        arr[(*returnSize)++] = elem;
        return;
    }
    if(l==r || (l>r && l<N)) {
        elem_tmp[l+r] = '(';
        looper(l+1, r, returnSize);
    }
    if(l>r) {
        elem_tmp[l+r] = ')';
        looper(l, r+1, returnSize);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    N = n;
    elem_size = N*2;
    *returnSize = 0; 
    arr = 0;
    elem_tmp = malloc(elem_size);
    looper(0, 0, returnSize);
    return arr;
}

main(){
    int n, *returnSize = &n;
    generateParenthesis(4, returnSize);
}