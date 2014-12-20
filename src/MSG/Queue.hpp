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
  
  struct ReadQueue
    : private Queue
  {
    Message GetMessage(){return Queue::GetMessage();}
    bool IsEmpty() const{return Queue::IsEmpty();}
  };
  
  struct WriteQueue
    : private Queue
  {
    void PushBack(Message message){Queue::PushBack(message);}
  };
  
  typedef ReadQueue* QueueHandle;
}
#endif	/* QUEUE_HPP */

