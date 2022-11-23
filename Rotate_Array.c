void reverse(int* temparray, int start,int end)
{
    int temp;
    int i;
    while(start<end)
    {
        temp = temparray[start];
        temparray[start] = temparray[end];
        temparray[end] = temp;
        end--;
        start++;
    }
    return temparray;
}
void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    reverse(nums,0,numsSize-1);
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);
    
}