#!/bin/bash
echo "1.Your os version, release number, kernel version:"
lsb_release -a
echo "2.All available shells:"
cat /etc/shells
echo "3.Computer CPU information like processor type, CPU,etc"
lscpu
echo "4.memory information:"
free -m
echo "5.Harddisk information"
lsblk|grep sda
echo "6.File system(mounted)"
df -h
