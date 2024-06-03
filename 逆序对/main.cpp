#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
int n = 0;
long long result = 0;
vector<int> v;
////归并排序
//void merge(vector<int>& nums, int left, int mid, int right)
//{
//	//初始化辅助数组
//	vector<int> tmp(nums.begin() + left, nums.begin() + right + 1);
//	//左数组的起始和结束索引
//	int leftStart = left - left;
//	int leftEnd = mid - left;
//	//右数组的起始和结束索引
//	int rightStart = mid + 1 - left;
//	int rightEnd = right - left;
//	//i,j分别指向左右数组的首元素
//	int i = leftStart;
//	int j = rightStart;
//	//开始合并数组，通过覆盖原数组
//	for (int k = left; k <= right; ++k)
//	{
//		//如果左边的数组全部放入后右数组仍有数
//		if (i > leftEnd)
//		{
//			nums[k] = tmp[j++];
//		}
//		//如果右数组全部放入后左数组仍有数或者左边比右边小
//		else if (j > rightEnd || tmp[i] <= tmp[j])
//		{
//			nums[k] = tmp[i++];
//		}
//		//如果右边比左边小
//		else
//		{
//			nums[k] = tmp[j++];
//		}
//	}
//}
//归并排序的基础上求逆序对
void merge(vector<int>& nums, int left, int middle, int right)
{
	//初始化辅助数组
	vector<int>tmp(nums.begin() + left, nums.begin() + right + 1);
	//确定左右边界
	//左边界
	int leftStart = left - left;
	int leftEnd = middle - left;
	//右边界
	int rightStart = middle - left + 1;
	int rightEnd = right - left;
	//i,j分别指向左右边界
	int i = leftStart;
	int j = rightStart;
	//做归并排序，通过覆盖原数组
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
	//划分
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