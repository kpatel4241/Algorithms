#include<bits/stdc++.h>

using namespace std;

struct Item
{
	int value , weight;
};


bool comparasion(Item A , Item B)
{
	float t1 = (float)(A.value/A.weight);
	float t2 = (float)(B.value/B.weight);

	return (t1 > t2);
}


float fractional_knapsack(Item A[] , int max_capacity , int n)
{
	int current_weight = 0; 
	float final_value = 0.0;

	sort(A , A+n , comparasion);

	for(int i=0;i<n;i++)
	{
		if(current_weight + A[i].weight <= max_capacity)
		{
			current_weight += A[i].weight;
			final_value += A[i].value;
		}
		else
		{
			int remain_weight = max_capacity - current_weight;
			final_value += A[i].value*((float)remain_weight/A[i].weight);
			break;
		}
	}

	return final_value;
}


int main()
{
	int n,max_size;
	cout<<"\n Enter the Size : ";
	cin>>n;

	Item _item_[n];
	cout<<"\n Enter the Value & Weight : ";
	for(int i=0;i<n;i++)
		cin>>_item_[i].value>>_item_[i].weight;

	cout<<"\n Enter the max_capacity of Knapsack : ";
	cin>>max_size;

	float final_value = fractional_knapsack(_item_ , max_size , n);

	cout<<"\n Max. Total Profit = "<<final_value<<endl;

	return 0;
}
