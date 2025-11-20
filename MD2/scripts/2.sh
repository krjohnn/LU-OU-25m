#!/bin/bash

A=$(cat a)
B=$(cat b)
result=$((A * B))

echo "$result" > c
