/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/04/22 17:13:56 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
ClapTrap() {
  guardGateMode = false;
  this->hp = 100;
  this->ep = 50;
  this->ad = 20;
  std::cout << "\e[1;92mScavTrap default constructor called\e[0m" << std::endl
            << "ScavTrap \e[1;96m" << name << "\e[0m status" << std::endl
            << "hp = " << hp << std::endl
            << "ep = " << ep << std::endl
            << "ad = " << ad << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) :
ClapTrap() {
  *this = obj;
  std::cout << "\e[1;92mScavTrap copy constructor called\e[0m" << std::endl
            << "ScavTrap \e[1;96m" << name << "\e[0m status" << std::endl
            << "hp = " << hp << std::endl
            << "ep = " << ep << std::endl
            << "ad = " << ad << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) :
ClapTrap(name) {
  guardGateMode = false;
  this->hp = 100;
  this->ep = 50;
  this->ad = 20;
  std::cout << "\e[1;92mScavTrap constructor called\e[0m" << std::endl
            << "ScavTrap \e[1;96m" << name << "\e[0m status" << std::endl
            << "hp = " << hp << std::endl
            << "ep = " << ep << std::endl
            << "ad = " << ad << std::endl;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap \e[1;96m" << name << " \e[0m"
            << "> byebye~" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
  if (this != &obj) {
    this->name = obj.name;
    this->hp = obj.hp;
    this->ep = obj.ep;
    this->ad = obj.ad;
  }
  else
    std::cout << "\e[1;31mScavTrap Error: "
              << "Attempted self-assignment in copy assignment operator"
              << "\e[0m"
              << std::endl;
  return *this;
}

void ScavTrap::attack(const std::string& target) {
  if (hp == 0)
    std::cout << "\e[1;91mScavTrap " << name << " has no hit points.\e[0m"
              << std::endl;
  else if (ep == 0)
    std::cout << "\e[1;91mScavTrap : No energy points.\e[0m" << std::endl;
  else {
  ep--;
  std::cout << "ScavTrap \e[1;96m" << name << "\e[0m attacks \e[1;95m"
            << target << "\e[0m, causing \e[1;31m"
            << ad << "\e[0m points of damage." << std::endl;
  }
}

void ScavTrap::beRepaired(unsigned int amount) {
  if (ep > 0 && hp > 0 && hp + amount <= 100)
  {
    std::cout << "\e[1;96m" << name << "\e[0m repaired itself and "
              << "recovered \e[1;92m" << amount << "\e[0m points."
              << std::endl;
    hp += amount;
    ep--;
  } else if (ep == 0)
    std::cout << "\e[1;91mNo energy points.\e[0m" << std::endl;
  else if (hp == 0)
    std::cout << "\e[1;91m" << name << " has no hit points.\e[0m"
              << std::endl;
  else
    std::cout << "\e[1;96m" << name << "\e[0m cannot be a hit point"
              << " greater than\e[1;92m 100 \e[0mpoints." << std::endl;
}

void ScavTrap::guardGate(void) {
  if (guardGateMode) {
    guardGateMode = false;
    std::cout << "\e[1;91mScavTrap is already in gatekeeper mode.\e[0m"
              << std::endl;
    return ;
  }
  guardGateMode = true;
  std::cout << "\e[1;93mScavTrap is now in gatekeeper mode.\e[0m"
            << std::endl;
}
