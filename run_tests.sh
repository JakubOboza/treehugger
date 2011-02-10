#!/usr/bin/env zsh

make clean
make test

if [[  -f test.run  ]]; then
  print "Running tests!"
  ./test.run
   if [[ $? == "0" ]]; then
    print "All passed, we have a win!"
  else
    print "We have $res failuers :( fix them!"
  fi
else
 print "Could not build tests! check wtf!"
fi

