#include <stdio.h>
#include <stdlib.h>

void qsorte(int a[],int left ,int right){
	if(left>right) return;
	int p=a[(left+right)/2];
	int i=left;
	int j=right;
	while(i<=j){
		while (a[i]<p)i++;
		while (a[j]>p)j--;
		if(i<=j){
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
			i++;
			j--;
		}
	}	
	  qsorte(a,left,j);
	  qsorte(a,i,right);
}
int main(){
	
	int n;
	printf("Введите размер массива:  ");
	scanf("%d",&n);
	int a[n];
	int g;
	printf("Введите массив\n");
	  for (int i = 0; i < n; i++) {
		  scanf("%d",&g);
        a[i] = g;
    }
    printf("исходный массив\n");
	  for (int i = 0; i < n; i++) {
		  printf("%d  ",a[i]);
    }
  qsorte(a,0,n-1);
  printf("\n");
  printf("Отсортированный массив\n");
  	  for (int i = 0; i < n; i++) {
		  printf("%d  ",a[i]);
    }


}
