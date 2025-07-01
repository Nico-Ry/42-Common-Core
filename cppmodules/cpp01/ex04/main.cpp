/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:46:38 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:46:38 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static void ft_replace(std::string& str, const char *str1, const char *str2);

int main(int argc, char **argv)
{
	std::ifstream   infile;
	std::ofstream   outfile;
	std::string     outname;
	std::string     str;

	if (argc != 4) {
		std::cout << "Error arguments. Usage: ./replace <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	infile.open(argv[1]);
	if (!infile.is_open()) {
		std::cout << "Error opening '" << argv[1] << "'" << std::endl;
		return (2);
	}
	outname.assign(argv[1]);
	outname += ".replace";
	outfile.open(outname.c_str());
	if (!outfile.is_open()) {
		std::cout << "Error opening / creating '" << outname << "'" << std::endl;
		return (3);
	}
	str.assign((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
	infile.close();
	if (*argv[2] != '\0') {
		ft_replace(str, argv[2], argv[3]);
	}
	outfile << str;
	outfile.close();
	return (0);
}

static void ft_replace(std::string& str, const char *str1, const char *str2)
{
	std::string s1(str1);
	std::string s2(str2);
	size_t      pos = 0;

	while ((pos = str.find(s1, pos)) != std::string::npos) {
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos += s2.length();
	}
}
