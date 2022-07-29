#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//函数的定义

//对联系人动态分配内存空间
void Init_contact(struct contact* pc)
{
	pc->Man = (struct PeoInfo*)malloc(sizeof(struct PeoInfo) * Init_SZ);
	if (pc->Man)
	{
		pc->Capacity = Init_SZ;
		pc->Size = 0;
		Load_Info(&con);
		printf("初始化成功\n");
	}
	else
	{
		printf("%s\n", strerror(errno));
		return ;
	}
}

//将文件内的数据加载到内存
void Load_Info(struct contact* pc)
{
	struct PeoInfo S={0};
	FILE* pfread = fopen("contact.txt", "rb");
	if (!pfread)
	{
		printf("Load_Info::%s\n", strerror(errno));
		return;
	}
	//读取文件，存储到通讯录
	while (fread(&S, sizeof(struct PeoInfo), 1, pfread))
	{
		check_capacity(pc);
		pc->Man[pc->Size] = S;
		pc->Size++;
	}
	fclose(pfread);
	pfread = NULL;
}


//对内存进行检测扩容
//返回0，不需要扩容；返回1，扩容成功；返回-1，扩容失败
 int check_capacity(struct contact* pc)
{
	if (pc->Size == pc->Capacity)
	{
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(pc->Man,
			(pc->Capacity *2 ) * sizeof(struct PeoInfo));
		if (ptr)
		{
			pc->Man = ptr;
			pc->Capacity *= 2;
			return 1;
		}
		else
		{
			printf("扩容失败\n");
			return -1;
		}
	}
	else
		return 0;
}

//对联系人的姓名进行遍历，如果找到了返回下标，找不到返回-1
static int Find(const struct contact* pc,const char name[])
{
	int i = 0;
	for (i = 0; i < pc->Size; i++)
	{
		if (strcmp(pc->Man[i].name, name) == 0)
			return i;
	}
	return -1;
}

//添加联系人信息
void Add(struct contact* pc)
{
	int ret=check_capacity(pc);
	if (ret == 1||ret==0)
	{
		char name[MAX_Name];
		printf("请输入>\n");
		printf("姓名:");
		scanf("%s", name);
		int pos = Find(pc, name);
		if (pos == -1)
		{
			printf("性别:");
			scanf("%s", pc->Man[pc->Size].sex);
			printf("年龄:");
			scanf("%d", &pc->Man[pc->Size].age);
			printf("电话:");
			scanf("%s", pc->Man[pc->Size].num);
			printf("地址:");
			scanf("%s", pc->Man[pc->Size].adress);
			strcpy(pc->Man[pc->Size].name, name);
			pc->Size++;
			system("cls");
			printf("添加成功\n");
			system("pause");
			system("cls");
		}
		else
		{
			printf("该联系人已存在\n");
			system("pause");
			system("cls");
			return;
		}
	}
}

//删除联系人信息
void Del(struct contact* pc)
{
	char name[MAX_Name];
	printf("请输入>");
	printf("姓名:");
	scanf("%s", &name);
	int pos=Find(pc, name);
	if (pos == -1)
	{
		printf("没有该联系人\n");
		system("pause");
		system("cls");
	}
	else
	{
		pc->Man[pos] = pc->Man[pc->Size - 1];
		pc->Size--;
		printf("删除成功\n");
		system("pause");
		system("cls");
	}
}

//查找联系人
void Search(const struct contact* pc)
{
	char name[MAX_Name];
	printf("请输入>\n");
	printf("姓名:");
	scanf("%s", name);
	int pos=Find(pc, name);
	if (pos == -1)
	{
		printf("没有该联系人\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("该联系人信息如下>\n");
		printf("%-20s%-10s%-10s%-15s%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%-20s%-10s%-10d%-15s%-20s\n",
			pc->Man[pos].name,
			pc->Man[pos].sex,
			pc->Man[pos].age,
			pc->Man[pos].num,
			pc->Man[pos].adress);
		system("pause");
		system("cls");
	}
}

//更改联系人信息
void Modif(struct contact* pc)
{
	char name[MAX_Name];
	printf("请输入>\n");
	printf("姓名:");
	scanf("%s", &name);
	int pos=Find(pc, name);
	if (pos == -1)
	{
		printf("没有该联系人\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("请输入更改信息>\n");
		printf("姓名:");
		scanf("%s", pc->Man[pos].name);
		printf("性别:");
		scanf("%s", pc->Man[pos].sex);
		printf("年龄:");
		scanf("%d", &pc->Man[pos].age);
		printf("电话:");
		scanf("%s", pc->Man[pos].num);
		printf("地址:");
		scanf("%s", pc->Man[pos].adress);
		printf("更改成功\n");
		system("pause");
		system("cls");
	}

}

//qsort调用函数,通过姓名进行排序
static int Cmp_by_name(const void* e1, const void* e2)
{
	return ((struct contact*)e1)->Man->name > ((struct contact*)e2)->Man->name ? 1 : -1;
}

//对所有联系人按姓名进行排序
void Sort(struct contact* pc)
{
	qsort(pc->Man, pc->Size, sizeof(struct PeoInfo), Cmp_by_name);
	printf("成功对所有联系人进行排序\n");
	system("pause");
	system("cls");
}

//对所有联系人进行展示
void Display(const struct contact* pc)
{
	int i = 0;
	printf("%-20s%-10s%-10s%-15s%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (i = 0; i < pc->Size; i++)
	{
		printf("%-20s%-10s%-10d%-15s%-20s\n",
			pc->Man[i].name,
			pc->Man[i].sex,
			pc->Man[i].age,
			pc->Man[i].num,
			pc->Man[i].adress);
	}
	system("pause");
	system("cls");
}

//销毁所有联系人
void Destory(struct contact* pc)
{
	free(pc->Man);
	pc->Man = NULL;
}

void Save(struct contact* pc)
{
	FILE* pfwrite = fopen("contact.txt", "wb");
	if (!pfwrite)
	{
		printf("Save::%s\n", strerror(errno));
		return;
	}
	//写通讯录中的数据到文件
	int i = 0;
	for (i = 0; i < pc->Size; i++)
	{
		fwrite(&(pc->Man[i]), sizeof(struct PeoInfo), 1, pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
	printf("保存成功\n");
	system("pause");
	system("cls");
}

void Clear_list(struct contact* pc)
{
	free(pc->Man);
	pc->Man = NULL;
	pc->Man = (struct PeoInfo*)malloc(sizeof(struct PeoInfo) * Init_SZ);
	if (!pc->Man)
	{
		return;
	}
	pc->Size = 0;
	pc->Capacity = Init_SZ;
	printf("已完成清空\n");
	system("pause");
	system("cls");
}
