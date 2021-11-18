/* argv 에 숫자를 입력받아 배열에 저장, 단 중복 값 입력시 삭제 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRSIZE 8

int compare(const void *a, const void *b);
void print_arr(int *arr, int size);

int main(int argc, char**argv)
{
	int arr[ARRSIZE], *buf;
	int *found, target=0, cnt=0;
	//arr 초기화
	memset(arr,-1,sizeof(arr));

	if(argc == 1){
		perror("input error");
		exit(1);
	}
	for(int i=1; i<argc; i++){
		//현재 삽입하고자 하는 값
		target = atoi(argv[i]);
		//중복 없으면 삽입
		if((found=(int *)bsearch(&target, arr, cnt, sizeof(int),compare))==NULL){
			arr[ARRSIZE-1]=target;
			cnt++;
		}
		//중복이면 삭제
		else{
			*found = -1;
			memmove(found, found+1, cnt*sizeof(int));
			printf("del: ");
			print_arr(arr,cnt);
			cnt--;
			continue;
		}
		//삽입된 값만 buf를 이용해 qsort
		if((buf=(int *)calloc(cnt, sizeof(int)))==NULL){
			perror("buf calloc error");
			exit(1);
		}
		buf[0] = arr[ARRSIZE-1];
		arr[ARRSIZE-1]=-1;
		for(int j=1; j<cnt; j++){
			buf[j]=arr[j-1];
		}
		qsort(buf, cnt, sizeof(int), compare);
		memmove(arr, buf, cnt*sizeof(int));
		print_arr(arr,cnt+1);

		free(buf);
	}
	printf("result: ");
	print_arr(arr, ARRSIZE);
}
int compare(const void *a, const void *b)
{
	int n1= *(int *)a;
	int n2= *(int *)b;

	if(n1<n2) return -1;
	if(n1>n2) return 1;

	return 0;
}
void print_arr(int *arr, int size)
{
	for(int j=0; j<size; j++){
		printf("%d ", arr[j]);
	}
	printf("\n");
}


