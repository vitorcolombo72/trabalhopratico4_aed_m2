void quicksort( int *valores , int *unicos , int start , int end) {
    int i,j,pivot,temp,temp2;
    i = start;
    j = end-1;
    pivot = valores[ ( start + end ) / 2 ];
      while( i <= j ) {
        while( valores[i] > pivot && i < end ) {
          i++;
        }
        while (valores[j] < pivot && j > start ) {
          j--;
        }
        if( i <= j ) {
          temp = valores[i];
          valores[i] = valores[j];
          valores[j] = temp;

          temp2 = unicos[i];
          unicos[i] = unicos[j];
          unicos[j] = temp2;
          i++;
          j--;
        } 
      }
      if( j > start )
        quicksort(valores,unicos,start,j+1);
      if( i < end )
        quicksort(valores,unicos,i,end);
}

int* uniqueElements( int *nums, int numsSize, int *count ) {
  int *retorno = NULL;
  int c = 0,i,j;
  for( i = 0 ; i  < numsSize ; i++ ) {
    for( j = 0 ; j < i ; j++ ) {
      if( nums[i] == nums[j] ) {
        break;
       }
     }
       if( i  ==  j ) {
         retorno = realloc( retorno,(i+1) * sizeof(int) );
         retorno[c] = nums[i];
         c++;
       }      
    }
    *count = c;
    return retorno;
  }

int* topKFrequent( int* nums , int numsSize , int k , int *returnSize ){
      int count;     
      *returnSize = k;      
      int *unicos = uniqueElements(nums,numsSize,&count);   
      int *valores = malloc(count * sizeof(int));
      int *valoresK = malloc(k * sizeof(int));
      int i = 0, c = 0, min, aux;
      while ( i < count )
      {
        for( int j = 0 ; j <numsSize ; j++ ) {
          if( nums[j] == unicos[i] ) {
            c++;
            }
          }
          valores[i] = c;
          c = 0;
          i++;
      }
      /*
      for(i = 0; i < numsSize-1;i++){
        min = i;
          for(int j = i+1; j < numsSize;j++){
            if(valores[j] > valores[min]){
              min = j;
            }
          }
          if(i != min) {
            aux = valores[i];
            valores[i] = valores[min];
            valores[min] = aux;

            aux = unicos[i];
            unicos[i] = unicos[min];
            unicos[min] = aux;
          }
      }
      */
      quicksort(valores,unicos,0,count);
      for( i = 0 ; i < k ; i++ ) {
        valoresK[i] = unicos[i];  
      }
      
      return valoresK;
      
}
