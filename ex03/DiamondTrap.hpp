/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/05/18 18:08:52 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap :
public ScavTrap, public FragTrap
{
private:
  std::string   name;

public:
  DiamondTrap( void );
  DiamondTrap( const DiamondTrap& obj );
  DiamondTrap( const std::string& name );

  void  attack( const std::string& target );
  void  beRepaired( unsigned int amount );
  void  whoAmI( void );

  DiamondTrap& operator=( const DiamondTrap& obj );
};

#endif
