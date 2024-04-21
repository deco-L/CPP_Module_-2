/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/04/21 17:45:23 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <unistd.h>
#include <sys/ioctl.h>

static size_t get_term_line() {
	winsize	terminal_size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal_size);
	return (terminal_size.ws_col);
}

static void draw_terminal_line() {
	size_t	terminal_col;

	terminal_col = get_term_line();
	for (size_t i = 0; i < terminal_col; i++)
		std::cout << "=";
	std::cout << std::endl;
	return ;
}

int main(void) {
  draw_terminal_line();
  ClapTrap  human0("yama");
  ScavTrap  human1("yamada");
  ScavTrap  human2("yayamada");
  ScavTrap  human3("yamamada");

  human0.attack("yamada");
  human1.takeDamage(0);
  human1.attack("yayamada");
  human2.takeDamage(20);
  human3.takeDamage(110);
  human3.beRepaired(100);
  human2.beRepaired(10);
  human1.beRepaired(10);
  human2.guardGate();
  human2.guardGate();
  draw_terminal_line();
  return (EXIT_SUCCESS);
}
