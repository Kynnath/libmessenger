/* 
 * File:   Filter.cpp
 * Author: JoPe
 * 
 * Created on 15 de diciembre de 2014, 23:27
 */

#include "Filter.hpp"

namespace msg
{
  bool operator==(Filter const& lhs, Filter const& rhs) noexcept
  {
    return lhs.m_filter == rhs.m_filter;
  }
  
  bool operator<(Filter const& lhs, Filter const& rhs) noexcept
  {
    return lhs.m_filter < rhs.m_filter;
  }
}