#!/bin/bash
cd /home/yjh/code_helper
git fetch origin master:temp
git merge temp
git branch -d temp
