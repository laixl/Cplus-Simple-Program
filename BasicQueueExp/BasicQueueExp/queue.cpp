//这是实现文件queue.cpp
//这是Queue类的实现
//Queue类的接口在头文件queue.h中

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "queue.h"
using namespace std;

namespace queuesavitch
{
	//使用cstddef:
	Queue::Queue():front(NULL), back(NULL)
	{
		//有意留空
		//front = NULL;
		//back = NULL;
	}
	Queue::Queue(const Queue& aQueue)
	{
		if (aQueue.empty())
			front = back = NULL;
		else
		{
			QueueNodePtr temp_ptr_old=aQueue.front;//temp_ptr_old在aQueue中，从front到back遍历所有节点
			QueueNodePtr temp_ptr_new;//temp_ptr_new在Queue类的新对象中，用于为该对象创建新节点
			
			back = new QueueNode;
			back->data = temp_ptr_old->data;
			back->link = NULL;
			front = back;
			//第一个节点已经创建，而且填充了数据
			//现在，新节点要在这个节点之后添加

			temp_ptr_old = temp_ptr_old->link;
			//temp_ptr_old现在指向aQueue的第二个节点；如果没有第二个节点，则为NULL

			while (temp_ptr_old != NULL)
			{
				temp_ptr_new = new QueueNode;
				temp_ptr_new->data = temp_ptr_old->data;
				temp_ptr_new->link = NULL;
				back->link = temp_ptr_new;
				back = temp_ptr_new;

				temp_ptr_old = temp_ptr_old->link;//再次更新aQueue中的temp_ptr_old
			}
		}
	}
	Queue::~Queue()
	{
		char next;
		while (!empty())
			next = remove();//remove调用delete
	}

	//使用cstddef：
	bool Queue::empty() const
	{
		return (back == NULL);//或者front==NULL
	}
	//使用cstddef:
	void Queue::add(char item)
	{
		if (empty())
		{
			front = new QueueNode;
			front->data = item;
			front->link = NULL;
			back = front;
		}
		else
		{
			QueueNodePtr temp_ptr;
			temp_ptr = new QueueNode;
			temp_ptr->data = item;
			temp_ptr->link = NULL;
			back->link = temp_ptr;
			back = temp_ptr;
		}
	}

	//使用cstdlib和iostream
	char Queue::remove()
	{
		if (empty())
		{
			cout << "Error:Removing an item from an empty queue.\n";
			exit(1);
		}

		char result = front->data;
		QueueNodePtr discard;
		discard = front;
		front = front->link;
		if (front == NULL)//如果已经删除了最后一个节点
			back = NULL;
		delete discard;

		return result;
	}
}//queuesavitch