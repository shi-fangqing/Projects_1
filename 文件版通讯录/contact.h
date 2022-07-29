#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#define Init_SZ 3
enum Info
{
	MAX_Name=20,
	MAX_Sex=5,
	MAX_Num=15,
	MAX_Adress=30
};
//联系人的基本信息的结构体
struct PeoInfo
{
	char name[MAX_Name];
	char sex[MAX_Sex];
	int age;
	char num[MAX_Num];
	char adress[MAX_Adress];
};
//通讯录的结构体
struct contact
{
	struct PeoInfo* Man; //最大能够容纳的联系人数量
	int Size;   //当前的联系人个数
	int Capacity;//当前通讯录的最大容量
};

//创建一个通讯录
struct contact con;

enum operation
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIF,
	SORT,
	DISPLAY,
	SAVE,
	CLEAR
};
//函数声明

//通讯录初始化
void Init_contact(struct contact* pc);

//添加联系人
void Add(struct contact* pc);

//删除联系人
void Del(struct contact* pc);

// 查询联系人信息
void Search(const struct contact* pc);

//修改联系人信息
void Modif(struct contact* pc);

// 对联系人进行排序
void Sort(struct contact* pc);

//展示联系人目录
void Display(const struct contact* pc);

//退出、销毁所有联系人
void Destory(struct contact* pc);

//对数据进行保存
void Save(struct contact* pc);

//检查内存空间是否足够
int check_capacity(struct contact* pc);

//将文件中的信息加载到内存
void Load_Info(struct contact* pc);

void Clear_list(struct contact* pc);


