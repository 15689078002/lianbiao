//=========================================================================
//	文件名：	1_creat.c
//  功能描述：	建立一个n个结点的链表，存放学生数据
//=========================================================================
typedef struct stu
{
	int num;
	int age;
	struct stu *next;
}TYPE;

TYPE *creat(int n)							//创建一个指针函数，用于创建一个有N个节点的链表
{
	struct stu *head=NULL,*pf=NULL,*pb=NULL;//定义三个struct stu类型的指针变量
	int i=0;								//head用于指向本链表的首地址，pb用于指向刚刚分配的空间首址，pf用于指向已建立的链表的最后一个元素

	for( i=0;i<n;i++ )
	{
		pb = (TYPE*)malloc(sizeof(TYPE));	//申请一个动态链表空间
		printf("input Number and Age\n");
		scanf("%d %d",&pb->num,&pb->age);	//输入元素内容

		if(i==0)							//判断是否第一个学生
			pf=head=pb;						//将新申请的空间加入链表
		else
		{
			pf->next=pb;
			pf=pb;
		}

		pb->next=NULL;
	}
	return(head);							//返回整个链表的首地址
}


//=========================================================================
//	文件名：	2_print.c
//  功能描述：	遍历链表
//=========================================================================
typedef struct stu
{
	int num;
	int age;
	struct stu *next;
}TYPE;

void print(TYPE * head)
{
	TYPE *pb;
	pb=head;
	while(pb!=NULL)
	{
		printf("%d %d \n",pb->num,pb->age);
		pb=pb->next;
	}
}


//=========================================================================
//	文件名：	3_search.c
//  功能描述：	在链表中按学号查找该结点。
//=========================================================================
typedef struct stu
{
	int num;
	int age;
	struct stu *next;
}TYPE;

TYPE *search(TYPE *head,int n)				//在一个已建立的链表中查找某一节点
{
	TYPE *p=NULL;
	p = head;								//导入已存在链表的头文件
	while( (p->num!=n) && (p->next!=NULL ))	//判断是否找到要找的数据，判断是否到链表尾
	{
		p=p->next; 							//不是要找的结点后移一步
	}

	//以上的while循环推出的条件是，找到想要的阶段或者没有节点可以再找
	if( p->num == n )						//如果找到节点
	{
		return p;							//返回相应指针地址
	}
	else
	{										//到链表尾则打印数据未找到
		printf ("not found!\n");
	}
}


//=========================================================================
//  工程名称：	4_delete.c
//  功能描述： 	链表删除实验
//	程序分析：	写一个函数，删除链表中的指定结点。删除一个结点有两种情况
//				被删除结点是第一个结点，使head指向第二个结点即可。即head=pb->next
//				被删结点不是第一个结点，使被删结点的前一结点指向被删结点的后一结点即可。
//				即pf->next=pb->next
//=========================================================================
typedef struct stu
{
	int num;
	int age;
	struct stu *next;
}TYPE;

TYPE * delete(TYPE * head,int num)
{
	TYPE *pf=NULL,*pb=NULL;

	if(head == NULL)							//如果链表为空
	{
		printf("empty list!\n");
		return NULL;
	}

	pb = head;
	while( (pb->num!=num) && (pb->next!=NULL) )	//当不是要删除的结点，而且也不是最后一个结点时，继续循环
	{
		pf=pb;
		pb=pb->next;							//pf指向当前结点，pb指向下一结点
	}

	if( pb->num == num )						//如果上面while推出是因为找到了要删除的节点
	{
		if( pb==head )							//如为第一结点，则使head指向第二个结点
			head=pb->next;
		else
			pf->next=pb->next;					//否则使pf所指结点的指针指向下一结点

		free(pb);								//释放删除节点所占空间
		printf("The node is deleted\n");
	}
	else
	{
		printf("The node not been foud!\n");
	}
	return head;
}


//=========================================================================
//  工程名称：	5_inster.c
//  功能描述： 	链表插入实验
//	程序分析：
//			1. 原表是空表，只需使head指向被插结点即可；
//			2. 被插结点值最小，应插入第一结点之前。这种情况下使head指向被插结点，被插结点的指针域指向原来的第一结点则可；
//			3. 在其它位置插入，这种情况下，使插入位置的前一结点的指针域指向被插结点，使被插结点的指针域指向插入位置的后一结点；
//			4. 在表末插入，这种情况下使原表末结点指针域指向被插结点，被插结点指针域置为NULL；
//	硬件连接：	无
//=========================================================================
// NULL
typedef struct stu
{
    int num;
    int age;
    struct stu *next;
}TYPE;
TYPE *insert(TYPE *head,int n)//传参数n是插入第n个以后
{
    TYPE *pb=NULl,*pf=NULL;
    if(head == NULL)
    {
        printf("empty list!\n");
        return NULL;
    }
    
    pb=head;
    int i=0;
    whlie(i<n &&pb!=NULL)
    {
        pb=pb->next;//pb和head开始是一个地址
        i++
        
    }
    pf=(TYPE*)malloc(sizeof(TYPE))//需要插入节点
    pf->next=pb->next;
    pb->next=pf;
    return 0;
    
}










//=========================================================================
//	文件名：	6_free.c
//  功能描述：	释放整条链表
//=========================================================================
void link_free(TYPE * head)
{
	TYPE * pb=NULL;
	pb=head;
	while(head!=NULL)
	{
		head=head->next;
		free(pb);
		pb=head;
	}
}


//=============================================================
// 语法格式：	STU * order(STU * head)
// 实现功能：	采用选择法，对指定链表按序号进行排序（只交换数据域）
// 参数：		head：待排序的链首址
// 返回值：		排好序的链表head指针
//=============================================================
 STU * order(STU * head)
{
	STU temp;
	STU *pf=NULL,*pb=NULL;
	pb = pf = head;
	if(head == NULL)
	{
		printf("list is null\n");
		return NULL;
	}
	while(pf->next!= NULL)
	{
		pb	= pf->next;
		while(pb!= NULL)
		{
			if(pf->number > pb->number)
			{
				//对结构体中所有的成员进行交换
				temp = *pb;
				*pb = *pf;
				*pf = temp;

				//为了保持修改之前链表连续性，需要把指针域再给换回去
				temp.next = pb->next;
				pb->next = pf->next;
				pf->next = temp.next;
			}
			pb = pb ->next;
		}
		pf = pf->next;
	}
	return (head);
}
