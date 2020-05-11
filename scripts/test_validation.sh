#!/usr/bin/env sh
# Assumes it is running in the build folder.

cat "../validation/valid.task" | ./asset_conv 2>/dev/null $1
if md5sum -c ../build/output/*  ../validation/valid.md5; then
    echo "OK"
    return 0
else
    return 1
fi
