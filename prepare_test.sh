#!/bin/bash -ue

#-------------------------------------------------------------------------------
#
# Prepare test script
#
# Copyright (C) 2020, Hensoldt Cyber GmbH
#
#-------------------------------------------------------------------------------


#-------------------------------------------------------------------------------
#-------------------------------------------------------------------------------
#-------------------------------------------------------------------------------
echo "Creating SD card image for QEMU"

# create a file that can be provided to QEMU as a backend for the SD card
# emulation. The size is arbitrary and should mainly provide enough space to run
# the current tests. The filename needs to fit what PyTest will search for in
# the test execution folder to verify if QEMU should be run with the
# specific SD card options.
truncate -s 8GB sdcard.img
