# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Générateur_de_plateaux.perl                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 10:50:18 by asaadi--          #+#    #+#              #
#    Updated: 2024/10/08 10:57:13 by asaadi--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Command to run the file: perl ./Générateur_de_plateaux.pl 10 <number of lines> <number of row> <number for the density of o>

#!/usr/bin/perl

use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print "o";
		}
		else {
			print ".";
		}
	}
	print "\n";
}