#include<iostream>
#include<algorithm>
using namespace std;
void Permutation(char *a, const int m){
	do{
		copy(a, a+m, ostream_iterator<char>(cout," "));
		std::cout<<std::endl;
	}
	while(next_permutation(a, a+m));
}

int main(){
	char a[5] = "acbd";
	Permutation(a, 5);
	return 0;
}
