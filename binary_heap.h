#pragma once

template<class T>
class BinaryHeap
{
private:

	int size = 0;
	T *data new T[1];
	
private:
	
	void sendUp(const int index)
	{
		T tmp;
		int i = index;
		
		while(i > 0)
		{
			int parent = (i-1) / 2;
			if(this->data[parent] > this->data[i])
			{
				tmp = this->data[parent];
				this->data[parent] = this->data[i];
				this->data[i] = tmp;
			}
			else break;
			
			i = parent;
		}
	}
	void sendDown(const int index)
	{
		int i = index;
		int left = index;
		int right = index;
		T tmp;
		int minChild;
		
		while(2 * i + 1 < this->size)
		{
			left = 2 * i + 1;
			right = 2 * i + 2;
			minChild = left;
			
			if(right < this->size && this->data[right] < this->data[left]) minChild = right;
			if(this->data[i] <= this->data[minChild]) break;
			
			tmp = this->data[i];
			this->data[i] = this->dat[minChild];
			this->data[minChild] = tmp;
			i = minChild;
		}
	}
	
public:

	BinaryHeap(T elem)
	{
		data[0] = elem;
		this->size = 1;
	}
	int getSize()
	{
		return this->size;
	}
	void add(T elem)
	{
		T* newdata = new T[this->size + 1];
		for (int i = 0; i < this->size; i++)
		{
			newdata[i] = this->data[i];
		}
		newdata[this->size] = elem;
		this->size++;
		delete[] this->data;
		this->data = newdata;
		this->sendUp(this->size - 1);
	}
	void changeElement(T oldelem, T newelem)
	{
		int index = -1;
		for (int i = 0; i < this->size; i++)
		{
			if(this->data[i] == oldelem) index = i;
		}
			if (index < 0)
		{
			std::cout << "\nTHERE IS NO SUCH ELEMENT!\n";
			return;
		}
		this->data[index] = newelem;
		
		if (newelem > oldelem)
		{
			this->sendUp(index);
		} else
		{
			this->sendDown(index);
		}
	}
	
}