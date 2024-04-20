/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/04/20 18:31:15 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP

#include <cstdlib>
#include <iostream>

class ClapTrap {
private:
  std::string name;
  long long   hp;
  long long   ep;
  long long   ad;

public:
  ClapTrap    (std::string& name);
  ~ClapTrap   ( void );

  void        attack( const std::string& target );
  void        takeDamage( unsigned int amount );
  void        beRepaired( unsigned int amount );
};

#endif
