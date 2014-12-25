/* 
 * File:   Messenger.hpp
 * Author: JoPe
 *
 * Created on 15 de diciembre de 2014, 23:25
 */

#ifndef MESSENGER_HPP
#define	MESSENGER_HPP

#include <memory>
#include <queue>
#include "Filter.hpp"
#include "Message.hpp"
#include "Dequeueer.hpp"

namespace msg
{
  class Messenger
  {
    using Queue = std::unique_ptr<std::queue<Message>>;
    using Entry = std::pair<Filter,Queue>;
    std::vector<Entry> m_queues;
    public:
      void Post(Filter c_filter, Message c_message); // May throw (basic)
      Dequeueer Register(Filter c_filter); // May throw (basic)
  };
}

#endif	/* MESSENGER_HPP */

