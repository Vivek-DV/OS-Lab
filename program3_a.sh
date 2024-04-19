#!/bin/bash
echo "1.Currently logged user"
whoami
echo "2.Your current shell"
echo $SHELL
echo "3.Your home directory"
echo $HOME
echo "4.Your operating system type"
uname -o
echo "5.Your current path setting"
echo $PATH
echo "6.Your current working directory"
pwd
echo "7.Number of users currrently logged in"
who -q
