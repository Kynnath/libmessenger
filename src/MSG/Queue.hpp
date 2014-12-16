/* 
 * File:   Queue.hpp
 * Author: JoPe
 *
 * Created on 15 de diciembre de 2014, 23:29
 */

#ifndef QUEUE_HPP
#define	QUEUE_HPP

#include <vector>
#include "Message.hpp"

namespace msg
{
  class Queue 
  {
    std::vector<Message> m_queue;
    int m_front;
    int m_back;
    
    public:
      Queue();
      void PushBack(Message message);
      Message GetMessage();
      bool IsEmpty() const;
  };
  
  typedef Queue* QueueHandle;
}
#endif	/* QUEUE_HPP */

