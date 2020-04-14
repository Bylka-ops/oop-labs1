#pragma once
#include <iostream>

using namespace std;

class Array
{
private:
	int *mas;
	int count;
	void quickSort(int *numbers, int left, int right);
public:
	class size
	{

	};
	class Delete
	{

	};
	class input
	{

	};
	class memory
	{

	};
	Array();
	void add_array(int new_size);
	void delete_array(int new_size);
	void find_array(int new_size);
	void set_array();
	void get_array();
	void sort();
	~Array();

private:

};

Array::Array()
{
	cout<<"enter size array"<<endl;
	if (!(cin >> count))
		throw input();
	mas = new int[count];


}

void Array::add_array(int new_mas)
{
	
	int *mas1 = new int[count];
	for (int i = 0; i < count; i++)
	{
		mas1[i] = mas[i];
	}
	delete mas;	
	count++;
	mas = new int[count];
	for (int i = 0; i < count; i++)
	{
		mas[i] = mas1[i];
	}
	delete mas1;
	mas[count - 1] = new_mas;
}
void Array::find_array(int new_mas)
{
	bool flag = false;
	for (int i = 0; i < count; i++)
	{
		if (mas[i] == new_mas)
			flag = true;
	}
	if (flag == true)
		cout << "yes" << endl;
	else 
		cout << "no" << endl;
}

void Array::delete_array(int new_mas)
{
	if (new_mas>count)
	{
		throw Delete();
	}
	else
	{
		if (new_mas == count)
			count--;
		else
		{
			int* mas1 = new int[count - 1];
			int k = 0;
			for (int i = 0; i < count; i++)
			{
				if (new_mas - 1 == i)
					i++;
				mas1[k] = mas[i];
				k++;
			}
			count--;
			for (int i = 0; i < count; i++)
			{
				mas[i] = mas1[i];
			}
			delete[] mas1;
		}
	}
}

void Array::quickSort(int *numbers, int left, int right)
{
	int pivot; 
	int l_hold = left; 
	int r_hold = right; 
	pivot = numbers[left];
	while (left < right) 
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; 
		if (left != right) 
		{
			numbers[left] = numbers[right]; 
			left++; 
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; 
		if (left != right) 
		{
			numbers[right] = numbers[left]; 
			right--; 
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) 
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}

void Array::set_array()
{
	for (int i = 0; i < count; i++)
	{
		mas[i] = rand()%10;
	}
}

void Array::get_array()
{
	for (int i = 0; i < count; i++)
	{
		cout << mas[i] << " ";
	}
}
void Array::sort()
{
	if (count==0)
		throw size();
	quickSort(mas, 0, count - 1);
}

Array::~Array()
{
	if (!mas)
		throw memory();
	delete[] mas;
}