#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
using namespace std;
struct Student
	{
		char num[15];
		char name[10];
		char sex;
		Student *next;
	};
void get_data()
	{
		int get_quantity;
		ifstream infile("d:/s_dt.txt",ios::in|ios::binary);
		if(!infile)
			cout<<"error,file cannot be opened."<<endl;
		else
		{
			cout<<"�������ǰ������ѧ�������ݣ�";
			cin>>get_quantity;
		char *p2=new char[get_quantity*50];
		infile.read(p2,get_quantity*50);
		cout<<p2;
		infile.close();
		}
	}
	
/*�ļ������ο�����
void save_to_file()
{
	ofstream outfile("e:/f2.dat");
	//��������ļ�������outfile���������ʽ�򿪴����ļ�f2.dat
	if(!outfile)
	{
		cerr<<"open f2.dat error!"<<endl;
		exit(1);
	}
	char c[80];
	cin.getline(c,80);//�Ӽ��̶���һ���ַ���
	for(int i=0;c[i]!=0;i++)
		if(c[i]>=65 && c[i]<=90||c[i]>=97 && c[i]<=122)//�������ĸ�ַ�
		{
			outfile.put(c[i]);
			cout<<c[i];
		}
		cout<<endl;
		outfile.close();

}*/
void data_save(Student *head,int save_choice)
{
	if(head==NULL)ofstream outfile("d:/s_dt.txt",ios::out|ios::binary);
	else
	{
	if(save_choice==1)
	{
	Student * save_head=head;
	ofstream outfile("d:/s_dt.txt",ios::out|ios::binary);
	if(!outfile)
	{
		cout<<"open f2.dat error!����һ�����̴����ļ�"<<endl;
		ofstream outfile("e:/s_dt.txt");
	}
	outfile<<setiosflags(ios::fixed)<<setprecision(0);
	outfile<<"ѧ��\t\t\t����\t\t�Ա�\n";//33 bytes;
	while(save_head->next!=NULL)
	{
		outfile<<save_head->num<<"\t\t"<<save_head->name<<"\t\t"<<save_head->sex<<endl;
		save_head=save_head->next;
		
	}
	
	outfile<<save_head->num<<"\t\t"<<save_head->name<<"\t\t"<<save_head->sex<<endl;
	cout<<"�ɹ�д���ļ�"<<endl;
	outfile.close();
	}
	else
	{	
		Student * save_head=head;
		ofstream outfile("d:/s_dt.txt",ios::app);
		outfile<<setiosflags(ios::fixed)<<setprecision(0);
		while(save_head->next!=NULL)
		{
			outfile<<save_head->num<<"\t\t"<<save_head->name<<"\t\t"<<save_head->sex<<endl;
			save_head=save_head->next;
		
		}
	
		outfile<<save_head->num<<"\t\t"<<save_head->name<<"\t\t"<<save_head->sex<<endl;
		cout<<"�ɹ�д���ļ�."<<endl;
		outfile.close();
	}
	}
}
int main()
{
	//����������
	Student *create();
	Student *add(Student * ,char[]);
	Student *sort(Student*,char[]);
	Student *edit(Student*,char[]);
	Student *data_cancel(char[]);
	void display(Student *);
	void data_save(Student *);
	void single_display(Student*);
	void meau();
	system("cls");//����
	meau();
	/*head=create();
	//cout<<p;
	display(head);
	cout<<"which student do u want to find?:(number-based search.)"<<endl;
	cin>>sort_num;
	p=sort(head,sort_num);
	single_display(p);
	cout<<"\n";
	cout<<"which student do u want to add?:(num)"<<endl;
	cin>>add_num;
	add(head,add_num);
	display(head);
	cout<<"\n";
	cout<<"please input the student's number u want to edit:"<<endl;
	cin>>edit_num;
	edit(head,edit_num);
	display(head);
	cout<<"which student do u want to delete?(num)"<<endl;
	cin>>cancel_num;
	head=data_cancel(head,cancel_num);
	display(head);*/
	return 0;
}
	
void display(Student *pPointer)
{
	cout<<"ѧ��"<<"\t\t\t"<<"����\t\t"<<"�Ա�"<<endl;
	while(pPointer!=NULL)
	{
		cout<<setiosflags(ios::fixed)<<setprecision(0);
		cout<<pPointer->num<<"\t\t"<<pPointer->name<<"\t\t"<<pPointer->sex<<endl;
		pPointer=pPointer->next;
	}
}

