#include<stdio.h>
#include<stdlib.h>//malloc��ͷ�ļ� 
#include<string.h>
/*malloc������Ŀռ䲻���Զ���ʼ��*/ //memory(�ڴ棩allocate(���䣩malloc �����ڴ� 
//malloc��free���ʹ�� 
void testMalloc()
{
	int i;
	//int a[10];//10*sizeof(int) 10���������͵��ֽ�  
	//  sizeof��ȡ�������ڴ���ռ�õ��ڴ�ռ䣬���ֽڱ�ʾ 
	int*p=malloc(10*sizeof(int));//10���ֽڵ��ڴ�ռ�//  �����ڴ� 
	if(!p)//!���䷵��ֵΪ��ĸı�Ϊ�ٵģ���0��Ϊ0�� 
	{
		printf("�ڴ�����ʧ�ܣ�\n");
		return;
	 }
	 //�ڴ�����
	 memset(p,0,10*sizeof(int));//memset��ʼ���ڴ棨�ض�ֵ�� ��ʼֵΪ0,��С�Ǹ��ֽ�  
	//����
	for(i=0;i<10;i++)
	{
		*(p+i)=i*2;//��ֵ 
	printf("%-3d",*(p+i));
	 } 
	 //�ֶ����룬�����ֶ��ͷţ�������ͷţ��ͻᷢ���ڴ�й¶ 
	 free(p);//free�ֶ��ͷ� �м��ָ�� 
	 p=NULL;//ָ���ͷ�֮�� ������Ϊ��  NULLҪ��д 
	 //�ͷ�֮�󣬾Ͳ��ܼ�����������ڴ�ռ� 
	 printf("\n");
}

//calloc����Ŀռ䣬���Զ���ʼ��Ϊ0 
void testCalloc()
{
	int i;
	int*p=calloc(10,sizeof(int));//����10 ����С sizeof��int�� 
	if(!p)
	{
	printf("�ڴ����ʧ�ܣ�\n");
	return;	
	}
	for(i=0;i<10;i++)
	{
		*(p+i)=i*2;//��ֵ 
		printf("%-3d",*(p+i));	
	 } 
	 printf("\n");
	 //15��Ԫ�� 
	/*int*pnew=calloc(15,sizeof(int));//�ô�ͳ����
	if(!p)
	{
	printf("�ڴ����ʧ�ܣ�\n");
	return;	
	}
	memcpy(pnew,p,10*sizeof(int));//memcpy  �Ӵ洢�� p ���� 10���ֽڵ��洢�� pnew��
	for(i=0;i<15;i++)
	{
		printf("%-3d",*(pnew+i));
	 } */
	 int*pnew=realloc(p,15*sizeof(int));
	 /*realloc �������µ���֮ǰ���� malloc �� calloc ������� p ��ָ����ڴ��Ĵ�С
	 ��� ԭ�ڴ�ռ�p�ĵ�ַ ���ϸ���ԭ�ڴ�ռ�p�Ĵ�С */ 
	 if(!pnew)
	 {
	 	printf("�ڴ����ʧ�ܣ�\n");
	 	return;
	 }
	 for(i=0;i<15;i++)
	 {
	 	if(i>=10)//��ֵ  ��������ֵ���ڵ���10 �� ������� ����20 
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
