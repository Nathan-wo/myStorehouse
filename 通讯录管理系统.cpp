#include <iostream>
#include <string>
#define MAX 4
using namespace std;
struct person
{
	string name;
	int sex;
	int age;
	string phone;
	string Addr;
};
struct Addressbooks
{
	person pArray[MAX];
	int size;

};
void showMenu()
{
	cout << "****************************" << endl;
	cout << "*****   1.添加联系人   *****" << endl;
	cout << "*****   2.显示联系人   *****" << endl;
	cout << "*****   3.删除联系人   *****" << endl;
	cout << "*****   4.查找联系人   *****" << endl;
	cout << "*****   5.修改联系人   *****" << endl;
	cout << "*****   6.清空联系人   *****" << endl;
	cout << "*****   0.退出通讯录   *****" << endl;
	cout << "****************************" << endl;
}
void addPerson(Addressbooks* p)
{
	if (p->size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		p->pArray[p->size].name = name; 
		int  Sex;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (true)
		{
			cin >> Sex;
			if (Sex == 1 || Sex == 2)
			{
				p->pArray[p->size].sex = Sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
			break;
		}
		int age;
		cout << "请输入年龄：" << endl;
		while (true)
		{
			cin >> age;
			if (age > 0)
			{
				p->pArray[p->size].age = age;
				break;
			}
			cout << "输入年龄有误，请重新输入！" << endl;
			
		}
		string phone;
		cout << "请输入联系电话：" << endl;
		
		while (true)
		{
			cin >> phone;
			
			if (phone.size() == 11) 
			{
				p->pArray[p->size].phone = phone;
				break;
			}
			cout << "输入号码有误，请重新输入！" << endl;
			
		}
		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		p->pArray[p->size].Addr = address;
		p->size++;
		cout << "添加成功" << endl;
		
		system("pause");
		system("cls");
		
	}
}
void showPeople(Addressbooks* p)
{
	if (p->size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << "姓名：" << p->pArray[i].name << "\t";
			cout << "性别：" << (p->pArray[i].sex == 1?"男":"女") << "\t";
			cout << "年龄：" << p->pArray[i].age << "\t";
			cout << "手机号码：" << p->pArray[i].phone << "\t";
			cout << "地址：" << p->pArray[i].Addr << endl;

		}
	}
	system("pause");
	system("cls");
}
void deletePerson(Addressbooks *p)
{
	string per;
	
	
			cout << "请输入姓名：" << endl;
			cin >> per;
			for (int i = 0; i < p->size; i++)
			{
				if (p->pArray[i].name.find(per)!=-1)
				{
					for (int j = i; j < p->size; j++)
					{
						if (j!=MAX-1)
						{
							p->pArray[j] = p->pArray[j + 1];
						}
					}
					p->size--;	
					cout << "删除成功" << endl;
				}
				
			}
			system("pause");
			return;
			
	
	
}
void findPerson(Addressbooks *ADD)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < ADD->size; i++)
	{
		if (ADD->pArray[i].name.find(name) != -1)
		{
			cout << "姓名：" << ADD->pArray[i].name << "\t";
			cout << "性别：" << (ADD->pArray[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << ADD->pArray[i].age << "\t";
			cout << "手机号码：" << ADD->pArray[i].phone << "\t";
			cout << "地址：" << ADD->pArray[i].Addr << endl;
		}
	}
}
int main()
{
	Addressbooks abs;
	abs.size = 0;
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPeople(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "请输入正确序号" << endl;
			break;
		}
		
	}

	system("pause");
	return 0;

}