void single_display(Student*pPointer)
{
	cout<<setiosflags(ios::fixed)<<setprecision(0);
	cout<<"ѧ��"<<"\t\t\t"<<"����\t\t"<<"�Ա�"<<endl;
	cout<<pPointer->num<<"\t\t"<<pPointer->name<<"\t\t"<<pPointer->sex<<endl;
}
Student* create()
{
	Student *pPrev;
	Student *pCurrent;
	Student *head;
	double n=0;

				pCurrent=new Student();
				pPrev=pCurrent;
				cout<<"������ѧ����ѧ�ź������Լ��Ա�(f or m)����0 0 0������"<<endl;
				cin>>pCurrent->num>>pCurrent->name>>pCurrent->sex;
		while (strcmp(pCurrent->num,"0")!=0)
			{	
				n+=1;
				if(n==1)head=pCurrent;
				else pPrev->next=pCurrent;
				pPrev=pCurrent;
				pCurrent=new Student();
				cout<<"\n������ѧ����ѧ�ź������Լ��Ա�(f or m)����0 0 0������"<<endl;
				cin>>pCurrent->num>>pCurrent->name>>pCurrent->sex;
				pCurrent->next=NULL;
			}
		return head;
		
}

Student *sort(Student *p,char sort_num[15])
{
	char *pChar= new char[15];
	char *pName = new char[10];
	char *pSex=new char;
	Student *next=new Student();
	ifstream infile("d:/s_dt.txt",ios::in|ios::binary);
	if(!infile)
		cout<<"error!fail to open the file!"<<endl;
	else
	{
		
		infile.seekg(33,ios::beg);
		infile.read(pChar,14);
		infile.seekg(12,ios::cur);
		infile.read(pName,5);
		infile.seekg(8,ios::cur);
		infile.read(pSex,1);
		strcpy(next->num,pChar);
		strcpy(next->name,pName);
		strcpy(&(next->sex),pSex);
		cout<<*pChar<<*pName<<*pSex<<endl;
		//cout<<next->num<<next->name<<next->sex<<endl;
		/*while()
		{
			if(strcmp(sort_num,pChar)==0){return p;break;}
			else p=p->next;
		}*/
	}
}

Student *add(Student *head,char add_num[15])
{
	Student *add_head=head;
	Student *p_add=new Student();
	if(strcmp(p_add->num,add_num))
	{
	cout<<"������ѧ��Ϊ"<<add_num<<"��ѧ�����������Ա�"<<endl;
	cin>>p_add->name>>p_add->sex;
	}
	while(add_head!=NULL)
	{
		if(add_head->next==NULL){add_head->next=p_add;break;}
		else add_head=add_head->next;
	}
	return p_add;
}

Student *edit(Student* head,char edit_num[15])
{
	ifstream infile("d:/s_dt.txt",ios::in|ios::binary);
	Student *edit_head=head;
	
		if(strcmp(edit_num,edit_head->num)==0)
			{
				cout<<"�����޸ĵ�ѧ�����ҵ������޸�����ѧ�ź��������Ա�"<<endl;
				cin>>edit_head->num>>edit_head->name>>edit_head->sex;
				
			}
		else edit_head=edit_head->next;
	
	return head;
}

Student *data_cancel(char cancel_num[15])
{
	ifstream infile("d:/s_dt.txt",ios::binary|ios::in|ios::out);
	if(!infile)cout<<"error!fail to open the file!"<<endl;
	else
	{
		Student *temp2=NULL;
		Student *cancel_head;
		
		Student *temp1=NULL;
		int i=0;
		while(cancel_head!=NULL)
		{
			i+=1;
			if(strcmp(cancel_head->num,cancel_num)==0 && i==1 )
			{
				temp1=cancel_head;
				cancel_head=cancel_head->next;
				delete temp1;
				//cout<<"fisrt node been deleted"<<endl;
				return cancel_head;
				
				
			}
			else if(strcmp(cancel_head->next->num,cancel_num)==0 && cancel_head->next->next==NULL)//cancel_head=head
			{
				
				temp1=cancel_head->next;//temp1�Ǹ�ָ��Student�͵�ָ�롣
				delete temp1;
				cancel_head->next=NULL;
				//cout<<cancel_head->next->next;
				//cout<<"last node been deleted"<<endl;
				return cancel_head;
				
			}
			else if(strcmp(cancel_head->next->num,cancel_num)==0 && cancel_head->next->next!=NULL)
			{
				temp2=cancel_head->next;
				
				temp1=temp2->next;
				delete temp2;
				cancel_head->next=temp1;
				return cancel_head;
				
			}
			if(strcmp(cancel_head->num,cancel_num)!=0 && cancel_head->next==NULL)
			{
				cout<<"��ѧ�������ڣ�"<<endl;
				return cancel_head;
			}
			
			cancel_head=cancel_head->next;
			
		}
	}
}

