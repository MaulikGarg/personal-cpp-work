#include <iostream>

template <typename T>
class CircularQueue{
  T* m_arr{nullptr};
  int m_front{};
  int m_rear{};
  int m_size{};

  public:

    // delete copy constructor and operator to avoid shallow pointer copy
    CircularQueue(const CircularQueue&) = delete;
    CircularQueue& operator=(const CircularQueue&) = delete;

    CircularQueue(int m_size);
    ~CircularQueue() {delete[] m_arr; }
    void enqueue(T value); // inserts an element to the end of the queue
    T dequeue(); // returns the element from the m_front of the queue

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const CircularQueue<U>& queue);
};

template <typename T>
CircularQueue<T>::CircularQueue(int m_size){
  m_arr = new T[m_size];
}

template <typename T>
void CircularQueue<T>::enqueue(T value){
  if(m_front == (m_rear+1)%m_size) throw std::out_of_range("Queue Overflow.");
  m_arr[m_rear] = value;
  m_rear = ++m_rear%m_size;
}

template <typename T>
T CircularQueue<T>::dequeue(){
  if(m_front == m_rear) throw std::out_of_range("Stack underflow");
  T value = m_arr[m_front];
  m_front = (m_front+1)%m_size;
  return value;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const CircularQueue<U>& queue){

}
