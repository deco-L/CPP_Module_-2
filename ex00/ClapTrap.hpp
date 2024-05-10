/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/04/21 15:13:55 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <cstdlib>
#include <iostream>

class ClapTrap {
private:
  std::string name;
  long long   hp;
  long long   ep;
  long long   ad;

public:
  ClapTrap( void );
  ClapTrap( const ClapTrap& obj );
  ClapTrap( const std::string& name );
  ~ClapTrap( void );

  void        attack( const std::string& target );
  void        takeDamage( unsigned int amount );
  void        beRepaired( unsigned int amount );

  ClapTrap&   operator=(const ClapTrap& obj);
};

#endif
