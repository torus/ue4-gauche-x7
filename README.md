# Unreal Engine 4 Blue Print Nodes to work with the Gauche Scheme Interpreter

## Build

Build Gauche static library, first:
```
cd Source/Gauche
./DIST gen
./configure
make
cd src
make static
```

Then,
```
make x7
```

## Example

This example calculates `(+ 123 456)` and then write the result to a file.
![Blue Print](http://66.media.tumblr.com/34e591df9899cdf99ad86ece8fb58d44/tumblr_nw3sdiQXi01qz7s26o1_1280.png)

[Tumblr Post](http://torus.tumblr.com/post/131012358938/)
