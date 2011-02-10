#!/usr/bin/env zsh

make clean
make test

if [[  -f test.run  ]]; then
  print "Running tests!"
  ./test.run
   if [[ $? == "0" ]]; then
    print "\033[22;32m All passed, we have a win!"
  else
    print "\033[22;31m We have $res failuers :( fix them!"
  fi
else
 print "\033[22;31m Could not build tests! check wtf!"
fi

