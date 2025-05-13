#include<stdio.h>
#include<stdlib.h>//malloc的头文件 
#include<string.h>
/*malloc：申请的空间不会自动初始化*/ //memory(内存）allocate(分配）malloc 分配内存 
//malloc和free配合使用 
void testMalloc()
{
	int i;
	//int a[10];//10*sizeof(int) 10个整数类型的字节  
	//  sizeof获取数据在内存所占用的内存空间，用字节表示 
	int*p=malloc(10*sizeof(int));//10个字节的内存空间//  申请内存 
	if(!p)//!是其返回值为真的改变为假的（非0变为0） 
	{
		printf("内存申请失败！\n");
		return;
	 }
	 //内存设置
	 memset(p,0,10*sizeof(int));//memset初始化内存（特定值） 初始值为0,大小是个字节  
	//遍历
	for(i=0;i<10;i++)
	{
		*(p+i)=i*2;//赋值 
	printf("%-3d",*(p+i));
	 } 
	 //手动申请，必须手动释放，如果不释放，就会发生内存泄露 
	 free(p);//free手动释放 中间放指针 
	 p=NULL;//指针释放之后 把其置为空  NULL要大写 
	 //释放之后，就不能继续访问这块内存空间 
	 printf("\n");
}

//calloc申请的空间，会自动初始化为0 
void testCalloc()
{
	int i;
	int*p=calloc(10,sizeof(int));//数量10 ，大小 sizeof（int） 
	if(!p)
	{
	printf("内存分配失败！\n");
	return;	
	}
	for(i=0;i<10;i++)
	{
		*(p+i)=i*2;//赋值 
		printf("%-3d",*(p+i));	
	 } 
	 printf("\n");
	 //15个元素 
	/*int*pnew=calloc(15,sizeof(int));//用传统方法
	if(!p)
	{
	printf("内存分配失败！\n");
	return;	
	}
	memcpy(pnew,p,10*sizeof(int));//memcpy  从存储区 p 复制 10个字节到存储区 pnew。
	for(i=0;i<15;i++)
	{
		printf("%-3d",*(pnew+i));
	 } */
	 int*pnew=realloc(p,15*sizeof(int));
	 /*realloc 尝试重新调整之前调用 malloc 或 calloc 所分配的 p 所指向的内存块的大小
	 后放 原内存空间p的地址 加上更改原内存空间p的大小 */ 
	 if(!pnew)
	 {
	 	printf("内存分配失败！\n");
	 	return;
	 }
	 for(i=0;i<15;i++)
	 {
	 	if(i>=10)//赋值  如果后面的值大于等于10 则 后面的数 加上20 
	 	{
	 		*(pnew+i)=20+i;
		 }
	 	printf("%-3d",*(pnew+i));
	 }
 } 
int main(){
	
	 
	testMalloc();
	testCalloc();
	return 0;
}
