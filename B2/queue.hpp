#ifndef QUEUE_HPP
#define QUEUE_HPP


#include <deque>
#include <iostream>
#include <list>

template<typename T>
class QueueWithPriority
{
  public:
  enum ElementPriority
  {
    LOW,
    NORMAL,
    HIGH
  };

  virtual ~QueueWithPriority() = default;

  bool operator==(const QueueWithPriority &other) const;

  bool operator!=(const QueueWithPriority &other) const;

  void PutElementToQueue(const T &element, ElementPriority priority);

  T GetElementFromQueue();

  void Accelerate();

  bool empty();

  void print();

  private:
  std::deque<T> queue;
  unsigned int highCounter = 0;
  unsigned int lowCounter = 0;
  unsigned int getCounter = 0;
};

template<typename T>
bool QueueWithPriority<T>::operator==(const QueueWithPriority &other) const
{
  return (queue == other.queue);
}

template<typename T>
bool QueueWithPriority<T>::operator!=(const QueueWithPriority &other) const
{
  return !(queue == other.queue);
}

template<typename T>
void QueueWithPriority<T>::PutElementToQueue(const T &element, ElementPriority priority)
{
  switch (priority)
  {
    case ElementPriority::HIGH:
      queue.insert(queue.begin() + highCounter, element);
      ++highCounter;
      break;
    case ElementPriority::NORMAL:
      queue.insert(queue.end() - lowCounter, element);
      break;
    case ElementPriority::LOW:
      ++lowCounter;
      queue.push_back(element);
      break;
  }
}

template<typename T>
void QueueWithPriority<T>::print()
{
  for (auto i : queue)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';
}

template<typename T>
void QueueWithPriority<T>::Accelerate()
{
  queue.insert(queue.begin() + highCounter, queue.end() - lowCounter, queue.end());

  queue.erase(queue.end() - lowCounter, queue.end());
}

template<typename T>
T QueueWithPriority<T>::GetElementFromQueue()
{
  return queue.at(getCounter++);
}

template<typename T>
bool QueueWithPriority<T>::empty()
{
  return (queue.empty() || getCounter == queue.size());
}

#endif
