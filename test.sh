#!/bin/bash
PROG=${1:-"../../src/prog_02200166_621"}
echo "$PROG"
make || exit 1
  cd testdata_EDF
    cd YES
      echo "=== YES ==="
      for filename in ./*; do
        "$PROG" "$filename"
      done
      echo "==========="
      echo ""
    cd ..
    cd NO
      echo "=== NO  ==="
      for filename in ./*; do
        "$PROG" "$filename"
      done
      echo "==========="
    cd ..
  cd ..
make clean
