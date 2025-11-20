#!/bin/bash

target=$(awk 'BEGIN {srand(); print int(rand()*100) + 1}')
max_tries=10
i=1

echo "Guess a number between 1 and 100. You have 10 chances to guess!"
while [ "$i" -le "$max_tries" ]; do
    read guess
    if [ "$guess" -eq "$target" ]; then
        echo "You guessed the number correctly!"
        exit 0
    fi

    if [ "$guess" -lt "$target" ]; then
        echo "Your guess is too SMALL."
    else
        echo "Your guess is too LARGE."
    fi
    tries_left=$((max_tries - i))
    if [ "$tries_left" -gt 0 ]; then
        echo "Tries left: $tries_left"
    fi

    i=$((i + 1))
done

echo "Game Over. You did not guess correctly!"
echo "The number was: $target"
