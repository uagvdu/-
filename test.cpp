#include"Array.h"
void test()
{
	ArrayStack<int>  as1;
	as1.Arr1_Push_Back(1);
	as1.Arr1_Push_Back(2);

	as1.Arr2_Push_Back(6);
	as1.Arr_DisPlay();  //整个数组两个栈
	as1.Arr1_DisPlay();//前栈

	as1.Arr2_Push_Back(5);
	as1.Arr2_Push_Back(4);
	as1.Arr2_DisPlay();//后栈

}

void test2()
{
	ArrayStack<int>  as1;
	as1.Arr1_Push_Back(1);
	as1.Arr1_Push_Back(2);
	as1.Arr2_Push_Back(6);

	as1.Arr1_Pop_Back();

	as1.Arr_DisPlay();  //整个数组两个栈
	as1.Arr1_DisPlay();

	as1.Arr2_Push_Back(5);
	as1.Arr2_Push_Back(4);

	as1.Arr2_Pop_Back();

	as1.Arr2_DisPlay();
	as1.Arr_DisPlay();  //整个数组两个栈
	cout << "---------------" << endl;
	ArrayStack <int> as2;
	as2 = as1;
	as2.Arr_DisPlay();
	as2.Arr2_DisPlay();
	as2.Arr1_DisPlay();

	cout << "------------------" << endl;
	ArrayStack <int> as3(as1);
	as3.Arr_DisPlay();
	as3.Arr2_DisPlay();
	as3.Arr1_DisPlay();
}
int main()
{
	test2();
	return 0;
}