/* 
 * File:   Queue.cpp
 * Author: JoPe
 * 
 * Created on 15 de diciembre de 2014, 23:29
 */

#include "Queue.hpp"

namespace msg
{
  Queue::Queue()
    : m_front()
    , m_back()
  {}
  
  void Queue::PushBack(Message message)
  {
    m_queue.push_back(message);
    ++m_back;
  }
  
  Message Queue::GetMessage()
  {
    return m_queue[static_cast<long long unsigned>(m_front++)];
  }
  
  bool Queue::IsEmpty() const
  {
    return static_cast<long long unsigned>(m_front) == m_queue.size();
  }
}