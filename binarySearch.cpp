/*
Linear search 
binary search --> recursive
binary search --> iterative
find first or last occurence
count of an element in a sorted list
linear
binary (find the first element and last element) --> interview
how many times is a soted array rotated --> interview
find an element in a circulary sorted array --> interview
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//loop thru the entire array
bool linearS(int* A, int n, int x){
	int* p = A;
	while(*p!=NULL){
		if(*p == x)
			return true;
		p++;
	}
	return false;
}

/*
revursive method
do not forget the + and - 1 after the update
*/
bool binaryS2(int* A, int low, int high, int x){
	int mid = (low+high)/2;

	if(low>high) return false;
	if(A[mid] == x) return true;
	else if(x < A[mid]){
		return binaryS2(A, low, mid-1, x);	
	}
	else{
		return binaryS2(A, mid+1, high, x);
	}  
}

/*
loop thru logN of the array
be careful here, end = mid-1 not end = mid,
the reason is that you what to meet certain condition to exit the while loop
if you just simply using end = mid, then when end right next to start it becomes infinite loop
this is iterative
*/
bool binaryS(int* A, int n, int x){
	int start = 0;
	int end = n-1;

	while(start<=end){
		int mid = (start+end)/2;
		if(A[mid] == x)
			return true;
		else if(x < A[mid]){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	return false;
}

//O(logN)
int findFirstE(int* A, int n, int x){
	int low = 0;
	int high = n-1;
	int result = -1; //does not exist yet

	while(low<=high){
		int mid = (low+high)/2;
		if(A[mid] == x){
			result = mid;
			high = mid-1;
		}
		else if(x < A[mid])
			high = mid-1;
		else
			low = mid+1; 
	}
	return result;
}

//O(logN)
int findLastE(int* A, int n, int x){
	int low = 0;
	int high = n-1;
	int result = -1; //does not exist yet

	while(low<=high){
		int mid = (low+high)/2;
		if(A[mid] == x){
			result = mid;
			low = mid+1;
		}
		else if(x < A[mid])
			high = mid-1;
		else
			low = mid+1; 
	}
	return result;
}
//O(n), in a sorted array
int linearCount(int* A, int n, int x){
	int counter=0;
	for(int i=0; i<n-1; i++){
		if(A[i]==x)
			counter++;
	}
	return counter;
}
//O(logN), in a sorted array
int binaryCount(int* A,  int n, int x){
	int start = findFirstE(A, n, x);
	int end = findLastE(A, n, x);
	return end - start;
}

/*
the array has no duplicate and it is circulated sorted
how to find a pivot point, in an array the pivot point is the smallest number
and its right size and left both are bigger. The idea is to find the pivot point
*/
int timesRotation(int*A, int n){
	int low = 0;
	int high = n-1;
	
	while(low<=high){

		if(A[low] <= A[high])
			return low;

		int mid = (low+high)/2;
		/*
		you have to use module in case that the index is the last one
		*/ 
		int next = (mid+1)%n;
		int prev = (mid+n-1)%n;

		if(A[mid]<=A[next] && A[mid]<=A[prev])
			return mid;
		else if(A[mid] >= A[high])
			low = mid+1;
		else
			high = mid-1;
		}
		return -1;	
}

int BScircularSort(int* A, int n, int x){
	int low = 0;
	int high = n-1;

	while(low<=high){
		int mid =(low+high)/2;
		
		if(A[mid] == x)
			return mid;
		//right half sorted
		if(A[mid] <= A[high]){
			if(x > A[mid] && x <= A[high])
				low = mid+1;
			else
				high = mid-1;
		}
		//left half sorted
		else if(A[low] <= A[mid]){
			if(x < A[mid] && x >= A[low])
				high = mid-1;
			else
				low = mid+1;
		}
	}
	return -1;
}	

int main(){
	int A[10] = {2,6,13,21,21,21,63,81,97,100};
	int B[8] = {11,12,15,18,2,5,6,8};
	int C[8] = {5,6,8,11,12,15,18,2};
	int D[8] = {2,5,6,8,11,12,15,18};

	if(linearS(A, 10, 81))
		cout << "in the array usign linearS" << endl;

	if(binaryS(A, 10, 21))
		cout << "in the array usign binaryS" << endl;

	if(binaryS2(A, 0, 9, 21))
		cout << "in the array usign binaryS" << endl;

	int x = findFirstE(A, 10, 21);
	cout << x << endl;
	int y = findLastE(A, 10, 21);
	cout << y << endl;
	int z = linearCount(A, 10, 21);
	cout << z << endl;
	int z2 = binaryCount(A, 10, 21);
	cout << z2 << endl;
	int z3 = timesRotation(C, 8);
	cout << z3 <<endl;
	int z4 = BScircularSort(B, 8, 11);
	cout << z4 <<endl;
}