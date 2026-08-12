# Competitive Programming

Competitive programming library and selected solutions in C++.

## Achievements

* **ICPC Seoul Regional 2025** — 9th / 84 teams, Bronze Medal
* **UCPC 2025** — 10th, 4th Prize
* **UCPC 2026** — 12th, 5th Prize

## Profiles

* [Codeforces — jay153](https://codeforces.com/profile/jay153)
* [AtCoder — jay153](https://atcoder.jp/users/jay153)
* [solved.ac — jay153](https://solved.ac/profile/jay153)

## Library

### Data Structures

* Disjoint Set Union (DSU)
* Fenwick Tree
* Segment Tree

### Graph

* Lowest Common Ancestor (LCA)

### Mathematics

* Sieve of Eratosthenes
* Modular Integer
* Fast Fourier Transform (FFT)
* Number Theoretic Transform (NTT)

## Selected Solutions

A small collection of problems I found particularly interesting during contest practice.

| Problem                                                      | Contest   | Key Ideas                                                                |
| ------------------------------------------------------------ | --------- | ------------------------------------------------------------------------ |
| [Kitchen Knobs](https://codeforces.com/gym/101620/problem/K) | CERC 2017 | State compression, modular modeling, greedy pairing, dynamic programming |

The selected solutions preserve the main structure of my original contest-practice code, with only light cleanup for readability.

## Testing

Library implementations are accompanied by simple assertion-based tests.

For example:

```bash
g++ -std=c++20 tests/ntt_test.cpp -o ntt_test
./ntt_test
```

## Language

* C++20 / C++23
