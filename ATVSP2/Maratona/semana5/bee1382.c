#include <stdio.h>

 
int main() {
 
    int t;
    scanf("%d",&t);

    for (int i = 0; i < t; i++){
        int n;
        scanf("%d",&n);

        int swaps = 0;

        int nums[10000],pos[10000],num;

        for(int i = 0; i < n; i++){
            scanf("%d",&num);
            nums[i] = num - 1;
            pos[nums[i]] = i;
        }

        for(int j = 0; j < n; j++){
            if(nums[j] != j){
                nums[pos[j]] = nums[j];
                pos[nums[j]] = pos[j];
                swaps += 1;
            }
        }

        printf("%d\n",swaps);
    }
    

    
    
 
    return 0;
}