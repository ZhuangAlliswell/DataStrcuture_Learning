#include<stdio.h>
int N = 1000;
int M = 5;
int Heap[6];

void create_Heap();
void AdjustDown(int);

int main(){
 int i;
 int a[1000] = { 0 };
 srand((unsigned int)time(NULL));
 for (i = 0; i < N; i++){
 a[i] = rand() % 100;
 }
 a[60] = 600;
 a[54] = 870;
 a[76] = 345;
 a[576] = 745;
 a[876] = 698;

 for (i = 1; i <= M; i++){
 Heap[i] = a[i-1];
 }
 create_Heap();
 for ( i = M; i < N; i++){
 if (a[i]>Heap[1]){
 Heap[1] = a[i];
 AdjustDown(1);
 }

 }
 for (i = 1; i <= M; i++){
 printf("%d ",Heap[i]);
 }
 getchar();
 getchar();
}

void create_Heap(){
 int i;
 int pos = M / 2;
 for (i = pos; i >= 1; i--){
 AdjustDown(i);
 }
}

void AdjustDown(int i){
 int left, right, tmp, pos;
 left = 2 * i;
 right = 2 * i + 1;
 if (left > M)
 return;
 else{
 if (right > M)
 pos = left;
 else
 pos = Heap[left] > Heap[right] ? right : left;

 if (Heap[i] > Heap[pos])
 {
 tmp = Heap[i];
 Heap[i] = Heap[pos];
 Heap[pos] = tmp;
 AdjustDown(pos);
 }


 }
}