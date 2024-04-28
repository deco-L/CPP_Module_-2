/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/04/28 18:35:55 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) :
ClapTrap() {
  this->name = this->name + "_clap_name";
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
DiamondTrap() {
  *this = obj;
  *this = obj;
  std::cout << "\e[1;92mDiamondTrap copy constructor called\e[0m" << std::endl
            << "DiamondTrap \e[1;96m" << name << "\e[0m status" << std::endl
            << "hp = " << hp << std::endl
            << "ep = " << ep << std::endl
            << "ad = " << ad << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :
ClapTrap(name) {
  this->name = this->name + "_clap_name";
  this->hp = FragTrap::hp;
  this->ep = ScavTrap::ep;
  this->ad = FragTrap::ad;
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
