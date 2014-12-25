/* 
 * File:   Messenger.cpp
 * Author: JoPe
 * 
 * Created on 15 de diciembre de 2014, 23:25
 */

#include "Messenger.hpp"

#include <algorithm>

namespace msg
{
  void Messenger::Post(Filter c_filter, Message c_message) // May throw (basic)
  {
    Entry filter = {c_filter,std::make_unique<std::queue<Message>>()};
    auto filteredQueues = 
      std::equal_range(std::begin(m_queues), std::end(m_queues), filter,
            [](Entry const& lhs, Entry const& rhs)
            { return lhs.first < rhs.first; });

    for (auto it = filteredQueues.first; it != filteredQueues.second; ++it)
    {
      it->second->push(c_message);
    }
  }
  
  Dequeueer Messenger::Register(Filter c_filter) // May throw (basic)
  {
    m_queues.push_back({c_filter,std::make_unique<std::queue<Message>>()});
    Dequeueer dequeueer {*(m_queues.back().second)};
    std::sort(std::begin(m_queues),std::end(m_queues),
            [](Entry const& lhs, Entry const& rhs)
            { return lhs.first < rhs.first; });
    return dequeueer;
  }
}