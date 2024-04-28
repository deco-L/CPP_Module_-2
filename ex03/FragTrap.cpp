/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/04/28 23:21:28 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) :
ClapTrap() {
  this->hp = 100;
  this->ep = 100;
  this->ad = 30;
  std::cout << "\e[1;92mFragTrap default constructor called\e[0m" << std::endl
            << "FragTrap \e[1;96m" << name << "\e[0m status" << std::endl
            << "hp = " << hp << std::endl
            << "ep = " << ep << std::endl
            << "ad = " << ad << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) :
ClapTrap() {
 *this = obj;
  std::cout << "\e[1;92mFragTrap copy constructor called\e[0m" << std::endl
            << "FragTrap \e[1;96m" << name << "\e[0m status" << std::endl
            << "hp = " << hp << std::endl
            << "ep = " << ep << std::endl
            << "ad = " << ad << std::endl;
}

FragTrap::FragTrap(const std::string& name) :
ClapTrap(name) {
  this->hp = 100;
  this->ep = 100;
  this->ad = 30;
  std::cout << "\e[1;92mFragTrap constructor called\e[0m" << std::endl
            << "FragTrap \e[1;96m" << name << "\e[0m status" << std::endl
            << "hp = " << hp << std::endl
            << "ep = " << ep << std::endl
            << "ad = " << ad << std::endl;
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap \e[1;96m" << name << " \e[0m"
            << "> byebye~" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
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

void FragTrap::beRepaired(unsigned int amount) {
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

void FragTrap::highFiveGuys(void) {
  std::cout << "\e[1;96m" << name << "\e[0m > High five! Let's do it!"
  << std::endl;
}
