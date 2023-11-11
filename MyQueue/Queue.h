#pragma once

template <typename T>
class Queue
{
	T* arr;
	int size;
	int count;
public:
	Queue() : size(10), count(0) {
		arr = new T[size];
	}

	Queue(int size) : size(size), count(0) {
		arr = new T[size];
	}

	Queue(const Queue& existQueue) {
		this->size = existQueue.size;
		this->count = existQueue.count;
		this->arr = new T[existQueue.size];
		for (int i = 0; i < existQueue.count; i++) {
			this->arr[i] = existQueue.arr[i];
		}
	}

	~Queue() {
		delete[] arr;
	}

	bool isEmpty() const {
		return (count == 0);
	}

	bool isFull() const {
		return (count == size);
	}

	void push(const T& s) {
		if (isFull()) {
			std::cout << " Queue if full. Push is impossible\n";
		}
		else {
			arr[count++] = s;
		}
	}

	T firstOut() {
		if (isEmpty()) {
			std::cout << " Queue is empty. Nothin to remove\n";
			return NULL;
		}
		else {
			T first = arr[0];
			for (int i = 0; i < count - 1; i++) {
				arr[i] = arr[i + 1];
			}
			count--;
			return first;
		}
	}

	void clear() {
		count = 0;
	}

	void display() const {
		std::cout << "\n  Queue elements:\n";
		std::cout << "  (size " << size << ")\n";
		std::cout << "  (count " << count << ")\n";
		for (int i = 0; i < count; i++) {
			std::cout << "  " << arr[i] << std::endl;
		}
	}

};

