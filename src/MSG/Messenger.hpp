/*
 * File:   Messenger.hpp
 * Author: JoPe
 *
 * Created on 15 de diciembre de 2014, 23:25
 */

#ifndef MESSENGER_HPP
#define	MESSENGER_HPP

#include <algorithm>
#include <queue>
#include "DGN/Check.hpp"

namespace msg
{
  template <class ...Messages>
  class Messenger
  {
    public:
      void Register(){}
      void Post(){}
      void Deregister(){}
  };

  template <class Message, class ...Messages>
  class Messenger<Message, Messages...>
      : public Messenger<Messages...>
  {
    std::vector<std::queue<Message>*> m_queues;

    public:
      using Messenger<Messages...>::Register;
      using Messenger<Messages...>::Post;
      using Messenger<Messages...>::Deregister;
      void Register(std::queue<Message>& q) { m_queues.push_back(&q); }
      void Post(Message m) { for (auto & queue : m_queues) { queue->push(m); } }
      void Deregister(std::queue<Message> const& q)
      {
        CHECK(m_queues.size() != 0);
        auto queue = std::find(m_queues.begin(),m_queues.end(), &q);
        using std::swap;
        swap(*queue,m_queues.back());
        m_queues.pop_back();
      }
  };
}

#endif	/* MESSENGER_HPP */

