/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/04/26 12:43:07 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap :
public ScavTrap, public FragTrap {
private:
  std::string   name;

public:
  DiamondTrap( void );
  DiamondTrap( const DiamondTrap& obj );
  DiamondTrap( const std::string& name );

  void  whoAmI( void );

  DiamondTrap& operator=( const DiamondTrap& obj );
};

#endif
