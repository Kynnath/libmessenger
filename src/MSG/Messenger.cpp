/* 
 * File:   Messenger.cpp
 * Author: JoPe
 * 
 * Created on 15 de diciembre de 2014, 23:25
 */

#include "Messenger.hpp"

namespace msg
{
  void Messenger::Post(Message message)
  {
    m_queue.PushBack(message);
  }
  
  QueueHandle Messenger::Register(Filter /*filter*/)
  {
    return &m_queue;
  }
}