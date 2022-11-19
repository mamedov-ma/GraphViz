## Reference

-   https://dcc.fceia.unr.edu.ar/sites/default/files/uploads/materias/fruchterman.pdf


## To build on linux:

Run in GraphViz folder:
```
mkdir build
cd build
cmake ..
make
./main < input.txt
```

### Input Format

The first line should contain one integer $n$, where $n$ should less than 1000.

In $n$ next lines, each line should contain $n$ integers, where each integer can be 1 or 0.

```
5
1 1 0 1 0
1 1 0 0 1
0 1 1 1 1
0 0 0 0 0
1 0 0 1 1
```
## Some examples 

**Identity matrix of size 30x30:**

![Minimal example](./images/1668882645.png)