void meau()
{
	
	char sort_num[15];
	char add_num[15];
	char edit_num[15];
	char cancel_num[15];
	int save_choice=1;
	Student *p=NULL;
	Student *head=NULL;
	int choice;
	while(true)
	{
	cout<<"-------------------------��ӭ����ѧ����Ϣ����ϵͳ------------------------"<<endl;
	cout<<"------------------------1.����һ���µ�ѧ�����ݱ���������---------------"<<endl;
	cout<<"------------------------2.����ѧ����Ϣ-----------------------------------"<<endl;
	cout<<"------------------------3.�༭ѧ����Ϣ-----------------------------------"<<endl;
	cout<<"------------------------4.���ѧ����Ϣ-----------------------------------"<<endl;
	cout<<"------------------------5.ɾ��ѧ����Ϣ-----------------------------------"<<endl;
	cout<<"------------------------6.�˳�-------------------------------------------"<<endl;
	cout<<"------------------------7.��ʾ��Ϣ---------------------------------------"<<endl;
	cout<<"---------------------�밴�����������ѡ��Ĺ���Ȼ�󰴻س�----------------"<<endl;
	cin>>choice;	
	switch(choice)
	{
	case(1):
		head=create();
		data_save(head,save_choice);
		cout<<"����������ز˵���"<<endl;
		getch();
		system("cls");
		break;
		
	case(2):
		{
			cout<<"���������Ǹ�ѧ������Ϣ��������ѧ�ţ�"<<endl;
			cin>>sort_num;
			p=sort(head,sort_num);
			single_display(p);
			cout<<"����������ز˵�"<<endl;
			getch();
			system("cls");
			break;
		}
		
	case(3):
		{
			if(head)
			{
				cout<<"����������༭��ѧ����ѧ��:"<<endl;
				cin>>edit_num;
				edit(head,edit_num);
				data_save(head,1);
				cout<<"�ɹ��༭�˸�ѧ����Ϣ"<<endl;
				cout<<"����������ز˵�"<<endl;
				getch();
				system("cls");
				break;
			}
			else {cout<<"������δ���������������ϵͳ���ص��˵�����"<<endl;getch();system("cls");break;}
		}
	case(4):
		{
			cout<<"������������ӵ�ѧ����ѧ�ţ�"<<endl;
			cin>>add_num;
			p=add(head,add_num);
			data_save(p,0);
			cout<<"����������ز˵�"<<endl;
			getch();
			system("cls");
			break;
					
		}
	case(5):
		{
			
			
			
				cout<<"����������ɾ����ѧ����ѧ�ţ�"<<endl;
				cin>>cancel_num;
				head=data_cancel(cancel_num);
				data_save(head,1);
				cout<<"ѧ����Ϣɾ���ɹ�"<<endl;
				cout<<"����������ز˵�"<<endl;
				getch();
				system("cls");
				break;
			
		}

	case(6):
		{
			if(head==NULL)exit(0);
			else
			for(Student *p3=head;p3->next!=NULL;p3=p3->next)
				{
					delete p3;
					//cout<<"room been released"<<endl;
					
				}
			
				head=NULL;
				exit(0);
			
			
		}
	case(7):
		{
			get_data();
			cout<<"����������ز˵�"<<endl;
			getch();
			system("cls");
			break;
		}
	default:
		{
			cout<<"��ѡ���ѡ����ڣ�����������ز˵�����"<<endl;
			getch();
			system("cls");
			break;
		}
	}
	}
}