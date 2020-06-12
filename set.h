#pragma once

template <class T>
class Set
{
private:

	BinaryHeap<T>* set;
	
public:
	Set(const T elem)
	{
		this->set = new BinaryHeap<T>(elem);
	}
	~Set() = default;
	void add(const T elem)
	{
		if(this->exist(elem) == true)
		{
			return;
		}
		this->set->add(elem);
	}
	bool exist(const T elem) const
	{
		return this->set->exist(elem);
	}
	void erase(const T elem)
	{
		if(this->exist(elem) == true)
		{
			this->set->erase(elem);
		}
	}
	void show() const
	{
		this->set->printAll();
	}
	int getSize()
	{
		return this->set->getSize();
	}
};