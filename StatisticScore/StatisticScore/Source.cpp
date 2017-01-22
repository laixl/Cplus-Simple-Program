#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef int* IntPtr;

vector<int> Input_Score();
//������������ش洢�˷���������
void Statistic_Score(vector<int> score);
//ͳ�Ʒ������ֵĴ�������������Ϊ����
//���ͳ�ƵĽ��������̨


int main()
{
	vector<int> score_list;
	score_list = Input_Score();
	Statistic_Score(score_list);
	return 0;
}

vector<int> Input_Score()
{
	cout << "Enter a list of nonnegative scores." << endl
		<< "End with a negative number." << endl;

	vector<int> score_list;
	int next;
	cin >> next;
	while (next >= 0)
	{
		score_list.push_back(next);
		cin >> next;
	}

	cout << "Input Ending.\n";
	return score_list;
}

void Statistic_Score(vector<int> score)
{
	vector<int> score_norepetition;	//�洢���ظ��ķ���
	int length;						//����score_norepetition�ĳ���
	IntPtr statistic_result;		//��̬����洢ͳ�ƽ��
	int k = 0;

	
	sort(score.begin(), score.end());//������
	//score_norepetition[k] = score[0];//�����±�Խ��
	score_norepetition.push_back(score[0]);

	for (unsigned int i = 0; i < score.size(); i++)
	{
		while (score[i] != score_norepetition[k])
		{
			k++;
			score_norepetition.push_back(score[i]);
		}
	}

	length = score_norepetition.size();
	statistic_result = new int[length];
	for (unsigned int i = 0; i < length; i++)
	{
		statistic_result[i] = 0;
		for (unsigned int j = 0; j < score.size(); j++)
		{
			if (score[j] == score_norepetition[i])
			{
				statistic_result[i]++;
			}
		}		
	}

	for (unsigned int i = 0; i < length; i++)
	{
		cout << "Number of " << score_norepetition[i] << " is: "
			<< statistic_result[i] << endl;
	}

	delete[] statistic_result;
}
