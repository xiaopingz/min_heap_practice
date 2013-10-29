/* 关于拷贝构造函数和操作符重载*/
#if 0
#include<iostream>
using namespace std;

class CExample   
{  
private:  
 int a;  
  
public:  
 //构造函数  
 CExample(int b)  
 {   
  a = b;  
  cout<<"creat: "<<a<<endl;  
 }  
  
 //拷贝构造  
 CExample(const CExample& C)  
 {  
  a = C.a;  
  cout<<"copy"<<endl;  
 }  
   
 //析构函数  
 ~CExample()  
 {  
  cout<< "delete: "<<a<<endl;  
 }  
  
     void Show ()  
 {  
         cout<<a<<endl;  
     }  
};  
  
//全局函数，传入的是对象  
void g_Fun(CExample C)  
{  
 cout<<"test"<<endl;  
}  
  
CExample g_Fun2()
{
	CExample test(0);
	cout<<"test 0 ";
	return test;
}

int main()  
{  
 CExample test(1);  
 //传入对象  
 g_Fun(test);  
 g_Fun2();
  
 return 0;  
}  

#endif