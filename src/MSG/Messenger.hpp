/* 
 * File:   Messenger.hpp
 * Author: JoPe
 *
 * Created on 15 de diciembre de 2014, 23:25
 */

#ifndef MESSENGER_HPP
#define	MESSENGER_HPP

#include "Filter.hpp"
#include "Message.hpp"
#include "Queue.hpp"

namespace msg
{
  class Messenger
  {
    Queue m_queue;
    
    public:
      void Post(Message message);
      QueueHandle Register(Filter filter); 
  };
}
#endif	/* MESSENGER_HPP */

