template <typename T>
class Stack {
  int m_size{};
  T* m_arrStart{nullptr};
  int m_top{-1};

 public:
  // deleted functions & operators
  Stack(const Stack&) = delete;
  Stack& operator=(const Stack&) = delete;

  Stack(int size) : m_size{size}, m_arrStart { new T[m_size] } {}

  ~Stack() { delete[] m_arrStart;}

  void push(const T& data){
    if(m_top == m_size-1) throw std::out_of_range("Exception: stack overflow.");
    m_arrStart[++m_top] = data;
  }

  T pop(){
    if(m_top < 0) throw std::out_of_range("Stack Underflow.");
    T temp = m_arrStart[m_top];
    m_top--;
    return temp;
  }

  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const Stack<U>& stk){
    int temp {stk.m_top};
    while (temp >= 0)
    {
      os << stk.m_arrStart[temp--] << " <- ";
    }
    os << "bottom\n";
    return os;
  }
};
