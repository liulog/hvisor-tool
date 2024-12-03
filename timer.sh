#!/bin/bash

insmod hvisor.ko

time_freq=50000000
time_start=$(./gettime)

./hvisor counter clear
cd unixbench-5.1.2
cd ..
./hvisor counter print

time_end=$(./gettime)

# 输出捕获的值, time_h 是人类可读的时间
time=`expr $time_end - $time_start`
time_h=$(echo "scale=3; $time / $time_freq" | bc)
echo "Time : $time"
echo "Time : $time_h s"

rmmod hvisor.ko