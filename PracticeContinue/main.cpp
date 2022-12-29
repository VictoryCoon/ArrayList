#include <iostream>
#include "Arrays.h"
using namespace std;

int main()
{
	Arrays<int> ar;
	int out;

	//Arrays<const char*> arc;
	Arrays<string> arc;

	ar.PushBack(2);			//0
	ar.PushBack(7);			//1
	ar.PushBack(9);			//2
	ar.PushBack(3);			//3
	ar.PushFront(3);		//4
	ar.PushFront(12);		//5
	ar.PushFront(47);		//6

	//placement new

	arc.PushBack("dkdkdkdkdkdk");
	arc.PushBack("sisisisisisi");
	arc.PushBack("dodododododo½Ã¹ß");

	arc.PrintAll();

	return 0;
}