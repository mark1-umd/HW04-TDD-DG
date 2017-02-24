# HW4 Test Drive Development
##Class Design and Unit Tests: DGellman; Implementation MJenkins
[![Build Status](https://travis-ci.org/mark1-umd/HW04-TDD-DG.svg?branch=MRJcodePIDController)](https://travis-ci.org/mark1-umd/HW04-TDD-DG)
[![Coverage Status](https://coveralls.io/repos/github/mark1-umd/HW04-TDD-DG/badge.svg?branch=MRJcodePIDController)](https://coveralls.io/github/mark1-umd/HW04-TDD-DG?branch=MRJcodePIDController)
---

## Overview

ENPM 808X Homework Week 4 - Test-Driven Development (TDD) Exercise

- C++ class PIDController
- GitHub version control
- googletest unit tests
- cppcheck static code analysis
- cpplint code style analysis (Google Style Guide for C++)
- Doxygen comments

## Current Status

- PIDController implementation complete according to original design
- Initial unit tests passing
- Travis build successful
- Coveralls code coverage integration incomplete; analysis hooks not present

## Review of current state and possible future work

- Discussion on 2017-02-23 regarding implementation and unit test results yielded:
-- Unit tests could be improved by using eq comparisons instead of just le, lt, ge, gt
-- Potential for Travis/Coveralls badge confusion exists when project merged back to designer's repo from implementor's repo


