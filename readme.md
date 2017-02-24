# HW4 Test Drive Development
##Class Design and Unit Tests: DGellman; Implementation MJenkins
[![Build Status](https://travis-ci.org/dgellman/cpp-boilerplate.svg?branch=master)](https://travis-ci.org/dgellman/cpp-boilerplate)
[![Coverage Status](https://coveralls.io/repos/github/dgellman/cpp-boilerplate/badge.svg?branch=master)](https://coveralls.io/github/dgellman/cpp-boilerplate?branch=master)
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
    * Unit tests could be improved by using eq comparisons instead of just le, lt, ge, gt
    * Potential for Travis/Coveralls badge confusion exists when project merged back to designer's repo from implementor's repo


