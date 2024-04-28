/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/04/28 18:00:17 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
private:
  bool  guardGateMode;

public:
  ScavTrap( void );
  ScavTrap( const ScavTrap& obj );
  ScavTrap( const std::string& name );
  ~ScavTrap( void );

  void  attack( const std::string& target );
  void  beRepaired( unsigned int amount );
  void  guardGate( void );

  ScavTrap& operator=( const ScavTrap& obj );
};

#endif