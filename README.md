# Force-Directed Graph Layout (Fruchterman–Reingold)

> A small pet project implementing the **Force-Directed Placement** algorithm (Fruchterman–Reingold) for laying out undirected graphs from an adjacency matrix.

<p align="center">
  <img src="./images/1668882727.png" alt="Sample layout" width="520">
</p>

---

## Features

- Fruchterman–Reingold force-directed layout
- Input: **symmetric** `n × n` adjacency matrix with 0/1 values
- Ready-to-run samples in `samples/`
- Simple Linux build via CMake

> Input constraint: `n < 1000`

---

## Build (Linux)

Requirements: `cmake`, `gcc`/`clang`.

```bash
# In the project root (GraphViz)
mkdir build
cd build
cmake ..
make
````

The executable will be `./main` inside `build/`.

---

## Run

Pass the input file via stdin:

```bash
./main < input.txt
```

See `samples/` for ready-made inputs.

---

## Input Format

First line: single integer `n` (`n < 1000`).

Next `n` lines: `n` integers (`0` or `1`) separated by spaces, forming a **symmetric** `n × n` adjacency matrix.

Example:

```
5
1 1 0 1 0
1 1 1 0 1
0 1 1 1 1
1 0 1 0 0
0 1 1 0 1
```

---

## Examples

Sample inputs live in `samples/`, example renders in `images/`.

* **Cycle (`input1.txt`)** <img src="./images/1668882727.png" width="420" alt="Cycle">

* **Identity 30×30 (`input2.txt`)** <img src="./images/1668882645.png" width="420" alt="Identity 30x30">

* **Random 20×20 (`input3.txt`)** <img src="./images/1668883356.png" width="420" alt="Random 20x20">

* **Random 25×25 (`input4.txt`)** <img src="./images/1668884276.png" width="420" alt="Random 25x25">

* **Tree (`input5.txt`)** <img src="./images/1668900650.png" width="420" alt="Tree">

---

## How it works (brief)

The Fruchterman–Reingold method models graph nodes as particles:

* **Repulsion** between all node pairs
* **Attraction** along edges

Each iteration computes forces and updates positions, with a gradually decreasing step/“temperature” (cooling) until convergence or an iteration cap. Typical tunables:

* number of iterations
* initial temperature & cooling schedule
* area/scale constant `k` (depends on drawing area and `n`)

For the original description, see the paper below.

---

## Roadmap

* [ ] CLI parameters (iterations, temperature, RNG seed)
* [ ] Weighted / directed graphs
* [ ] Export to SVG/JSON
* [ ] Node labels and edge styling
* [ ] Benchmarks & profiling

---

## Reference

* Fruchterman, T. M. J., & Reingold, E. M. (1991). *Graph Drawing by Force-Directed Placement*. **Software: Practice and Experience**.
  PDF: [https://dcc.fceia.unr.edu.ar/sites/default/files/uploads/materias/fruchterman.pdf](https://dcc.fceia.unr.edu.ar/sites/default/files/uploads/materias/fruchterman.pdf)

---

## Acknowledgments

Built for fun and learning. Thanks to the FR authors and the graph-drawing community for decades of inspiration.
