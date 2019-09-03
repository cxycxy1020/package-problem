#include <iostream>
using namespace std;

int max(int, int);
int value_max(int, int,int[20],int[20]);

int main()
{
	int weight[20] = { 92 ,4 ,43 ,83 ,84 ,68 ,92 ,82 ,6 ,44 ,32 ,18 ,56 ,83 ,25 ,96 ,70 ,48 ,14 ,58 };
	int value[20] = { 44 ,46 ,90 ,72 ,91, 40 ,75 ,35 ,8 ,54 ,78 ,40 ,77 ,15 ,61 ,17 ,75 ,29 ,75 ,63 };
	cout<<"价值最大值是:"<<value_max(20, 878,weight,value);
	return 0;
}
int max(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}

int value_max(int i, int w,int weight[20],int value[20])
{
	if (i == 0 || w <= weight[i-1]) return 0;
	int value_put = value_max(i - 1, w - weight[i - 1], weight, value)+value[i-1];
	int value_nput = value_max(i - 1, w, weight, value);
	return max(value_put, value_nput);
}