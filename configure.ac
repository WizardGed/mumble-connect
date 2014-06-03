# Mumble-Connect: Connects to mumble servers while using minimal resources 
# Copyright (C) 2014  William A. Kennington III
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

AC_PREREQ([2.64])
AC_INIT([mumble-connect],
		[0.1.0],
		[https://github.com/wkennington/mumble-connect],
		[mumble-connect],
		[william@wkennington.com])

AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([1.11 foreign -Wall -Werror silent-rules subdir-objects check-news])
AM_SILENT_RULES([yes])

LT_PREREQ([2.2])
LT_INIT

AC_PROG_CC_C99
AM_PROG_CC_C_O

AC_CONFIG_FILES([
	Makefile
	src/Makefile
])
AC_OUTPUT
