#pragma once
//这是头文件queue.h。这是类Queue的接口，该类用于表示一个字符队列
#ifndef QUEUE_H
#define QUEUE_H
namespace queuesavitch
{
	struct QueueNode
	{
		char data;
		QueueNode *link;
	};

	typedef QueueNode* QueueNodePtr;

	class Queue
	{
	public:
		Queue();//将对象初始化为一个空的队列
		Queue(const Queue& aQueue);//拷贝构造函数
		~Queue();//析构函数

		void add(char item);//将数据项添加到队列的末尾
		char remove();		//条件：队列非空，返回队列前端的数据项并从队列中删除该项
		bool empty() const; //如果队列为空，则返回true，反之返回false

	private:
		QueueNodePtr front;//指向链表的表头，数据项在表头删除
		QueueNodePtr back; //指向链表的另一端，数据项在这一端添加
	};
}//queuesavitch
#endif // !QUEUE_H