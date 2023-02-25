#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void Print(); 

private:
  /// Add whatever helper functions and data members you need below
  int m_;
  std::vector<T> v_;
  PComparator c_;
  void exchangepos(unsigned int origin, unsigned int target);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c):
m_(m), c_(c)
{}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{}

template <typename T, typename PComparator>
void Heap<T,PComparator>::exchangepos(unsigned int origin,unsigned int target)
{
  if (origin >= v_.size() || target >= v_.size())
  {
    throw std::underflow_error("exchange out of range");
  }
  T temp =  v_[origin];
  v_[origin] = v_[target];
  v_[target] = temp;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  v_.push_back(item);
  int position = v_.size() - 1;
  while (position != 0)
  {
    int parentpos;
    if (position % m_ == 0)
    {
      parentpos = position/m_ -1;
    }
    else
    {
      parentpos = position/m_;
    }
    if (c_(item, v_[parentpos]))
    {
      T temp =  v_[parentpos];
       v_[parentpos] = item;
       v_[position] = temp;
      position = parentpos;
    }
    else
    {
      return;
    }
  }
}
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("the heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return v_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("the heap is empty");
  }

  // pop the front data
  if (size() > 1)
  {
    exchangepos(0, size()-1);
    v_.pop_back();
  }
  else {
    v_.pop_back();
    return;
  }
  unsigned int position = 0;
  T item = v_[0];
  while(true)
  {
    // check each child if have child 
    int maxchildpos = -1;
    for (int i = 0; i < m_; i++)
    {
      unsigned int childpos = m_*position + 1 + i;
      if (childpos >= size())
      {
        break;
      }
      if (c_(v_[childpos], item))
      {
        if (maxchildpos != -1)
        {
          if(c_(v_[childpos], v_[maxchildpos]))
          {
            //std::cout << v_[childpos] <<">"<<v_[maxchildpos]<<std::endl;
            maxchildpos = childpos; //update the one to exchange
          }
        }
        else 
        {
          maxchildpos = childpos;
        }
      }
    }
    if (maxchildpos == -1)//no need to switch
    {
      return;
    }
    else 
    {
      exchangepos(maxchildpos,position);
      position = maxchildpos;
    }
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return v_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return v_.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::Print() 
{
  size_t s = this->size();
  for (unsigned int i = 0; i < s; i++)
	{
		std::cout<< this->top() << std::endl;
		this->pop();
	}
}

#endif

