#!/bin/bash

sudo losetup /dev/loop0 floppy.img
sudo mount /dev/loop0 /mnt/dsd
sudo cp ../build/kernel /mnt/dsd/kernel
sudo umount /dev/loop0
sudo losetup -d /dev/loop0
