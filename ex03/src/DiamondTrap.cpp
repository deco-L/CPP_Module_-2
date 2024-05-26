/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/04/28 23:46:03 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) :
ClapTrap("none_clap_name") {
  this->name ="none";
  this->hp = FragTrap::hp;
  this->ep = ScavTrap::ep;
  this->ad = FragTrap::ad;
  std::cout << "\e[1;92mDiamondTrap default constructor called\e[0m" << std::endl
            << "DiamondTrap \e[1;96m" << name << "\e[0m status" << std::endl
            << "hp = " << hp << std::endl
            << "ep = " << ep << std::endl
            << "ad = " << ad << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) :
ClapTrap(obj), ScavTrap(obj), FragTrap(obj), name(obj.name) {
  *this = obj;
  std::cout << "\e[1;92mDiamondTrap copy constructor called\e[0m" << std::endl
            << "DiamondTrap \e[1;96m" << name << "\e[0m status" << std::endl
            << "hp = " << hp << std::endl
            << "ep = " << ep << std::endl
            << "ad = " << ad << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :
ClapTrap(name + "_clap_name") {
  this->name = name;
  this->hp = FragTrap::hp;
  this->ep = ScavTrap::ep;
  this->ad = FragTrap::ad;
  std::cout << "\e[1;92mDiamondTrap constructor called\e[0m" << std::endl
            << "DiamondTrap \e[1;96m" << name << "\e[0m status" << std::endl
            << "hp = " << hp << std::endl
            << "ep = " << ep << std::endl
            << "ad = " << ad << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
  if (this != &obj) {
    this->name = obj.name;
    this->hp = obj.hp;
    this->ep = obj.ep;
    this->ad = obj.ad;
  }
  else
    std::cout << "\e[1;31mFragTrap Error: "
              << "Attempted self-assignment in copy assignment operator"
              << "\e[0m"
              << std::endl;
  return *this;
}

void  DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void  DiamondTrap::beRepaired( unsigned int amount ) {
  FragTrap::beRepaired(amount);
}

void  DiamondTrap::whoAmI(void) {
  std::cout << "DiamondTrap \e[1;96m" << this->name << "\e[0m" <<std::endl
            << "ClapTrap \e[1;96m" << ClapTrap::name << "\e[0m" << std::endl;
}
