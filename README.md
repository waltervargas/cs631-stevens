# cs631-stevens
Advanced Unix Programming in the UNIX Environment  - stevens.edu

## Prerequisites
 - meson: `sudo apt install meson`
 - check: `sudo apt install check`

## How do I run this

Code base is build with `meson`, exercises are written in form of tests using
the test framework `check.h`, so after installing meson and check the next step is to setup a build folder and run the tests:

``` sh
meson setup build
meson test -C build -v
```

# Acknowledgments

Thank you profesor Jan Schaumann for releasing this course online.

# References

- [CS631 - APUE](https://stevens.netmeister.org/631/)
