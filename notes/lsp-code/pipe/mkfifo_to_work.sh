#!/bin/bash

echo "Hello"
cd ~ && sudo umount /mnt/d
sudo mount -t drvfs D:\\ /mnt/d -o metadata

