#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
int n = 0;
long long result = 0;
vector<int> v;
////�鲢����
//void merge(vector<int>& nums, int left, int mid, int right)
//{
//	//��ʼ����������
//	vector<int> tmp(nums.begin() + left, nums.begin() + right + 1);
//	//���������ʼ�ͽ�������
//	int leftStart = left - left;
//	int leftEnd = mid - left;
//	//���������ʼ�ͽ�������
//	int rightStart = mid + 1 - left;
//	int rightEnd = right - left;
//	//i,j�ֱ�ָ�������������Ԫ��
//	int i = leftStart;
//	int j = rightStart;
//	//��ʼ�ϲ����飬ͨ������ԭ����
//	for (int k = left; k <= right; ++k)
//	{
//		//�����ߵ�����ȫ�������������������
//		if (i > leftEnd)
//		{
//			nums[k] = tmp[j++];
//		}
//		//���������ȫ�������������������������߱��ұ�С
//		else if (j > rightEnd || tmp[i] <= tmp[j])
//		{
//			nums[k] = tmp[i++];
//		}
//		//����ұ߱����С
//		else
//		{
//			nums[k] = tmp[j++];
//		}
//	}
//}
//�鲢����Ļ������������
void merge(vector<int>& nums, int left, int middle, int right)
{
	//��ʼ����������
	vector<int>tmp(nums.begin() + left, nums.begin() + right + 1);
	//ȷ�����ұ߽�
	//��߽�
	int leftStart = left - left;
	int leftEnd = middle - left;
	//�ұ߽�
	int rightStart = middle - left + 1;
	int rightEnd = right - left;
	//i,j�ֱ�ָ�����ұ߽�
	int i = leftStart;
	int j = rightStart;
	//���鲢����ͨ������ԭ����
	for (int k = left; k <= right; ++k)
	{
		if (i > leftEnd)
		{
			nums[k] = tmp[j++];
			continue;
		}
		if (j > rightEnd)
		{
			nums[k] = tmp[i++];
			continue;
		}
		if (tmp[i] <= tmp[j])
		{
			nums[k] = tmp[i++];
		}
		else
		{
			nums[k] = tmp[j++];
			result += leftEnd - i + 1;
		}
	}
}
void mergeSort(vector<int>& nums, int left, int right)
{
	if (left >= right)
		return;
	//����
	int mid = (left + right) / 2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	merge(nums, left, mid, right);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		cin >> k;
		v.push_back(k);
	}
	mergeSort(v, 0, v.size() - 1);
	cout << result;
	return 0;
}