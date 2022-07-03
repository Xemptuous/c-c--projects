#!/bin/bash
rm run.exe &> /dev/null;
g++ -o run.exe *.{cpp,h} `wx-config --cxxflags --libs`;
./run.exe;
