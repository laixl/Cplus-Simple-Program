#pragma once
//����ͷ�ļ�queue.h��������Queue�Ľӿڣ��������ڱ�ʾһ���ַ�����
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
		Queue();//�������ʼ��Ϊһ���յĶ���
		Queue(const Queue& aQueue);//�������캯��
		~Queue();//��������

		void add(char item);//����������ӵ����е�ĩβ
		char remove();		//���������зǿգ����ض���ǰ�˵�������Ӷ�����ɾ������
		bool empty() const; //�������Ϊ�գ��򷵻�true����֮����false

	private:
		QueueNodePtr front;//ָ������ı�ͷ���������ڱ�ͷɾ��
		QueueNodePtr back; //ָ���������һ�ˣ�����������һ�����
	};
}//queuesavitch
#endif // !QUEUE_H