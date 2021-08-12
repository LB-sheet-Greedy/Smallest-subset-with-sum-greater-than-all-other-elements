/*
The Brute force approach is to find the sum of all the possible subsets and then compare 
sum with the sum of remaining elements.

Time Complexity : O(n^2)


The Efficient Approach:

TO SORT ARRAY IN DECREASING ORDER
sort(arr, arr + n, greater<T>());


Time Complexity : O(n Log n)

Appraoch: (U TUBE)

>> Sort the array
>> do subsets imagine karo, ek empty hai jiska count apna answer hoga and another is remaining subset
   jisme ans subset ke alawaa saare elements hai
>> Apan sirf in dono ki sum se khelenege taaki chize simple rahe 
>> jab bhi ans subarray ka sum > remaining subarray ka sum ho to return karo ans subarray ke count ko

*/

#include <bits/stdc++.h>
using namespace std;

int minElements(int arr[], int n)
{
	int remaining_sum=0;
	int ans_subset_sum=0;
	int CountOfAnsSubset=0;
	
	sort(arr,arr+n);
	
	//remaining_sum will be equal to sum of all elements initially
	for(int i=0;i<n;i++)
	{
		remaining_sum=remaining_sum+arr[i];
	}
	
	//traverse from last (Greedy, sum maximize karna hai)
	for(int i=n-1;i>=0;i--)
	{
		//ek ek karke aakhri ke eleemnts ko subset me include karte jao(iniially 0 hai)
		//sirf sum me khelenge actual me element add nhi karenge
		ans_subset_sum=arr[i];
		
		//ab remaining sum ko modify karo kyuki ek element kam ho jaayga usmese
		remaining_sum=remaining_sum-ans_subset_sum;
		CountOfAnsSubset++;  //elements jitne included hai unko track karne ke liye
		
		if(ans_subset_sum>remaining_sum)
		{
			return CountOfAnsSubset;
			break;
		}
	}
	
}

// Driver function
int main()
{
    int arr[] ={2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minElements(arr, n) << endl;
    return 0;
}


