#!/bin/bash

echo Now running the second set of vm installations
chmod 600 .passwd-s3fs 
s3fs findingbuddhismbucket gutenberg_text

echo Remember to change the Makefile in Finding from cc = clang to cc = gcc