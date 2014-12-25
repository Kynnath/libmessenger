/* 
 * File:   Filter.hpp
 * Author: JoPe
 *
 * Created on 15 de diciembre de 2014, 23:27
 */

#ifndef FILTER_HPP
#define	FILTER_HPP

namespace msg
{
  struct Filter 
  {
    int m_filter;
    
    friend bool operator==(Filter const& lhs, Filter const& rhs) noexcept;
    friend bool operator<(Filter const& lhs, Filter const& rhs) noexcept;
  };
}

#endif	/* FILTER_HPP */

