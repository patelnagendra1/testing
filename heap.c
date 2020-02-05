#include<time.h>
#include<stdlib.h> 
#include<stdio.h> 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        // swap(arr[i], arr[largest]); 
        int temp =arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        int temp =arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
  

// Implement Iterative Merge Sort
int main(int argc,char *argv[])
{
  
  clock_t t;
  t = clock();
  int c;
  FILE *ptr;
  ptr=fopen(argv[1],"r");
  if (ptr == NULL) 
    { 
        printf("Cannot open file \n"); 
         
    } 
   
    int count=0;
    //FILE *p;
     //p = fopen("aa.txt", "w"); 

    while (!feof(ptr)) 
    { 
        
        fscanf(ptr,"%d",&c); 
       
          count++;
        
    }
      printf("%d\n",count ); 
  int a[count];
  int i=0;
  fclose(ptr);
    ptr=fopen(argv[1],"r");
  while (!feof(ptr)) 
    { 
        
        fscanf(ptr,"%d",&c); 
       //printf("%d\n", c);
          a[i]=c;
          i++;
        
    } 
  int n = sizeof(a) / sizeof(a[0]); 

  heapSort(a,n); 
  //printArray(a, n); 
  
t = clock() - t; 
    printf("No. of clicks %ld clicks (%f seconds).\n", 
           t, ((float)t) / CLOCKS_PER_SEC); 
    FILE *infptr,*p,*q;
  
   infptr = fopen(argv[2], "w");
  
   for(int i = 0; i<n; i++) 
  {
        int num=a[i];
        //printf("%d ",num);
       fprintf(infptr,"%d ",num);

  }
  fclose(infptr);
  return 0; 
}
