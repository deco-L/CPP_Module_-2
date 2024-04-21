/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/04/20 20:58:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
name("none"), hp(10), ep(10), ad(0) {
  std::cout << "\e[1;92mClapTrap default constructor called\e[0m" << std::endl
            << "ClapTrap \e[1;96m" << name << "\e[0m status" << std::endl
            << "hp = " << hp << std::endl
            << "ep = " << ep << std::endl
            << "ad = " << ad << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) {
  *this = obj;
  std::cout << "\e[1;92mClapTrap copy constructor called\e[0m" << std::endl
            << "ClapTrap \e[1;96m" << name << "\e[0m status" << std::endl
            << "hp = " << hp << std::endl
            << "ep = " << ep << std::endl
            << "ad = " << ad << std::endl;
}

ClapTrap::ClapTrap(const std::string& name):
name(name), hp(10), ep(10), ad(0) {
  std::cout << "\e[1;92mClapTrap constructor called\e[0m" << std::endl
            << "ClapTrap \e[1;96m" << name << "\e[0m status" << std::endl
            << "hp = " << hp << std::endl
            << "ep = " << ep << std::endl
            << "ad = " << ad << std::endl;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "\e[1;96m" << name << " \e[0m"
            << "> byebye~" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
  if (this != &obj) {
    this->name = obj.name;
    this->hp = obj.hp;
    this->ep = obj.ep;
    this->ad = obj.ad;
  }
  else
    std::cout << "\e[1;31mError: "
              << "Attempted self-assignment in copy assignment operator"
              << "\e[0m"
              << std::endl;
  return *this;
}

void ClapTrap::attack(const std::string& target) {
  if (hp == 0)
    std::cout << "\e[1;91mClapTrap " << name << " has no hit points.\e[0m"
              << std::endl;
  else if (ep == 0)
    std::cout << "\e[1;91mNo energy points.\e[0m" << std::endl;
  else {
  ep--;
  std::cout << "ClapTrap \e[1;96m" << name << "\e[0m attacks \e[1;95m"
            << target << "\e[0m, causing \e[1;31m"
            << ad << "\e[0m points of damage." << std::endl;
  }
};

void ClapTrap::takeDamage(unsigned int amount) {
  if (hp == 0)
    std::cout << "\e[1;91mClapTrap " << name << " has no hit points.\e[0m"
              << std::endl;
  else if (hp <= amount)
    hp = 0;
  else
    hp -= amount;
  std::cout << "ClapTrap \e[1;96m" << name << "\e[0m takes \e[1;31m"
            << amount << "\e[0m damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (ep > 0 && hp > 0 && hp + amount <= 10)
  {
    std::cout << "ClapTrap \e[1;96m" << name << "\e[0m repaired itself and "
              << "recovered \e[1;92m" << amount << "\e[0m points."
              << std::endl;
    hp += amount;
    ep--;
  } else if (ep == 0)
    std::cout << "\e[1;91mNo energy points.\e[0m" << std::endl;
  else if (hp == 0)
    std::cout << "\e[1;91mClapTrap " << name << " has no hit points.\e[0m"
              << std::endl;
  else
    std::cout << "ClapTrap \e[1;96m" << name << "\e[0m cannot be a hit point"
              << " greater than\e[1;92m 10 \e[0mpoints." << std::endl;
}
