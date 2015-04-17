#include "sokobanGame.h"
#include <stdio.h>
#include <malloc/malloc.h>

//定义链表中要存储的数据类型
typedef char DataType;

//定义链表元素的数据结构
typedef struct linknode
{
    DataType data;//节点的据域
    struct linknode *next;
}linknode;

//头插入法建立单链表
linknode* CreateListF(void)
{
    char ch;
    linknode *head;
    linknode *s;
    head=NULL;
    ch=getchar();
    while(ch!='\n')
    {
        s=(linknode*)malloc(sizeof(linknode));
        s->data=ch;
        s->next=head;
        head=s;
        ch=getchar();
    }
    return head;
}

//尾插入法建立单链表
void CreateListR(linknode *head)
{
    //声明尾指针及工作指针
    linknode *r,*s;
    char ch;
    ch=getchar();
    r=head;
    while(ch!='\n')
    {
        s=(linknode*)malloc(sizeof(linknode));
        s->data=ch;
        r->next=s;
        r=s;
        ch=getchar();
    }
    r->next=NULL;
}

//获取链表长度
int getLength(linknode* head)
{
    int length=0;
    linknode *s;
    s=head->next ;
    while(s!=NULL)
    {
        s=s->next;
        ++length;
    }
    return length;
}

//获取指定位置的链表元素
linknode* getNode(linknode *head,int i)
{
    int listLength=0;
    int j=1;
    linknode *s;
    listLength=getLength(head);
    if(i<1||i>listLength)
    {
        printf("i value is error! \n");
        return NULL;
    }
    else
    {
        s=head->next ;
        while(s!=NULL)
        {
            if(i==j)
            {
                return s;
            }
            else
            {
                s=s->next;
                j++;
            }
        }
        return NULL;
    }
}

//在指定的位置插入一个元素
void insertList(linknode* head,DataType x,int i)
{
    linknode *s,*p;
    p=getNode(head,i-1);
    if(p==NULL)
    {
        printf("the position is Error!\n");
    }
    else
    {
        s=(linknode*)malloc(sizeof(linknode));
        s->data=x;
        s->next=p->next;
        p->next=s;
    }
}

//删除指定位置元素
void deleteList(linknode *head,int i)
{
    linknode *p,*s;
    p=getNode(head,i-1);
    if(p==NULL||p->next==NULL)
    {
        printf("the position is Error!\n");
    }
    else
    {
        s=p->next;;
        p->next=s->next;
        free(s);
    }
}

//打印链表中的所有元素
void printLinkList(linknode* L)
{
    linknode *nextNode;
    nextNode=L;
    do
    {
        nextNode=nextNode->next;
        printf("%c \n",nextNode->data);
    }
    while(nextNode->next!=NULL);
}

int main() {
    linknode *flist,*rlist,*find;
    int index; char value;
    rlist=(linknode*)malloc(sizeof(linknode));
    rlist->next=NULL;
    printf("plase input a sting,end with the KEY_Enter \n");
    //flist=CreateListF();
    //printLinkList(flist);
    CreateListR(rlist);
    printLinkList(rlist);
    printf("list length=%d \n",getLength(rlist));
    printf("set insert node:index,value:");
    scanf("%d,%c",&index,&value);
    printf("insert a element!");
    insertList(rlist,value,index);
    printLinkList(rlist);
    printf("list length=%d \n",getLength(rlist));
    printf("set delete node index:");
    scanf("%d",&index);
    deleteList(rlist,index);
    printf("delete a element!");
    printLinkList(rlist);
    printf("list length=%d \n",getLength(rlist));
    printf("set visit node index:");
    scanf("%d",&index);
    find=getNode(rlist,index);
    if(find!=NULL)
    {
        printf("this node value=%c \n",find->data);
    }
    
    return 0;
}
