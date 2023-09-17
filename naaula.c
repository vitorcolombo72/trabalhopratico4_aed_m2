#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* uniqueElements(int nums[],int numsSize){
  int *retorno = malloc(numsSize * sizeof(int));
  int c = 0,i,j;
  for(i = 0; i  < numsSize; i++){
    for(j = 0; j < i; j++){
      if(nums[i] == nums[j]){
        break;
       }
     }
       if(i  ==  j){
         retorno[c] = nums[i];
         c++;
        //printf("%d",nums[i]); 
       }
      
    }
    return retorno;
  }

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
      int *unicos = uniqueElements(nums,numsSize);
      int *valores = malloc(numsSize * sizeof(int));
      int *valoresK = malloc ( k * sizeof(int));
      int i = 0, c = 0;
      while (unicos[i] != 0)
      {
        for(int j = 0; j <numsSize;j++){
          if(nums[j] == unicos[i]){
            c++;
            }
          }
          valores[i] = c;
          c = 0;
          i++;
      }
      for(int i = 0;i< numsSize;i++){
        
        }
      return valores;
}
int main(){
   int k = 2;
   int nums[6] = {1,1,1,2,2,3};
   int *retorno = topKFrequent(nums,6,k,0);
   printf("%d",retorno[3]);
  return 0;
}
