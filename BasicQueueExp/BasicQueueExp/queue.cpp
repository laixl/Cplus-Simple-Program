//����ʵ���ļ�queue.cpp
//����Queue���ʵ��
//Queue��Ľӿ���ͷ�ļ�queue.h��

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "queue.h"
using namespace std;

namespace queuesavitch
{
	//ʹ��cstddef:
	Queue::Queue():front(NULL), back(NULL)
	{
		//��������
		//front = NULL;
		//back = NULL;
	}
	Queue::Queue(const Queue& aQueue)
	{
		if (aQueue.empty())
			front = back = NULL;
		else
		{
			QueueNodePtr temp_ptr_old=aQueue.front;//temp_ptr_old��aQueue�У���front��back�������нڵ�
			QueueNodePtr temp_ptr_new;//temp_ptr_new��Queue����¶����У�����Ϊ�ö��󴴽��½ڵ�
			
			back = new QueueNode;
			back->data = temp_ptr_old->data;
			back->link = NULL;
			front = back;
			//��һ���ڵ��Ѿ��������������������
			//���ڣ��½ڵ�Ҫ������ڵ�֮�����

			temp_ptr_old = temp_ptr_old->link;
			//temp_ptr_old����ָ��aQueue�ĵڶ����ڵ㣻���û�еڶ����ڵ㣬��ΪNULL

			while (temp_ptr_old != NULL)
			{
				temp_ptr_new = new QueueNode;
				temp_ptr_new->data = temp_ptr_old->data;
				temp_ptr_new->link = NULL;
				back->link = temp_ptr_new;
				back = temp_ptr_new;

				temp_ptr_old = temp_ptr_old->link;//�ٴθ���aQueue�е�temp_ptr_old
			}
		}
	}
	Queue::~Queue()
	{
		char next;
		while (!empty())
			next = remove();//remove����delete
	}

	//ʹ��cstddef��
	bool Queue::empty() const
	{
		return (back == NULL);//����front==NULL
	}
	//ʹ��cstddef:
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

	//ʹ��cstdlib��iostream
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
		if (front == NULL)//����Ѿ�ɾ�������һ���ڵ�
			back = NULL;
		delete discard;

		return result;
	}
}//queuesavitch