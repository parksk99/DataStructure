#include"header.h"
#include"arrayUtil.h"

void Permutation(char *a, int x, int y){
	if(x==y){
		for(int i=0; i<y; i++) std::cout<<a[i]<<" ";
		std::cout<<std::endl;
	}
	else{
		for(int i=x; i<y; i++){
			swap(a+x, a+i);
			Permutation(a,x+1, y);
			swap(a+x, a+i);
		}
	}
	return;
}
