# Intro
Mumble-Connect is a simple utility for filling mumble rooms with users.

# Dependencies
Mumble-Connect has a minimal set of dependencies mostly contained in any essential build environment:
- C Compiler
- Make
- Automake
- Autoconf

# Building
Building mumble-connect is similar to any other autotools managed project.

```bash
git clone git://github.com/wkennington/mumble-connect
cd mumble-connect

autoreconf -vfi
./configure --prefix="<INSTALL DIR>"
make
make install
```

# Running
To print the help text:
```bash
mumble-connect -h
```
