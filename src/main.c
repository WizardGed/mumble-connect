/**
 * Mumble-Connect: Connects to mumble servers while using minimal resources 
 * Copyright (C) 2014  William A. Kennington III
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

static const int default_connections = 1;
static const char default_user[] = "MC#";

static const char opts[] = "hn:u:";
static const struct option long_opts[] = {
	{
		.name = "help",
		.has_arg = no_argument,
		.flag = NULL,
		.val = 'h'
	},
	{
		.name = "connections",
		.has_arg = required_argument,
		.flag = NULL,
		.val = 'n'
	},
	{
		.name = "user",
		.has_arg = required_argument,
		.flag = NULL,
		.val = 'u'
	},
	NULL
};

int main(int argc, char *argv[])
{
	int opt_ret, main_ret = EXIT_FAILURE;
	int connections = default_connections;
	const char *user = default_user;

	while ((opt_ret = getopt_long(argc, argv, opts, long_opts, NULL)) != -1) {
		switch (opt_ret) {
			case 'u':
				user = optarg;
				break;
			case 'n':
				connections = atoi(optarg);
				if (connections < 1) {
					fprintf(stderr, "The number of connections must be positive\n\n");
					goto main_print_help;
				}
				break;
			case 'h':
			default:
				goto main_print_help;
		}
	}
	argv += optind;
	argc -= optind;

	// We must have a username containing # when dealing with multiple conns
	if (connections > 1) {
		size_t i = 0;
		for (; user[i] != 0 && user[i] != '#'; ++i);
		if (user[i] == 0) {
			fprintf(stderr, "The username must contain a pound sign when "
					"performing multiple connections\n\n");
			goto main_print_help;
		}
	}

	// We require a hostname for the mumble server
	if (argc != 1) {
		fprintf(stderr, "You must pass a single hostname to connect\n\n");
		goto main_print_help;
	}

	printf("Not implemented yet\n");
	main_ret = EXIT_SUCCESS;
	goto main_cleanup;

main_print_help:
	fprintf(stderr, "Usage: mumble-connect [OPTION] HOST\n");
	fprintf(stderr, "Example: mumble-connect -n hello# example.com\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "Options:\n");
	fprintf(stderr, "  -h, --help                 "
			"Displays this help text\n");
	fprintf(stderr, "  -n, --connections=COUNT    "
			"The number of connections to make to the mumble server\n");
	fprintf(stderr, "  -u, --user=USER%           "
			"The username to connect with. Pound signs get substituted with a number "
			"based on how many connections are made\n");
main_cleanup:
	return main_ret;
}
