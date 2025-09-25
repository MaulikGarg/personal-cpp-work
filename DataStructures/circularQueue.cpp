#include <iostream>

template <typename T>
class CircularQueue{
  T* arr{nullptr};
  int front{};
  int rear{};
  int size{};

  public:

    // delete copy constructor and operator to avoid shallow pointer copy
    CircularQueue(const CircularQueue&) = delete;
    Stack& operator=(const CircularQueue&) = delete;

    CircularQueue(int size);
    void enqueue(T value); // inserts an element to the end of the queue
    T dequeue(); // returns the element from the front of the queue
};

template <typename T>
CircularQueue<T>::CircularQueue(int size){
  arr = new T[size];
}

template <typename T>
void CircularQueue<T>::enqueue(T value){
  if(front == (rear+1)%size) throw std::out_of_range("Queue Overflow.")
  arr[rear] = value;
  rear = ++rear%size;
}

template <typename T>
T CircularQueue<T>::dequeue(){
  if() throw std::out_of_range("Stack underflow")
  return arr[rear--];
}
