#!/bin/bash

echo $$ > /sys/fs/cgroup/lb/cgroup.procs
dd if=/dev/zero of=/bigfile bs=1M count=200 oflag=direct

