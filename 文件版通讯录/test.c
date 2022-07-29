#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("***********最大容量:%d*******\n",con.Capacity);
	printf("***********当前已用:%d*******\n",con.Size);
	printf("*****************************\n");
	printf("****1.Add     2.Del     *****\n");
	printf("****3.Search  4.Modif   *****\n");
	printf("****5.Sort    6.Display *****\n");
	printf("****7.Save    8.Clear  ******\n");
	printf("****          0.Exit    *****\n");
	printf("*****************************\n");
}
int main()
{
	int input = 0;
	
	//初始化通讯录
	Init_contact(&con);
	do
	{
		menu();
		printf("请选择>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case ADD:
			Add(&con);
			break;
		case DEL:
			Del(&con);
			break;
		case SEARCH:
			Search(&con);
			break;
		case MODIF:
			Modif(&con);
			break;
		case SORT:
			Sort(&con);
			break;
		case DISPLAY:
			Display(&con);
			break;
		case SAVE:
			Save(&con);
			break;
		case CLEAR:
			Clear_list(&con);
			break;
		case EXIT:
			Save(&con);
			Destory(&con);
			break;
		default:printf("选择错误\n");
			system("pause");
			system("cls");
		}
	} while (input);
	
	return 0;
}
