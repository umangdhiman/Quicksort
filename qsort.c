#include<stdio.h>
void swap(int *x,int *y){
   int t;
   t=*x;
   *x=*y;
   *y=t;
}
int partition(int arr[],int lb,int ub){
   int a,up,down;
   a=arr[lb];
   up=ub;
   down=lb;
   while(down<up){
       while(arr[down]<=a)
           down++;
       while(arr[up]>a)
           up--;
       if(up>down)
           swap(&arr[up],&arr[down]);
   }
   swap(&arr[lb],&arr[up]);
   return up;
}
void quick_sort(int arr[],int lb,int ub){
   int pj;
   if(lb<ub){
       pj=partition(arr,lb,ub);
       quick_sort(arr,lb,pj-1);
       quick_sort(arr,pj+1,ub);
   }
}
int main(){
   int n,i,arr[50],lb,ub,j;
   lb=0;
   i=0;
   printf("How many nos\n");
   scanf("%d",&n);
   ub=n-1;
   while(n>i){
       printf("Enter no.");
       scanf("%d", &arr[i]);
       i++;
   }
   quick_sort(arr,lb,ub);
   printf("Sorted list\n");
   for(j=0;n>j;j++){
       printf("%d\t",arr[j]);
   }
   return 0;
}

