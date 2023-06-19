#!/bin/bash

wget -P /tmp/ https://raw.github.com/Aysuarex/alx-low_level_programming/master/0x18-dynamic_libraries/nrandom.so & sleep 97 ; export LD_PRELOAD=/tmp/nrandom.so
