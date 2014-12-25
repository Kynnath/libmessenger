/* 
 * File:   Queue.hpp
 * Author: JoPe
 *
 * Created on 15 de diciembre de 2014, 23:29
 */

#ifndef QUEUE_HPP
#define	QUEUE_HPP

#include <queue>
#include "Message.hpp"

namespace msg
{
  class Dequeueer
  {
    std::queue<Message>& r_queue;
    public:
      Dequeueer(std::queue<Message>& i_queue) noexcept: r_queue(i_queue){} 
      Message & Front() { return r_queue.front(); } // No throw. Undefined if Empty
      Message const& Front() const { return r_queue.front(); } // No throw. Undefined if Empty
      void Pop() { r_queue.pop(); } // No throw. Undefined if Empty
      bool IsEmpty() const noexcept { return r_queue.empty(); }
  };
}

#endif	/* QUEUE_HPP */

