/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/04/21 17:49:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
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
