/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/04/20 20:55:24 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <sys/ioctl.h>
#include <unistd.h>

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
  ClapTrap human1("yamada");
  ClapTrap human2("yayamada");
  ClapTrap human3;

  human1.attack("yayamada");
  human2.takeDamage(10);
  human1.takeDamage(5);
  human2.beRepaired(10);
  human1.beRepaired(6);
  human1.beRepaired(3);

  ClapTrap human4(human1);
  human4.beRepaired(2);
  human4.beRepaired(3);
  human1.beRepaired(1);
  draw_terminal_line();
  return (EXIT_SUCCESS);
}
